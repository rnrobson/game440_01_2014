#include "ClientLiaison.h"
#include "Serialize.h"
#include "ServerIncludes.h"
#include "Packet.h"
#include "ThreadedListener.h"
#include "PacketFactory.h"

bool ClientLiaison::running = false;
Networking::NetServer* ClientLiaison::master;
std::vector<Networking::NetClient*> ClientLiaison::connections = std::vector<Networking::NetClient*>();
BlockingQueue<Networking::Packet*> ClientLiaison::dataToWorker = BlockingQueue<Networking::Packet*>();

void ClientLiaison::InitLiaison() {
	running = true;
}

void ClientLiaison::Run() {
	InitLiaison();
	master = new Networking::NetServer(27015);
	Networking::ThreadedListener* listener = new Networking::ThreadedListener(master, 5);
}

int ClientLiaison::SendToClient(void*) {
	while (false) {

	}
	return 0;
}

void ClientLiaison::SendToWorker() {

}

void ClientLiaison::CloseLiaison() {
	std::cout << "Closing master connection: " << master->Close() << std::endl;

	for (auto iter = connections.begin(); iter != connections.end(); ++iter) {
		std::cout << "Closing connection: " << (*iter)->Close() << std::endl;
		delete *iter;
	}
}



