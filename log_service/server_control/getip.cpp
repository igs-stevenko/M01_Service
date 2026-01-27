#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include "getip.h"

#define DNS_PORT 53
#define DNS_SERVER "8.8.8.8"

void build_dns_query(unsigned char *buf, const char *domain, int *query_len) {
    // DNS Header
    buf[0] = 0x12; buf[1] = 0x34; // Transaction ID
    buf[2] = 0x01; buf[3] = 0x00; // Flags (standard query)
    buf[4] = 0x00; buf[5] = 0x01; // Questions
    buf[6] = 0x00; buf[7] = 0x00; // Answer RRs
    buf[8] = 0x00; buf[9] = 0x00; // Authority RRs
    buf[10] = 0x00; buf[11] = 0x00; // Additional RRs

    // Query section
    const char *p = domain;
    int pos = 12;
    while (*p) {
        const char *dot = strchr(p, '.');
        if (!dot) dot = p + strlen(p);
        int len = dot - p;
        buf[pos++] = len;
        memcpy(&buf[pos], p, len);
        pos += len;
        if (*dot) p = dot + 1;
        else break;
    }
    buf[pos++] = 0x00;           // End of host name
    buf[pos++] = 0x00; buf[pos++] = 0x01; // Type A
    buf[pos++] = 0x00; buf[pos++] = 0x01; // Class IN

    *query_len = pos;
}

int getip(char *domain, char *ip) {
    unsigned char buf[512];
    int query_len;

	if(strlen(domain) <= 0)
	  return NULL_DOMAIN;
	

    build_dns_query(buf, domain, &query_len);

    // Create socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return SOCKET_FAILED;
    }

	struct timeval tv;
	tv.tv_sec = 5;
	tv.tv_usec = 0;
	if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0){
        perror("setsockopt(SO_RCVTIMEO)");
        close(sock);
        return SET_TIMEOUT_FAILED;
	}

	if (setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, "eth1", strlen("eth1")) < 0) {
        perror("setsockopt(SO_BINDTODEVICE)");
        close(sock);
        return SET_BINDTODEVICE_FAILED;
    }


    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(DNS_PORT);
    inet_pton(AF_INET, DNS_SERVER, &dest.sin_addr);

    // Send query
    if (sendto(sock, buf, query_len, 0, (struct sockaddr *)&dest, sizeof(dest)) < 0) {
        perror("sendto failed");
        close(sock);
        return SEND_FAILED;
    }

    // Receive response
    socklen_t len = sizeof(dest);
    int recv_len = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&dest, &len);
    if (recv_len < 0) {
        perror("recvfrom failed");
        close(sock);
        return RECV_FAILED;
    }

#if 1
	int answer_count = buf[6] << 8 | buf[7];
	printf("Answer count: %d\n", answer_count);


	int pos = 12;
	while (buf[pos] != 0) pos += buf[pos] + 1;
	pos += 5;  // Skip null byte + QTYPE + QCLASS

	for (int i = 0; i < answer_count; i++) {
		// Skip NAME (pointer or label)
		if ((buf[pos] & 0xC0) == 0xC0) {
			pos += 2;
		} else {
			while (buf[pos] != 0) pos += buf[pos] + 1;
			pos += 1;
		}

		uint16_t type = buf[pos] << 8 | buf[pos+1];
		uint16_t classd = buf[pos+2] << 8 | buf[pos+3];
		uint32_t ttl = (buf[pos+4]<<24) | (buf[pos+5]<<16) | (buf[pos+6]<<8) | buf[pos+7];
		uint16_t rdlength = buf[pos+8] << 8 | buf[pos+9];
		pos += 10;

		if (type == 1 && classd == 1 && rdlength == 4) {
			// A record found
			/*
			printf("IP Address: %d.%d.%d.%d (TTL: %u)\n",
						buf[pos], buf[pos+1], buf[pos+2], buf[pos+3], ttl);
			*/
			sprintf(ip, "%d.%d.%d.%d\n", buf[pos], buf[pos+1], buf[pos+2], buf[pos+3]);
			break;
		}

		pos += rdlength;
	}
#else

    int i;
	for (i = 0; i < recv_len - 4; i++) {
        if (buf[i] == 0xC0 && buf[i+1] == 0x0C && buf[i+2] == 0x00 && buf[i+3] == 0x01) {
            // Found A record
            if (i + 16 < recv_len && buf[i+10] == 0x00 && buf[i+11] == 0x04) {
				sprintf(ip, "%d.%d.%d.%d\n", buf[i+12], buf[i+13], buf[i+14], buf[i+15]);
            }
        }
    }
#endif

    close(sock);

    return 0;
}

