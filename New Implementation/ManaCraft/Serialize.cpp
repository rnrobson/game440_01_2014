#include "Serialize.h"

using namespace ManaCraft::Networking;

Serializer& Serializer::operator<<(const __int8 num) {
	AddSpace(sizeof(num));
	Serialize::Int8(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const unsigned __int8 num) {
	AddSpace(sizeof(num));
	Serialize::UInt8(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const __int16 num) {
	AddSpace(sizeof(num));
	Serialize::Int16(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const unsigned __int16 num) {
	AddSpace(sizeof(num));
	Serialize::UInt16(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const __int32 num) {
	AddSpace(sizeof(num));
	Serialize::Int32(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const unsigned __int32 num) {
	AddSpace(sizeof(num));
	Serialize::UInt32(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const __int64 num) {
	AddSpace(sizeof(num));
	Serialize::Int64(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const unsigned __int64 num) {
	AddSpace(sizeof(num));
	Serialize::UInt64(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const float num) {
	AddSpace(sizeof(num));
	Serialize::Float(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator<<(const double num) {
	AddSpace(sizeof(num));
	Serialize::Double(mBytes, mBytes.size() - sizeof(num), num);
	return *this;
}

Serializer& Serializer::operator>>(__int8& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::Int8(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(unsigned __int8& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::UInt8(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(__int16& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::Int16(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(unsigned __int16& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::UInt16(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(__int32& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::Int32(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(unsigned __int32& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::UInt32(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(__int64& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::Int64(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(unsigned __int64& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::UInt64(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(float& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::Float(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

Serializer& Serializer::operator>>(double& num) {
	assert(mBytes.size() >= sizeof(num));
	num = Deserialize::Double(mBytes, mBytes.size() - sizeof(num));
	RemoveSpace(sizeof(num));
	return *this;
}

void Serializer::AddSpace(const unsigned int num) {
	for (unsigned int i = 0; i < num; ++i) {
		mBytes.push_back(0);
	}
}

void Serializer::RemoveSpace(const unsigned int num) {
	for (unsigned int i = 0; i < num; ++i) {
		mBytes.pop_back();
	}
}

char* Serialize::Int8(char* data, const __int8 num) {
	__int8* pInt8 = (__int8*)data;
	*pInt8 = num;
	return data += sizeof(__int8);
}

void Serialize::Int8(std::vector<char>& buffer, const unsigned int index, const __int8 num) {
	assert(buffer.size() > index);
	__int8* pInt8 = new __int8();
	*pInt8 = num;
	char* data = (char*)pInt8;
	buffer[index] = data[0];
	delete pInt8;
}

char* Serialize::UInt8(char* data, const unsigned __int8 num) {
	unsigned __int8* pUInt8 = (unsigned __int8*)data;
	*pUInt8 = num;
	return data += sizeof(unsigned __int8);
}

void Serialize::UInt8(std::vector<char>& buffer, const unsigned int index, const unsigned __int8 num) {
	assert(buffer.size() > index);
	unsigned __int8* pUInt8 = new unsigned __int8();
	*pUInt8 = num;
	char* data = (char*)pUInt8;
	buffer[index] = data[0];
	delete pUInt8;
}

char* Serialize::Int16(char* data, const __int16 num) {
	__int16* pInt16 = (__int16*)data;
	*pInt16 = num;
	return data += sizeof(__int16);
}

void Serialize::Int16(std::vector<char>& buffer, const unsigned int index, const __int16 num) {
	assert(buffer.size() > (index + 1));
	__int16* pInt16 = new __int16();
	*pInt16 = num;
	char* data = (char*)pInt16;
	buffer[index] = data[0];
	buffer[index + 1] = data[1];
	delete pInt16;
}

char* Serialize::UInt16(char* data, const unsigned __int16 num) {
	unsigned __int16* pUInt16 = (unsigned __int16*)data;
	*pUInt16 = num;
	return data += sizeof(unsigned __int16);
}

void Serialize::UInt16(std::vector<char>& buffer, const unsigned int index, const unsigned __int16 num) {
	assert(buffer.size() > (index + 1));
	unsigned __int16* pUInt16 = new unsigned __int16();
	*pUInt16 = num;
	char* data = (char*)pUInt16;
	buffer[index] = data[0];
	buffer[index + 1] = data[1];
	delete pUInt16;
}

char* Serialize::Int32(char* data, const __int32 num) {
	__int32* pInt32 = (__int32*)data;
	*pInt32 = num;
	return data += sizeof(__int32);
}

void Serialize::Int32(std::vector<char>& buffer, const unsigned int index, const __int32 num) {
	assert(buffer.size() > (index + 3));
	__int32* pInt32 = new __int32();
	*pInt32 = num;
	char* data = (char*)pInt32;
	buffer[index] = data[0];
	buffer[index + 1] = data[1];
	buffer[index + 2] = data[2];
	buffer[index + 3] = data[3];
	delete pInt32;
}

char* Serialize::UInt32(char* data, const unsigned __int32 num) {
	unsigned __int32* pUInt32 = (unsigned __int32*)data;
	*pUInt32 = num;
	return data += sizeof(unsigned __int32);
}

void Serialize::UInt32(std::vector<char>& buffer, const unsigned int index, const unsigned __int32 num) {
	assert(buffer.size() > (index + 3));
	unsigned __int32* pUInt32 = new unsigned __int32();
	*pUInt32 = num;
	char* data = (char*)pUInt32;
	buffer[index] = data[0];
	buffer[index + 1] = data[1];
	buffer[index + 2] = data[2];
	buffer[index + 3] = data[3];
	delete pUInt32;
}

char* Serialize::Int64(char* data, const __int64 num) {
	__int64* pInt64 = (__int64*)data;
	*pInt64 = num;
	return data += sizeof(__int64);
}

void Serialize::Int64(std::vector<char>& buffer, const unsigned int index, const __int64 num) {
	assert(buffer.size() > (index + 7));
	__int64* pInt64 = new __int64();
	*pInt64 = num;
	char* data = (char*)pInt64;
	buffer[index] = data[0];
	buffer[index + 1] = data[1];
	buffer[index + 2] = data[2];
	buffer[index + 3] = data[3];
	
	buffer[index + 4] = data[4];
	buffer[index + 5] = data[5];
	buffer[index + 6] = data[6];
	buffer[index + 7] = data[7];
	delete pInt64;
}

char* Serialize::UInt64(char* data, const unsigned __int64 num) {
	unsigned __int64* pUInt64 = (unsigned __int64*)data;
	*pUInt64 = num;
	return data += sizeof(unsigned __int64);
}

void Serialize::UInt64(std::vector<char>& buffer, const unsigned int index, const unsigned __int64 num) {
	assert(buffer.size() > (index + 7));
	unsigned __int64* pUInt64 = new unsigned __int64();
	*pUInt64 = num;
	char* data = (char*)pUInt64;
	buffer[index] = data[0];
	buffer[index + 1] = data[1];
	buffer[index + 2] = data[2];
	buffer[index + 3] = data[3];

	buffer[index + 4] = data[4];
	buffer[index + 5] = data[5];
	buffer[index + 6] = data[6];
	buffer[index + 7] = data[7];
	delete pUInt64;
}

char* Serialize::Float(char* data, const float num) {
	Serialize::Int32(data, *(__int32*)&num);
	return data += sizeof(float);
}

void Serialize::Float(std::vector<char>& buffer, const unsigned int index, const float num) {
	assert(buffer.size() > (index + 3));
	float* pFloat = new float();
	*pFloat = num;
	char* data = (char*)pFloat;
	buffer[index] = data[0];
	buffer[index + 1] = data[1];
	buffer[index + 2] = data[2];
	buffer[index + 3] = data[3];
	delete pFloat;
}

char* Serialize::Double(char* data, const double num) {
	Serialize::Int64(data, *(__int64*)&num);
	return data += sizeof(double);
}

void Serialize::Double(std::vector<char>& buffer, const unsigned int index, const double num) {
	assert(buffer.size() > (index + 7));
	double* pDouble = new double();
	*pDouble = num;
	char* data = (char*)pDouble;
	buffer[index] = data[0];
	buffer[index + 1] = data[1];
	buffer[index + 2] = data[2];
	buffer[index + 3] = data[3];

	buffer[index + 4] = data[4];
	buffer[index + 5] = data[5];
	buffer[index + 6] = data[6];
	buffer[index + 7] = data[7];
	delete pDouble;
}

__int8 Deserialize::Int8(char* data) {
	__int8 tempInt8 = *(__int8*)data;
	return tempInt8;
}

__int8 Deserialize::Int8(std::vector<char>& buffer, const unsigned int index) {
	return *(__int8*)&buffer[index];
}

unsigned __int8 Deserialize::UInt8(char* data) {
	unsigned __int8 tempUInt8 = *(unsigned __int8*)data;
	return tempUInt8;
}

unsigned __int8 Deserialize::UInt8(std::vector<char>& buffer, const unsigned int index) {
	return *(unsigned __int8*)&buffer[index];
}

__int16 Deserialize::Int16(char* data) {
	__int16 tempInt16 = *(__int16*)data;
	return tempInt16;
}

__int16 Deserialize::Int16(std::vector<char>& buffer, const unsigned int index) {
	return *(__int16*)&buffer[index];
}

unsigned __int16 Deserialize::UInt16(char* data) {
	unsigned __int16 tempUInt16 = *(unsigned __int16*)data;
	return tempUInt16;
}

unsigned __int16 Deserialize::UInt16(std::vector<char>& buffer, const unsigned int index) {
	return *(unsigned __int16*)&buffer[index];
}

__int32 Deserialize::Int32(char* data) {
	__int32 tempInt32 = *(__int32*)data;
	return tempInt32;
}

__int32 Deserialize::Int32(std::vector<char>& buffer, const unsigned int index) {
	return *(__int32*)&buffer[index];
}

unsigned __int32 Deserialize::UInt32(char* data) {
	unsigned __int32 tempUInt32 = *(unsigned __int32*)data;
	return tempUInt32;
}

unsigned __int32 Deserialize::UInt32(std::vector<char>& buffer, const unsigned int index) {
	return *(unsigned __int32*)&buffer[index];
}

__int64 Deserialize::Int64(char* data) {
	__int64 tempInt64 = *(__int64*)data;
	return tempInt64;
}

__int64 Deserialize::Int64(std::vector<char>& buffer, const unsigned int index) {
	return *(__int64*)&buffer[index];
}

unsigned __int64 Deserialize::UInt64(char* data) {
	unsigned __int64 tempUInt64 = *(unsigned __int64*)data;
	return tempUInt64;
}

unsigned __int64 Deserialize::UInt64(std::vector<char>& buffer, const unsigned int index) {
	return *(unsigned __int64*)&buffer[index];
}

float Deserialize::Float(char* data) {
	__int32 tempInt32 = Deserialize::Int32(data);
	return *(float*)&tempInt32;
}

float Deserialize::Float(std::vector<char>& buffer, const unsigned int index) {
	return *(float*)&buffer[index];
}

double Deserialize::Double(char* data) {
	__int64 tempInt64 = Deserialize::Int64(data);
	return *(double*)&tempInt64;
}

double Deserialize::Double(std::vector<char>& buffer, const unsigned int index) {
	return *(double*)&buffer[index];
}
