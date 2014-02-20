#ifndef SERIALIZE_H
#define SERIALIZE_H

typedef char byte;

namespace ManaCraft {
	namespace Networking {
		/// <summary> Converts a 8 bit integer into 1 byte.
		/// <para>[byte* data] Data should point to 1 pre-allocated byte.</para>
		/// <para>[__int8 num] Num represents a 8 bit integer.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int8) for convenience.</returns>
		/// </summary>
		byte* SerializeInt8(byte* data, __int8 num);

		/// <summary> Converts a 8 bit unsigned integer into 1 byte.
		/// <para>[byte* data] Data should point to 1 pre-allocated byte.</para>
		/// <para>[unsigned __int8 num] Num represents a 8 bit unsigned integer.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int8) for convenience.</returns>
		/// </summary>
		byte* SerializeUInt8(byte* data, unsigned __int8 num);

		/// <summary> Converts a 16 bit integer into 2 chars.
		/// <para>[byte* data] Data should point to 2 pre-allocated bytes.</para>
		/// <para>[__int16 num] Num represents a 16 bit integer.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int16) for convenience.</returns>
		/// </summary>
		byte* SerializeInt16(byte* data, __int16 num);

		/// <summary> Converts a 16 bit unsigned integer into 2 chars.
		/// <para>[byte* data] Data should point to 2 pre-allocated bytes.</para>
		/// <para>[unsigned __int16 num] Num represents a 16 bit unsigned integer.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int16) for convenience.</returns>
		/// </summary>
		byte* SerializeUInt16(byte* data, unsigned __int16 num);

		/// <summary> Converts a 32 bit integer into 4 chars.
		/// <para>[byte* data] Data should point to 4 pre-allocated bytes.</para>
		/// <para>[__int32 num] Num represents a 32 bit integer.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int32) for convenience.</returns>
		/// </summary>
		byte* SerializeInt32(byte* data, __int32 num);

		/// <summary> Converts a 32 bit unsigned integer into 4 chars.
		/// <para>[byte* data] Data should point to 4 pre-allocated bytes.</para>
		/// <para>[unsigned __int32 num] Num represents a 32 bit unsigned integer.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int32) for convenience.</returns>
		/// </summary>
		byte* SerializeUInt32(byte* data, unsigned __int32 num);

		/// <summary> Converts a 64 bit integer into 8 chars.
		/// <para>[byte* data] Data should point to 8 pre-allocated bytes.</para>
		/// <para>[__int64 num] Num represents a 64 bit integer.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int64) for convenience.</returns>
		/// </summary>
		byte* SerializeInt64(byte* data, __int64 num);

		/// <summary> Converts a 64 bit unsigned integer into 8 chars.
		/// <para>[byte* data] Data should point to 8 pre-allocated bytes.</para>
		/// <para>[__int64 num] Num represents a 64 bit unsigned integer.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int64) for convenience.</returns>
		/// </summary>
		byte* SerializeUInt64(byte* data, unsigned __int64 num);

		/// <summary> Converts a 32 bit float into 4 chars.
		/// <para>[byte* data] Data should point to 4 pre-allocated bytes.</para>
		/// <para>[float num] Num represents a 32 bit floating point number.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(float) for convenience.</returns>
		/// </summary>
		byte* SerializeFloat(byte* data, float num);

		/// <summary>Converts a 64 bit double into 8 chars.
		/// <para>[byte* data] Data should point to 8 pre-allocated bytes.</para>
		/// <para>[double num] Num represents a 64 bit floating point number.</para>
		/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(double) for convenience.</returns>
		/// </summary>
		byte* SerializeDouble(byte* data, double num);

		/// <summary> Converts 1 byte into a 8 bit integer.
		/// <para>[byte* data] Data should point to a 8 bit integer that's currently stored as 1 char.</para>
		/// <returns>[Returns] the deserialized 8 bit integer.</returns>
		/// </summary>
		__int8 DeserializeInt8(byte* data);

		/// <summary> Converts 1 byte into a 8 bit unsigned integer.
		/// <para>[byte* data] Data should point to a 8 bit unsigned integer that's currently stored as 1 char.</para>
		/// <returns>[Returns] the deserialized 8 bit unsigned integer.</returns>
		/// </summary>
		unsigned __int8 DeserializeUInt8(byte* data);

		/// <summary> Converts 2 bytes into a 16 bit integer.
		/// <para>[byte* data] Data should point to a 16 bit integer that's currently stored as 2 chars.</para>
		/// <returns>[Returns] the deserialized 16 bit integer.</returns>
		/// </summary>
		__int16 DeserializeInt16(byte* data);

		/// <summary> Converts 2 bytes into a 16 bit unsigned integer.
		/// <para>[byte* data] Data should point to a 16 bit unsigned integer that's currently stored as 2 chars.</para>
		/// <returns>[Returns] the deserialized 16 bit unsigned integer.</returns>
		/// </summary>
		unsigned __int16 DeserializeUInt16(byte* data);

		/// <summary> Converts 4 bytes into a 32 bit integer.
		/// <para>[byte* data] Data should point to a 32 bit integer that's currently stored as 4 chars.</para>
		/// <returns>[Returns] the deserialized 32 bit integer.</returns>
		/// </summary>
		__int32 DeserializeInt32(byte* data);

		/// <summary> Converts 4 bytes into a 32 bit unsigned integer.
		/// <para>[byte* data] Data should point to a 32 bit unsigned integer that's currently stored as 4 chars.</para>
		/// <returns>[Returns] the deserialized 32 bit unsigned integer.</returns>
		/// </summary>
		unsigned __int32 DeserializeUInt32(byte* data);

		/// <summary> Converts 8 bytes into a 64 bit integer.
		/// <para>[byte* data] Data should point to a 64 bit integer that's currently stored as 8 chars.</para>
		/// <returns>[Returns] the deserialized 64 bit integer.</returns>
		/// </summary>
		__int64 DeserializeInt64(byte* data);

		/// <summary> Converts 8 bytes into a 64 bit unsigned integer.
		/// <para>[byte* data] Data should point to a 64 bit unsigned integer that's currently stored as 8 chars.</para>
		/// <returns>[Returns] the deserialized 64 bit unsigned integer.</returns>
		/// </summary>
		unsigned __int64 DeserializeUInt64(byte* data);

		/// <summary> Converts 4 bytes into a 32 bit float.
		/// <para>[byte* data] Data should point to a 32 bit float that's currently stored as 4 chars.</para>
		/// <returns>[Returns] the deserialized 32 bit float. </returns>
		/// </summary>
		float DeserializeFloat(byte* data);

		/// <summary> Converts 8 bytes into a 64 bit double.
		/// <para>[byte* data] Data should point to a 64 bit double that's currently stored as 8 chars.</para>
		/// <returns>[Returns] the deserialized 64 bit double. </returns>
		/// </summary>
		double DeserializeDouble(byte* data);
	}
}

#endif