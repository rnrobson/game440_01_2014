#include "Packet.h"
#include <string.h>
#include <iostream>
#include "Serialize.h"

using namespace ManaCraft::Networking;

Packet::Packet() : mSecurityHeader(0), mProtocolID(0), mDataLength(0) {
}

Packet::Packet(int securityHeader, short protocolID, std::vector<char>& data) :
mSecurityHeader(securityHeader), mProtocolID(protocolID) {
	SetData(data);
}

Packet::~Packet() {
}

void Packet::Initialize() {
	mPayload.clear();
	mPayload = std::vector<char>(GetPayloadSize());
	unsigned int pos = 0;
	Serialize::Int32(mPayload, pos, mSecurityHeader);
	pos += sizeof(__int32);
	Serialize::Int16(mPayload, pos, mDataLength);
	pos += sizeof(__int16);
	Serialize::Int16(mPayload, pos, mProtocolID);
	pos += sizeof(__int16);
	for (int i = pos; i < pos + mDataLength; ++i) {
		mPayload[i] = mData[i];
	}
	pos += mDataLength;
	Serialize::Int32(mPayload, pos, mSecurityHeader);
}

void Packet::SetProtocolID(short protocolID) {
	mProtocolID = protocolID;
	Initialize();
}

void Packet::SetData(std::vector<char>& newData) {
	mData = newData;
	mDataLength = mData.size();
	Initialize();
}

const int Packet::GetSecurityHeader() const {
	return mSecurityHeader;
}

short Packet::GetProtocolID() const {
	return mProtocolID;
}

std::vector<char> Packet::GetData() const {
	return mData;
}

short Packet::GetDataLength() const {
	return mDataLength;
}

int Packet::GetPayloadSize() const {
	return sizeof(int) * 2 + sizeof(__int16) * 2 + mDataLength;
}

std::vector<char> Packet::GetPayload() const {
	return mPayload;
}