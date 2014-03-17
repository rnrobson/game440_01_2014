#include "Packet.h"
#include <string.h>
#include <iostream>
#include "Serialize.h"

using namespace ManaCraft::Networking;

Packet::Packet() : mSecurityHeader(0), mProtocolID(0) {
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
	Serialize::Int16(mPayload, pos, GetDataLength());
	pos += sizeof(__int16);
	Serialize::Int16(mPayload, pos, mProtocolID);
	pos += sizeof(__int16);
	for (unsigned int i = 0; i < GetDataLength(); ++i) {
		mPayload[pos + i] = mData[i];
	}
	pos += GetDataLength();
	Serialize::Int32(mPayload, pos, mSecurityHeader);
}

void Packet::SetProtocolID(short protocolID) {
	mProtocolID = protocolID;
	Initialize();
}

void Packet::SetData(std::vector<char>& newData) {
	mData = newData;
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
	return mData.size();
}

int Packet::GetPayloadSize() const {
	return sizeof(mSecurityHeader) * 2 + sizeof(mProtocolID) * 2 + GetDataLength();
}

std::vector<char> Packet::GetPayload() const {
	return mPayload;
}