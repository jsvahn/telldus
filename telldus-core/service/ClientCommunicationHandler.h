#ifndef CLIENTCOMMUNICATIONHANDLER_H
#define CLIENTCOMMUNICATIONHANDLER_H

#include <string>
#include "Thread.h"
#include "Socket.h"
#include "Event.h"
#include "DeviceManager.h"
#include "ControllerManager.h"

class ClientCommunicationHandler : public TelldusCore::Thread
{
public:
	ClientCommunicationHandler();
	ClientCommunicationHandler(TelldusCore::Socket *clientSocket, Event *event, DeviceManager *deviceManager, ControllerManager *controllerManager);
	~ClientCommunicationHandler(void);

	bool isDone();

protected:
	void run();

private:
	class PrivateData;
	PrivateData *d;
	//std::wstring parseMessage(const std::wstring &clientMessage);
	void parseMessage(const std::wstring &clientMessage, int *intReturn, std::wstring *wstringReturn);
};

#endif //CLIENTCOMMUNICATIONHANDLER_H