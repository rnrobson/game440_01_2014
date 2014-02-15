#include "Packet.h"
#include <string.h>
#include "Serialize.h"

using namespace ManaCraft::Networking;

Packet::Packet() :
mSecurityHeader(nullptr), mProtocolID(0),
mData(nullptr), mDataLength(0),
mPayload(nullptr) {
}

Packet::Packet(byte* securityHeader, byte protocolID, byte* data) :
mSecurityHeader(securityHeader), mProtocolID(protocolID), mData(data),
mDataLength(strlen(data)), mPayload(nullptr) {
	NewPayload();
}

Packet::~Packet() {
	delete[] mPayload;
	mPayload = nullptr;
}

void Packet::SetProtocolID(byte newProtocolID) {
	mProtocolID = newProtocolID;
	NewPayload();
}

void Packet::SetData(byte* newData) {
	mData = newData;
	mDataLength = strlen(mData);
	NewPayload();
}

byte* Packet::GetSecurityHeader() const {
	return mSecurityHeader;
}

byte Packet::GetProtocolID() const {
	return mProtocolID;
}

byte* Packet::GetData() const {
	return mData;
}

int Packet::GetDataLength() const {
	return mDataLength;
}

int Packet::PayloadSize() const {
	return strlen(mSecurityHeader) + 2 + mDataLength + strlen(mSecurityHeader);
}

byte* Packet::GetPayload() const {
	return mPayload;
}

void Packet::NewPayload() {
	// Delete old payload
	if (mPayload != nullptr)
	{
		delete[] mPayload;
	}
	// Allocate an array of bytes from the payload size
	mPayload = new byte[PayloadSize()];
	// Set new pointer to the payload.
	byte* currPos = mPayload;
	// Copy the security header
	for (unsigned int i = 0; i < strlen(mSecurityHeader); ++i) {
		currPos[i] = mSecurityHeader[i];
	}
	// Advance pointer the size of the header array.
	currPos += strlen(mSecurityHeader);
	// Serialize the data length and copy it into the array.
	currPos = SerializeInt8(currPos, mDataLength);
	// Copy the protocol ID
	currPos = SerializeInt8(currPos, mProtocolID);
	// Copy the data
	for (int i = 0; i < mDataLength; ++i) {
		currPos[i] = mData[i];
	}
	// Advance pointer the length of the data.
	currPos += mDataLength;
	// Copy the security header
	for (unsigned int i = 0; i < strlen(mSecurityHeader); ++i) {
		currPos[i] = mSecurityHeader[i];
	}
}