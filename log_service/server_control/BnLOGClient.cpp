#include "BnLOGClient.h"

namespace android
{

	
	void BnLOGClient::setDomain(const char *src){
	}
	
	void BnLOGClient::setUrl(const char *src){
	}
	void BnLOGClient::setPost(const char *src){
	}
	const char* BnLOGClient::getIP(){
		return NULL;
	}
	const char* BnLOGClient::getData(){
		return NULL;
	}
	int BnLOGClient::getDataLen(){
		return 0;
	}
	
	int BnLOGClient::cmd_send(int mode) {
		return 0;
	}
	
	status_t BnLOGClient::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {

		int rtn = 0;
		int error_flag = 0;

		//CHECK_INTERFACE(ILOGService, data, reply);

		switch (code) {


			case GET_IP :
				{
					printf("---> GET_IP <---\n");

					String8 rtnData;
					String8 domain;

					memset(ip, 0, sizeof(ip));

					domain = data.readString8();
					rtn = getip((char *)(domain.string()), (char *)ip);

					rtnData.setTo((const char *)ip);
					reply->writeString8(rtnData);
					reply->writeInt32(rtn);

					break;
				}
			case POST_LOG :
				{	
					printf("---> POST_LOG <---\n");

					String8 rtnData;
					String8 jsonData;
					String8 url;

					memset(resData, 0, sizeof(resData));
					resDataLen = 0;

					

					url = data.readString8();
					jsonData = data.readString8();

					printf("url = %s\n", url.string());
					printf("jsonData = %s\n", jsonData.string());
	
					rtn = PostData((char *)(url.string()), (char *)(jsonData.string()),(char *)resData, &resDataLen);
					printf("### [%s][%d] : rtn = %d###\n", __func__, __LINE__, rtn); 

					printf("resData = %s", resData);
					printf("resDataLen = %d\n", resDataLen);

					rtnData.setTo((const char *)resData);
					reply->writeString8(rtnData);
					reply->writeInt32(resDataLen);
					reply->writeInt32(rtn);
					break;
				}
			default:

				error_flag = 1;

				break;
		}
		return rtn;
	}
};
