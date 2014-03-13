#include "Packet.h"
#include <string.h>
#include "Serialize.h"

using namespace ManaCraft::Networking;

Packet::Packet() :
mSecurityHeader(nullptr), mProtocolID(0),
mData(nullptr), mDataLength(0),
mPayload(nullptr) {
}

Packet::Packet(const Byte* securityHeader, short protocolID, Byte* data) :
mSecurityHeader(securityHeader), mProtocolID(protocolID), mData(data),
mDataLength(strlen(data)), mPayload(nullptr) {
	NewPayload();
}

Packet::Packet(short protocolID, Byte* data) :
mSecurityHeader(nullptr), mProtocolID(protocolID), mData(data),
mDataLength(strlen(data)), mPayload(nullptr) {
}

Packet::~Packet() {
	delete[] mPayload;
	mPayload = nullptr;
}

void Packet::SetProtocolID(short newProtocolID) {
	mProtocolID = newProtocolID;
	NewPayload();
}

void Packet::SetData(Byte* newData) {
	mData = newData;
	mDataLength = strlen(mData);
	NewPayload();
}

const Byte* Packet::GetSecurityHeader() const {
	return mSecurityHeader;
}

short Packet::GetProtocolID() const {
	return mProtocolID;
}

Byte* Packet::GetData() const {
	return mData;
}

short Packet::GetDataLength() const {
	return mDataLength;
}

int Packet::PayloadSize() const {
	return strlen(mSecurityHeader) + sizeof(short) * 2 + mDataLength + strlen(mSecurityHeader);
}

Byte* Packet::GetPayload() const {
	return mPayload;
}

void Packet::NewPayload() {
	if (mPayload != nullptr) {
		delete[] mPayload;
	}
	mPayload = new Byte[PayloadSize()];
	Byte* currPos = mPayload;
	for (unsigned int i = 0; i < strlen(mSecurityHeader); ++i) {
		currPos[i] = mSecurityHeader[i];
	}
	currPos += strlen(mSecurityHeader);
	currPos = Serialize::Int16(currPos, mDataLength);
	currPos = Serialize::Int16(currPos, mProtocolID);
	for (int i = 0; i < mDataLength; ++i) {
		currPos[i] = mData[i];
	}
	currPos += mDataLength;
	for (unsigned int i = 0; i < strlen(mSecurityHeader); ++i) {
		currPos[i] = mSecurityHeader[i];
	}
}