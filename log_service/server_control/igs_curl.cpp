#include <utils/String8.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "curl/include/curl.h"

#include <cstddef>
#include <stdlib.h>
#include <cstdlib>

#include <utils/String8.h>

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata);
int debug_callback(CURL *handle, curl_infotype type, char *data, size_t size, void *userptr);

class CurlCtrl {

	private :
		
		unsigned char data[1048576];
		int offset;
	
	public :

		CurlCtrl(){
			memset(data, 0, sizeof(data));
			offset = 0;
		}


		int CurlPost(const char *url, const char *jsonPayload){

			int rtn;
			curl_global_init(CURL_GLOBAL_ALL);
			CURL* curl = curl_easy_init();
			struct curl_slist *headers = NULL;

			if (curl) {
				curl_easy_setopt(curl, CURLOPT_URL, url);


				curl_easy_setopt(curl, CURLOPT_INTERFACE, "eth1");

				curl_easy_setopt(curl, CURLOPT_POST, 1L);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(jsonPayload));


				// Content-Type: application/json
				headers = curl_slist_append(headers, "Content-Type: application/json");
				curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
				curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

				curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);   // TCP 連線超時（秒）
				curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60L);         // 總操作時間上限（秒）

				curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
				curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, debug_callback);

				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

				rtn = curl_easy_perform(curl);  // 執行


				if (rtn != CURLE_OK){
					rtn = -2;
				}
				else{
					rtn = 0;
				}

				curl_easy_cleanup(curl);  // 清除 handle
			}
			else
			{
				rtn = -1;
			}

			return rtn;
		}



		void SetData(char *src, int len){
			
			memcpy(data+offset, src, len);
			offset += len;
		}

		int GetDataLen(void){
			return offset;
		}

		void GetData(char *target, int len){
			
			memcpy(target, data, len);
		}

		void CleanData(void){
			
			memset(data, 0, sizeof(data));
			offset = 0;
		}


		void PrintData(){
			printf("Print Data : \n");
			for(int i=0; i<offset; i++){
				printf("%c", data[i]);
			}
		}
};

CurlCtrl curlctrl;




size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t total = size * nmemb;
	curlctrl.SetData((char *)ptr, total);
    return total;

}


int debug_callback(CURL *handle, curl_infotype type, char *data, size_t size, void *userptr) {
    const char *text;
    switch (type) {
        case CURLINFO_TEXT:         text = "== Info:"; break;
        case CURLINFO_HEADER_IN:    text = "< Header:"; break;
        case CURLINFO_HEADER_OUT:   text = "> Header:"; break;
        case CURLINFO_DATA_IN:      text = "< Data:"; break;
        case CURLINFO_DATA_OUT:     text = "> Data:"; break;
        default:                    return 0;
    }
    
	//curlctrl.SetData(data, size);
	//setdata(data, size);

	return 0;
}

int PostData(char *url, char *postData, char *resData, int *resDataLen){

	int rtn = 0;

	rtn = curlctrl.CurlPost(url, postData);
	if(rtn != 0){
		curlctrl.CleanData();
		return 1;
	}

	*resDataLen = curlctrl.GetDataLen();
	if(*resDataLen <= 0){
		curlctrl.CleanData();
		return 2;
	}

	curlctrl.GetData(resData, *resDataLen);
	curlctrl.CleanData();

	return rtn;
}

