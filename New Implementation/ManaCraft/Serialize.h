#ifndef SERIALIZE_H
#define SERIALIZE_H

typedef char byte;

namespace ManaCraft {
	namespace Networking {
		class Serialize {
		public:
			/// <summary> Converts a 8 bit integer into 1 byte.
			/// <para>[byte* data] Data should point to 1 pre-allocated byte.</para>
			/// <para>[__int8 num] Num represents a 8 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int8) for convenience.</returns>
			/// </summary>
			static byte* Int8(byte* data, __int8 num);

			/// <summary> Converts a 8 bit unsigned integer into 1 byte.
			/// <para>[byte* data] Data should point to 1 pre-allocated byte.</para>
			/// <para>[unsigned __int8 num] Num represents a 8 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int8) for convenience.</returns>
			/// </summary>
			static byte* UInt8(byte* data, unsigned __int8 num);

			/// <summary> Converts a 16 bit integer into 2 chars.
			/// <para>[byte* data] Data should point to 2 pre-allocated bytes.</para>
			/// <para>[__int16 num] Num represents a 16 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int16) for convenience.</returns>
			/// </summary>
			static byte* Int16(byte* data, __int16 num);

			/// <summary> Converts a 16 bit unsigned integer into 2 chars.
			/// <para>[byte* data] Data should point to 2 pre-allocated bytes.</para>
			/// <para>[unsigned __int16 num] Num represents a 16 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int16) for convenience.</returns>
			/// </summary>
			static byte* UInt16(byte* data, unsigned __int16 num);

			/// <summary> Converts a 32 bit integer into 4 chars.
			/// <para>[byte* data] Data should point to 4 pre-allocated bytes.</para>
			/// <para>[__int32 num] Num represents a 32 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int32) for convenience.</returns>
			/// </summary>
			static byte* Int32(byte* data, __int32 num);

			/// <summary> Converts a 32 bit unsigned integer into 4 chars.
			/// <para>[byte* data] Data should point to 4 pre-allocated bytes.</para>
			/// <para>[unsigned __int32 num] Num represents a 32 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int32) for convenience.</returns>
			/// </summary>
			static byte* UInt32(byte* data, unsigned __int32 num);

			/// <summary> Converts a 64 bit integer into 8 chars.
			/// <para>[byte* data] Data should point to 8 pre-allocated bytes.</para>
			/// <para>[__int64 num] Num represents a 64 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int64) for convenience.</returns>
			/// </summary>
			static byte* Int64(byte* data, __int64 num);

			/// <summary> Converts a 64 bit unsigned integer into 8 chars.
			/// <para>[byte* data] Data should point to 8 pre-allocated bytes.</para>
			/// <para>[__int64 num] Num represents a 64 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int64) for convenience.</returns>
			/// </summary>
			static byte* UInt64(byte* data, unsigned __int64 num);

			/// <summary> Converts a 32 bit float into 4 chars.
			/// <para>[byte* data] Data should point to 4 pre-allocated bytes.</para>
			/// <para>[float num] Num represents a 32 bit floating point number.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(float) for convenience.</returns>
			/// </summary>
			static byte* Float(byte* data, float num);

			/// <summary>Converts a 64 bit double into 8 chars.
			/// <para>[byte* data] Data should point to 8 pre-allocated bytes.</para>
			/// <para>[double num] Num represents a 64 bit floating point number.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(double) for convenience.</returns>
			/// </summary>
			static byte* Double(byte* data, double num);

		private:
			Serialize();
			~Serialize();
		};

		class Deserialize {
		public:
			/// <summary> Converts 1 byte into a 8 bit integer.
			/// <para>[byte* data] Data should point to a 8 bit integer that's currently stored as 1 char.</para>
			/// <returns>[Returns] the deserialized 8 bit integer.</returns>
			/// </summary>
			static __int8 Int8(byte* data);

			/// <summary> Converts 1 byte into a 8 bit unsigned integer.
			/// <para>[byte* data] Data should point to a 8 bit unsigned integer that's currently stored as 1 char.</para>
			/// <returns>[Returns] the deserialized 8 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int8 UInt8(byte* data);

			/// <summary> Converts 2 bytes into a 16 bit integer.
			/// <para>[byte* data] Data should point to a 16 bit integer that's currently stored as 2 chars.</para>
			/// <returns>[Returns] the deserialized 16 bit integer.</returns>
			/// </summary>
			static __int16 Int16(byte* data);

			/// <summary> Converts 2 bytes into a 16 bit unsigned integer.
			/// <para>[byte* data] Data should point to a 16 bit unsigned integer that's currently stored as 2 chars.</para>
			/// <returns>[Returns] the deserialized 16 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int16 UInt16(byte* data);

			/// <summary> Converts 4 bytes into a 32 bit integer.
			/// <para>[byte* data] Data should point to a 32 bit integer that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit integer.</returns>
			/// </summary>
			static __int32 Int32(byte* data);

			/// <summary> Converts 4 bytes into a 32 bit unsigned integer.
			/// <para>[byte* data] Data should point to a 32 bit unsigned integer that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int32 UInt32(byte* data);

			/// <summary> Converts 8 bytes into a 64 bit integer.
			/// <para>[byte* data] Data should point to a 64 bit integer that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit integer.</returns>
			/// </summary>
			static __int64 Int64(byte* data);

			/// <summary> Converts 8 bytes into a 64 bit unsigned integer.
			/// <para>[byte* data] Data should point to a 64 bit unsigned integer that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int64 UInt64(byte* data);

			/// <summary> Converts 4 bytes into a 32 bit float.
			/// <para>[byte* data] Data should point to a 32 bit float that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit float. </returns>
			/// </summary>
			static float Float(byte* data);

			/// <summary> Converts 8 bytes into a 64 bit double.
			/// <para>[byte* data] Data should point to a 64 bit double that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit double. </returns>
			/// </summary>
			static double Double(byte* data);

		private:
			Deserialize();
			~Deserialize();
		};
	}
}

#endif