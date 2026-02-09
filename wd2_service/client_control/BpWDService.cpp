#include <utils/Log.h>
#include <fcntl.h>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>

#include "BpWDService.h"
#include "BpWDClient.h"

namespace android{

	sp<IWDService> IWDService::asInterface(const sp<IBinder>& obj) {
		sp<IWDService> intr;
		if (obj != NULL) {
			//sp<IInterface> i = obj->queryLocalInterface(IWDClient::getInterfaceDescriptor());
			sp<IInterface> i = obj->queryLocalInterface(IWDService::IWDService::descriptor);
			if (i != NULL) {
				intr = static_cast<IWDService*>(i.get());
			} else {
				intr = new BpWDService(obj);
			}
		}
		return intr;
	}

	BpWDService::BpWDService(const sp<IBinder>& impl)
		: BpInterface<IWDService>(impl) {}

	sp<IWDClient> BpWDService::getClient() {
		Parcel data, reply;
		data.writeInterfaceToken(IWDService::getInterfaceDescriptor());

		remote()->transact(GET_CLIENT_TRANSACTION, data, &reply);

		sp<IBinder> clientBinder = reply.readStrongBinder();
		return interface_cast<IWDClient>(clientBinder);
	}

}
