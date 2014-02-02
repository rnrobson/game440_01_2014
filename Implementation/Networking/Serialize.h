#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#ifdef NETWORKING_EXPORTS
#define NETWORKING_API __declspec(dllexport)
#else
#define NETWORKING_API __declspec(dllimport)
#endif

typedef char byte;

namespace ManaCraft {
	namespace Networking {
		/// <summary> Converts a 8 bit integer into 1 char.
		/// <para> byte* data: data should point to 1 pre-allocated byte. </para>
		/// <para> __int8 num: num represents a 8 bit integer. </para>
		/// </summary>
		extern NETWORKING_API void SerializeInt8(byte* data, __int8 num) {
			__int8* pInt8 = (__int8*)data;
			*pInt8 = num;
		}

		/// <summary> Converts a 16 bit integer into 2 chars.
		/// <para> byte* data: data should point to 2 pre-allocated bytes. </para>
		/// <para> __int16 num: num represents a 16 bit integer. </para>
		/// </summary>
		extern NETWORKING_API void SerializeInt16(byte* data, __int16 num) {
			__int16* pInt16 = (__int16*)data;
			*pInt16 = num;
		}

		/// <summary> Converts a 32 bit integer into 4 chars.
		/// <para> byte* data: data should point to 4 pre-allocated bytes. </para>
		/// <para> __int32 num: num represents a 32 bit integer. </para>
		/// </summary>
		extern NETWORKING_API void SerializeInt32(byte* data, __int32 num) {
			__int32* pInt32 = (__int32*)data;
			*pInt32 = num;
		}

		/// <summary> Converts a 64 bit integer into 8 chars.
		/// <para> byte* data: data should point to 8 pre-allocated bytes. </para>
		/// <para> __int16 num: num represents a 64 bit integer. </para>
		/// </summary>
		extern NETWORKING_API void SerializeInt64(byte* data, __int64 num) {
			__int64* pInt64 = (__int64*)data;
			*pInt64 = num;
		}

		/// <summary> Converts a 32 bit float into 4 chars.
		/// <para> byte* data: data should point to 4 pre-allocated bytes. </para>
		/// <para> float num: num represents a 32 bit floating point number. </para>
		/// </summary>
		extern NETWORKING_API void SerializeFloat(byte* data, float num) {
			return SerializeInt32(data, *(__int32*)&num);
		}

		/// <summary> Converts a 64 bit double into 8 chars.
		/// <para> byte* data: data should point to 8 pre-allocated bytes. </para>
		/// <para> double num: num represents a 64 bit floating point number. </para>
		/// </summary>
		extern NETWORKING_API void SerializeDouble(byte* data, double num) {
			return SerializeInt64(data, *(__int64*)&num);
		}

		/// <summary> Converts 1 byte into a 8 bit integer.
		/// <para> byte* data: data should point to a 8 bit integer that's currently stored as 1 char. </para>
		/// <return> Returns the deserialized 8 bit integer. </return>
		/// </summary>
		extern NETWORKING_API __int8 DeserializeInt8(byte* data) {
			__int8 tempInt8 = *(__int8*)data;
			return tempInt8;
		}

		/// <summary> Converts 2 bytes into a 16 bit integer.
		/// <para> byte* data: data should point to a 16 bit integer that's currently stored as 2 chars. </para>
		/// <return> Returns the deserialized 16 bit integer. </return>
		/// </summary>
		extern NETWORKING_API __int16 DeserializeInt16(byte* data) {
			__int16 tempInt16 = *(__int16*)data;
			return tempInt16;
		}

		/// <summary> Converts 4 bytes into a 32 bit integer.
		/// <para> byte* data: data should point to a 32 bit integer that's currently stored as 4 chars. </para>
		/// <return> Returns the deserialized 32 bit integer. </return>
		/// </summary>
		extern NETWORKING_API __int32 DeserializeInt32(byte* data) {
			__int32 tempInt32 = *(__int32*)data;
			return tempInt32;
		}

		/// <summary> Converts 8 bytes into a 64 bit integer.
		/// <para> byte* data: data should point to a 64 bit integer that's currently stored as 8 chars. </para>
		/// <return> Returns the deserialized 64 bit integer. </return>
		/// </summary>
		extern NETWORKING_API __int64 DeserializeInt64(byte* data) {
			__int64 tempInt64 = *(__int64*)data;
			return tempInt64;
		}

		/// <summary> Converts 4 bytes into a 32 bit float.
		/// <para> byte* data: data should point to a 32 bit float that's currently stored as 4 chars. </para>
		/// <return> Returns the deserialized 32 bit float. </return>
		/// </summary>
		extern NETWORKING_API float DeserializeFloat(byte* data) {
			__int32 tempInt32 = DeserializeInt32(data);
			return *(float*)&tempInt32;
		}

		/// <summary> Converts 8 bytes into a 64 bit double.
		/// <para> byte* data: data should point to a 64 bit double that's currently stored as 8 chars. </para>
		/// <return> Returns the deserialized 64 bit double. </return>
		/// </summary>
		extern NETWORKING_API double DeserializeDouble(byte* data) {
			__int64 tempInt64 = DeserializeInt64(data);
			return *(double*)&tempInt64;
		}
	}
}

#endif