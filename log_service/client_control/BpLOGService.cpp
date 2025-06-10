#include <utils/Log.h>
#include <fcntl.h>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>

#include "BpLOGService.h"
#include "BpLOGClient.h"

namespace android{

	sp<ILOGService> ILOGService::asInterface(const sp<IBinder>& obj) {
		sp<ILOGService> intr;
		if (obj != NULL) {
			//sp<IInterface> i = obj->queryLocalInterface(ILOGClient::getInterfaceDescriptor());
			sp<IInterface> i = obj->queryLocalInterface(ILOGService::ILOGService::descriptor);
			if (i != NULL) {
				intr = static_cast<ILOGService*>(i.get());
			} else {
				intr = new BpLOGService(obj);
			}
		}
		return intr;
	}

	BpLOGService::BpLOGService(const sp<IBinder>& impl)
		: BpInterface<ILOGService>(impl) {}

	sp<ILOGClient> BpLOGService::getClient() {
		Parcel data, reply;
		data.writeInterfaceToken(ILOGService::getInterfaceDescriptor());

		remote()->transact(GET_CLIENT_TRANSACTION, data, &reply);

		sp<IBinder> clientBinder = reply.readStrongBinder();
		return interface_cast<ILOGClient>(clientBinder);
	}

}
