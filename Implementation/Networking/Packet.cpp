#include "Packet.h"

using namespace ManaCraft::Networking;

Packet::Packet() : 
	mSecurityHeader(nullptr), mProtocolID(0), 
	mObjTypeID(0), mObjNumID(0),
	mData(nullptr), mDataLength(0) { 
}

Packet::Packet(byte* securityHeader, byte protocolID, byte objTypeID, byte objNumID, byte* data, int dataLength) :
	mSecurityHeader(securityHeader), mProtocolID(protocolID), 
	mObjTypeID(objTypeID), mObjNumID(objNumID), 
	mData(data), mDataLength(dataLength) {
}

Packet::~Packet() { 
}

void Packet::SetSecurityHeader(byte* newHeader) {
	mSecurityHeader = newHeader;
}
void Packet::SetProtocolID(byte newProtocolID) {
	mProtocolID = newProtocolID;
}
void Packet::SetObjTypeID(byte newObjTypeID) {
	mObjTypeID = newObjTypeID;
}
void Packet::SetObjNumID(byte newObjNumID) {
	mObjNumID = newObjNumID;
}
void Packet::SetData(byte* newData) {
	// TODO: Possibly set the packet data length here.
	mData = newData;
}

byte* Packet::GetSecurityHeader() const {
	return mSecurityHeader;
}
byte Packet::GetProtocolID() const {
	return mProtocolID;
}
byte Packet::GetObjTypeID() const {
	return mObjTypeID;
}
byte Packet::GetObjNumID() const {
	return mObjNumID;
}
byte* Packet::GetData() const {
	return mData;
}
int Packet::GetDataLength() const {
	return mDataLength;
}