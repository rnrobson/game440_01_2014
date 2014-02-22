#include "Serialize.h"

using namespace ManaCraft::Networking;

byte* Serialize::Int8(byte* data, __int8 num) {
	__int8* pInt8 = (__int8*)data;
	*pInt8 = num;
	return data += sizeof(__int8);
}

byte* Serialize::UInt8(byte* data, unsigned __int8 num) {
	unsigned __int8* pUInt8 = (unsigned __int8*)data;
	*pUInt8 = num;
	return data += sizeof(unsigned __int8);
}

byte* Serialize::Int16(byte* data, __int16 num) {
	__int16* pInt16 = (__int16*)data;
	*pInt16 = num;
	return data += sizeof(__int16);
}

byte* Serialize::UInt16(byte* data, unsigned __int16 num) {
	unsigned __int16* pUInt16 = (unsigned __int16*)data;
	*pUInt16 = num;
	return data += sizeof(unsigned __int16);
}

byte* Serialize::Int32(byte* data, __int32 num) {
	__int32* pInt32 = (__int32*)data;
	*pInt32 = num;
	return data += sizeof(__int32);
}

byte* Serialize::UInt32(byte* data, unsigned __int32 num) {
	unsigned __int32* pUInt32 = (unsigned __int32*)data;
	*pUInt32 = num;
	return data += sizeof(unsigned __int32);
}

byte* Serialize::Int64(byte* data, __int64 num) {
	__int64* pInt64 = (__int64*)data;
	*pInt64 = num;
	return data += sizeof(__int64);
}

byte* Serialize::UInt64(byte* data, unsigned __int64 num) {
	unsigned __int64* pUInt64 = (unsigned __int64*)data;
	*pUInt64 = num;
	return data += sizeof(unsigned __int64);
}

byte* Serialize::Float(byte* data, float num) {
	Serialize::Int32(data, *(__int32*)&num);
	return data += sizeof(float);
}

byte* Serialize::Double(byte* data, double num) {
	Serialize::Int64(data, *(__int64*)&num);
	return data += sizeof(double);
}

__int8 Deserialize::Int8(byte* data) {
	__int8 tempInt8 = *(__int8*)data;
	return tempInt8;
}

unsigned __int8 Deserialize::UInt8(byte* data) {
	unsigned __int8 tempUInt8 = *(unsigned __int8*)data;
	return tempUInt8;
}

__int16 Deserialize::Int16(byte* data) {
	__int16 tempInt16 = *(__int16*)data;
	return tempInt16;
}

unsigned __int16 Deserialize::UInt16(byte* data) {
	unsigned __int16 tempUInt16 = *(unsigned __int16*)data;
	return tempUInt16;
}

__int32 Deserialize::Int32(byte* data) {
	__int32 tempInt32 = *(__int32*)data;
	return tempInt32;
}

unsigned __int32 Deserialize::UInt32(byte* data) {
	unsigned __int32 tempUInt32 = *(unsigned __int32*)data;
	return tempUInt32;
}

__int64 Deserialize::Int64(byte* data) {
	__int64 tempInt64 = *(__int64*)data;
	return tempInt64;
}

unsigned __int64 Deserialize::UInt64(byte* data) {
	unsigned __int64 tempUInt64 = *(unsigned __int64*)data;
	return tempUInt64;
}

float Deserialize::Float(byte* data) {
	__int32 tempInt32 = Deserialize::Int32(data);
	return *(float*)&tempInt32;
}

double Deserialize::Double(byte* data) {
	__int64 tempInt64 = Deserialize::Int64(data);
	return *(double*)&tempInt64;
}