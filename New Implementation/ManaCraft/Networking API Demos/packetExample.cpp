#include <iostream>
#include <Packet.h>
#include <Protocol.h>

using namespace ManaCraft::Networking;

int main()
{
	// Security header
	byte* header = new byte[4];
	header = "HEAD";
	// Protocol ID
	CS_Protocol protocol = CS_Protocol::JOIN_GAME;
	// Data
	byte* data = "My_serialized_packet_data";
	// Create a new Packet
	Packet* packet = new Packet(header, protocol, data);

	std::cout << "Packet Protocol: " << std::endl;
	std::cout << packet->GetProtocolID() << std::endl;

	std::cout << "Packet Data Length: " << std::endl;
	std::cout << packet->GetDataLength() << std::endl;

	std::cout << "Packet Data: " << std::endl;
	std::cout << packet->GetData() << std::endl << std::endl;

	std::cout << "Packet Payload: " << std::endl;
	std::cout << packet->GetPayload() << std::endl << std::endl;

	std::cout << "Changed Packet Data: " << std::endl;
	byte* newData = "This data was changed by packet->SetData();";
	packet->SetData(newData);
	// Use GetPayload() to return serialized data ready for the networking stream.
	std::cout << packet->GetPayload();
	for (;;){}
}