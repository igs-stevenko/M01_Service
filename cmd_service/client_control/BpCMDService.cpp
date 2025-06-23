#include <utils/Log.h>
#include <fcntl.h>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>

#include "BpCMDService.h"
#include "BpCMDClient.h"

namespace android{

	sp<ICMDService> ICMDService::asInterface(const sp<IBinder>& obj) {
		sp<ICMDService> intr;
		if (obj != NULL) {
			//sp<IInterface> i = obj->queryLocalInterface(ICMDClient::getInterfaceDescriptor());
			sp<IInterface> i = obj->queryLocalInterface(ICMDService::ICMDService::descriptor);
			if (i != NULL) {
				intr = static_cast<ICMDService*>(i.get());
			} else {
				intr = new BpCMDService(obj);
			}
		}
		return intr;
	}

	BpCMDService::BpCMDService(const sp<IBinder>& impl)
		: BpInterface<ICMDService>(impl) {}

	sp<ICMDClient> BpCMDService::getClient() {
		Parcel data, reply;
		data.writeInterfaceToken(ICMDService::getInterfaceDescriptor());

		remote()->transact(GET_CLIENT_TRANSACTION, data, &reply);

		sp<IBinder> clientBinder = reply.readStrongBinder();
		return interface_cast<ICMDClient>(clientBinder);
	}

}
