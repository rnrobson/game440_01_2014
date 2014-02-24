#ifndef SERIALIZATION_H
#define SERIALIZATION_H

typedef char byte;

namespace ManaCraft {
	namespace Networking {
		/// <summary> Converts a 8 bit integer into 1 char.
		/// <para>byte* data: data should point to 1 pre-allocated byte.</para>
		/// <para>__int8 num: num represents a 8 bit integer.</para>
		/// </summary>
		void SerializeInt8(byte* data, __int8 num);

		void SerializeUInt8(byte* data, unsigned __int8 num);

		/// <summary> Converts a 16 bit integer into 2 chars.
		/// <para>byte* data: data should point to 2 pre-allocated bytes.</para>
		/// <para>__int16 num: num represents a 16 bit integer.</para>
		/// </summary>
		void SerializeInt16(byte* data, __int16 num);

		void SerializeUInt16(byte* data, unsigned __int16 num);

		/// <summary> Converts a 32 bit integer into 4 chars.
		/// <para>byte* data: data should point to 4 pre-allocated bytes.</para>
		/// <para>__int32 num: num represents a 32 bit integer.</para>
		/// </summary>
		void SerializeInt32(byte* data, __int32 num);

		void SerializeUInt32(byte* data, unsigned __int32 num);

		/// <summary> Converts a 64 bit integer into 8 chars.
		/// <para>byte* data: data should point to 8 pre-allocated bytes.</para>
		/// <para>__int16 num: num represents a 64 bit integer.</para>
		/// </summary>
		void SerializeInt64(byte* data, __int64 num);

		void SerializeUInt64(byte* data, unsigned __int64 num);

		/// <summary> Converts a 32 bit float into 4 chars.
		/// <para>byte* data: data should point to 4 pre-allocated bytes.</para>
		/// <para>float num: num represents a 32 bit floating point number.</para>
		/// </summary>
		void SerializeFloat(byte* data, float num);

		/// <summary> Converts a 64 bit double into 8 chars.
		/// <para>byte* data: data should point to 8 pre-allocated bytes.</para>
		/// <para>double num: num represents a 64 bit floating point number.</para>
		/// </summary>
		void SerializeDouble(byte* data, double num);

		/// <summary> Converts 1 byte into a 8 bit integer.
		/// <para>byte* data: data should point to a 8 bit integer that's currently stored as 1 char.</para>
		/// <return>Returns the deserialized 8 bit integer.</return>
		/// </summary>
		__int8 DeserializeInt8(byte* data);

		unsigned __int8 DeserializeUInt8(byte* data);

		/// <summary> Converts 2 bytes into a 16 bit integer.
		/// <para>byte* data: data should point to a 16 bit integer that's currently stored as 2 chars.</para>
		/// <return>Returns the deserialized 16 bit integer.</return>
		/// </summary>
		__int16 DeserializeInt16(byte* data);

		unsigned __int16 DeserializeUInt16(byte* data);

		/// <summary> Converts 4 bytes into a 32 bit integer.
		/// <para>byte* data: data should point to a 32 bit integer that's currently stored as 4 chars.</para>
		/// <return>Returns the deserialized 32 bit integer.</return>
		/// </summary>
		__int32 DeserializeInt32(byte* data);

		unsigned __int32 DeserializeUInt32(byte* data);

		/// <summary> Converts 8 bytes into a 64 bit integer.
		/// <para>byte* data: data should point to a 64 bit integer that's currently stored as 8 chars.</para>
		/// <return>Returns the deserialized 64 bit integer.</return>
		/// </summary>
		__int64 DeserializeInt64(byte* data);

		unsigned __int64 DeserializeUInt64(byte* data);

		/// <summary> Converts 4 bytes into a 32 bit float.
		/// <para>byte* data: data should point to a 32 bit float that's currently stored as 4 chars.</para>
		/// <return>Returns the deserialized 32 bit float.</return>
		/// </summary>
		float DeserializeFloat(byte* data);

		/// <summary> Converts 8 bytes into a 64 bit double.
		/// <para>byte* data: data should point to a 64 bit double that's currently stored as 8 chars.</para>
		/// <return>Returns the deserialized 64 bit double.</return>
		/// </summary>
		double DeserializeDouble(byte* data);
	}
}

#endif