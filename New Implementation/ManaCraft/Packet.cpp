#include "Packet.h"
#include <string.h>
#include "Serialize.h"

using namespace ManaCraft::Networking;

Packet::Packet() :
mSecurityHeader(nullptr), mProtocolID(0),
mData(nullptr), mDataLength(0),
mPayload(nullptr) {
}

Packet::Packet(const byte* securityHeader, short protocolID, byte* data) :
mSecurityHeader(securityHeader), mProtocolID(protocolID), mData(data),
mDataLength(strlen(data)), mPayload(nullptr) {
	NewPayload();
}

Packet::~Packet() {
	delete[] mPayload;
	mPayload = nullptr;
}

void Packet::SetProtocolID(short newProtocolID) {
	mProtocolID = newProtocolID;
	NewPayload();
}

void Packet::SetData(byte* newData) {
	mData = newData;
	mDataLength = strlen(mData);
	NewPayload();
}

const byte* Packet::GetSecurityHeader() const {
	return mSecurityHeader;
}

short Packet::GetProtocolID() const {
	return mProtocolID;
}

byte* Packet::GetData() const {
	return mData;
}

short Packet::GetDataLength() const {
	return mDataLength;
}

int Packet::PayloadSize() const {
	return strlen(mSecurityHeader) + 4 + mDataLength + strlen(mSecurityHeader);
}

byte* Packet::GetPayload() const {
	return mPayload;
}

void Packet::NewPayload() {
	if (mPayload != nullptr) {
		delete[] mPayload;
		mPayload = nullptr;
	}
	mPayload = new byte[PayloadSize()];
	byte* currPos = mPayload;
	for (unsigned int i = 0; i < strlen(mSecurityHeader); ++i) {
		currPos[i] = mSecurityHeader[i];
	}
	currPos += strlen(mSecurityHeader);
	currPos = SerializeInt16(currPos, mDataLength);
	currPos = SerializeInt16(currPos, mProtocolID);
	for (int i = 0; i < mDataLength; ++i) {
		currPos[i] = mData[i];
	}
	currPos += mDataLength;
	for (unsigned int i = 0; i < strlen(mSecurityHeader); ++i) {
		currPos[i] = mSecurityHeader[i];
	}
}