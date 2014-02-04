#include "Packet.h"

using namespace ManaCraft::Networking;

Packet::Packet() : mSecurityHeader(0), mProtocolID(0), mObjTypeID(0), mObjNumID(0), mData(0), mDataLength(0) { }

Packet::Packet(byte* securityHeader, byte protocolID, byte objTypeID, byte objNumID, byte* data, int dataLength) {
	// Initialize variables.
	SetSecurityHeader(securityHeader);
	SetProtocolID(protocolID);
	SetObjTypeID(objTypeID);
	SetObjNumID(objNumID);
	SetData(data);
	mDataLength = dataLength;
}

Packet::~Packet() { }

void Packet::SetSecurityHeader(byte* newHeader) {
	// Set the security header.
	mSecurityHeader = newHeader;
}
void Packet::SetProtocolID(byte newProtocolID) {
	// Set the packet protocol ID.
	mProtocolID = newProtocolID;
}
void Packet::SetObjTypeID(byte newObjTypeID) {
	// Set the packet object type ID.
	mObjTypeID = newObjTypeID;
}
void Packet::SetObjNumID(byte newObjNumID) {
	// Set the packet object number ID.
	mObjNumID = newObjNumID;
}
void Packet::SetData(byte* newData) {
	// Possibly set the packet data length here.
	// Set the packet data.
	mData = newData;
}

byte* Packet::GetSecurityHeader() const {
	// Return the security header.
	return mSecurityHeader;
}
byte Packet::GetProtocolID() const {
	// Return the packet protocol ID.
	return mProtocolID;
}
byte Packet::GetObjTypeID() const {
	// Return the packet object type ID.
	return mObjTypeID;
}
byte Packet::GetObjNumID() const {
	// Return the packet object number ID.
	return mObjNumID;
}
byte* Packet::GetData() const {
	// Return the packet data.
	return mData;
}
int Packet::GetDataLength() {
	// Return the packet data length.
	return mDataLength;
}