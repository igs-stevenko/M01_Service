#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define DNS_PORT 53
#define DNS_SERVER "8.8.8.8"

void build_dns_query(unsigned char *buf, const char *hostname, int *query_len) {
    // DNS Header
    buf[0] = 0x12; buf[1] = 0x34; // Transaction ID
    buf[2] = 0x01; buf[3] = 0x00; // Flags (standard query)
    buf[4] = 0x00; buf[5] = 0x01; // Questions
    buf[6] = 0x00; buf[7] = 0x00; // Answer RRs
    buf[8] = 0x00; buf[9] = 0x00; // Authority RRs
    buf[10] = 0x00; buf[11] = 0x00; // Additional RRs

    // Query section
    const char *p = hostname;
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

int getip(const char *hostname, char *ip) {
    unsigned char buf[512];
    int query_len;

    build_dns_query(buf, hostname, &query_len);

    // Create socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return -1;
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
        return -2;
    }

    // Receive response
    socklen_t len = sizeof(dest);
    int recv_len = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&dest, &len);
    if (recv_len < 0) {
        perror("recvfrom failed");
        close(sock);
        return -3;
    }

    // Parse and print IP addresses from answer section (simple)
    printf("Received %d bytes\n", recv_len);
    int i;
	for (i = 0; i < recv_len - 4; i++) {
        if (buf[i] == 0xC0 && buf[i+1] == 0x0C && buf[i+2] == 0x00 && buf[i+3] == 0x01) {
            // Found A record
            if (i + 16 < recv_len && buf[i+10] == 0x00 && buf[i+11] == 0x04) {
				sprintf(ip, "%d.%d.%d.%d\n", buf[i+12], buf[i+13], buf[i+14], buf[i+15]);
                //printf("IP Address: %d.%d.%d.%d\n", buf[i+12], buf[i+13], buf[i+14], buf[i+15]);
            }
        }
    }

    close(sock);

    return 0;
}

int main(void){

	int rtn = 0;

	unsigned char ip[1024] = {0x00};
	const char *domain = "log.awp-skill.com";
	
	rtn = getip(domain, ip);
	if(rtn < 0){
		printf("### [%s][%d] ###\n", __func__, __LINE__); 
		exit(1);
	}
	printf("ip = %s\n", ip);

	return 0;
}
