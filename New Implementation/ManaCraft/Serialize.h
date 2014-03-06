#ifndef SERIALIZE_H
#define SERIALIZE_H

typedef char Byte;

namespace ManaCraft {
	namespace Networking {
		class Serialize {
		public:
			/// <summary> Converts a 8 bit integer into 1 Byte.
			/// <para>[Byte* data] Data should point to 1 pre-allocated Byte.</para>
			/// <para>[__int8 num] Num represents a 8 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int8) for convenience.</returns>
			/// </summary>
			static Byte* Int8(Byte* data, __int8 num);

			/// <summary> Converts a 8 bit unsigned integer into 1 Byte.
			/// <para>[Byte* data] Data should point to 1 pre-allocated Byte.</para>
			/// <para>[unsigned __int8 num] Num represents a 8 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int8) for convenience.</returns>
			/// </summary>
			static Byte* UInt8(Byte* data, unsigned __int8 num);

			/// <summary> Converts a 16 bit integer into 2 chars.
			/// <para>[Byte* data] Data should point to 2 pre-allocated Bytes.</para>
			/// <para>[__int16 num] Num represents a 16 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int16) for convenience.</returns>
			/// </summary>
			static Byte* Int16(Byte* data, __int16 num);

			/// <summary> Converts a 16 bit unsigned integer into 2 chars.
			/// <para>[Byte* data] Data should point to 2 pre-allocated Bytes.</para>
			/// <para>[unsigned __int16 num] Num represents a 16 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int16) for convenience.</returns>
			/// </summary>
			static Byte* UInt16(Byte* data, unsigned __int16 num);

			/// <summary> Converts a 32 bit integer into 4 chars.
			/// <para>[Byte* data] Data should point to 4 pre-allocated Bytes.</para>
			/// <para>[__int32 num] Num represents a 32 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int32) for convenience.</returns>
			/// </summary>
			static Byte* Int32(Byte* data, __int32 num);

			/// <summary> Converts a 32 bit unsigned integer into 4 chars.
			/// <para>[Byte* data] Data should point to 4 pre-allocated Bytes.</para>
			/// <para>[unsigned __int32 num] Num represents a 32 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int32) for convenience.</returns>
			/// </summary>
			static Byte* UInt32(Byte* data, unsigned __int32 num);

			/// <summary> Converts a 64 bit integer into 8 chars.
			/// <para>[Byte* data] Data should point to 8 pre-allocated Bytes.</para>
			/// <para>[__int64 num] Num represents a 64 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int64) for convenience.</returns>
			/// </summary>
			static Byte* Int64(Byte* data, __int64 num);

			/// <summary> Converts a 64 bit unsigned integer into 8 chars.
			/// <para>[Byte* data] Data should point to 8 pre-allocated Bytes.</para>
			/// <para>[__int64 num] Num represents a 64 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int64) for convenience.</returns>
			/// </summary>
			static Byte* UInt64(Byte* data, unsigned __int64 num);

			/// <summary> Converts a 32 bit float into 4 chars.
			/// <para>[Byte* data] Data should point to 4 pre-allocated Bytes.</para>
			/// <para>[float num] Num represents a 32 bit floating point number.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(float) for convenience.</returns>
			/// </summary>
			static Byte* Float(Byte* data, float num);

			/// <summary>Converts a 64 bit double into 8 chars.
			/// <para>[Byte* data] Data should point to 8 pre-allocated Bytes.</para>
			/// <para>[double num] Num represents a 64 bit floating point number.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(double) for convenience.</returns>
			/// </summary>
			static Byte* Double(Byte* data, double num);

		private:
			Serialize();
			~Serialize();
		};

		class Deserialize {
		public:
			/// <summary> Converts 1 Byte into a 8 bit integer.
			/// <para>[Byte* data] Data should point to a 8 bit integer that's currently stored as 1 char.</para>
			/// <returns>[Returns] the deserialized 8 bit integer.</returns>
			/// </summary>
			static __int8 Int8(Byte* data);

			/// <summary> Converts 1 Byte into a 8 bit unsigned integer.
			/// <para>[Byte* data] Data should point to a 8 bit unsigned integer that's currently stored as 1 char.</para>
			/// <returns>[Returns] the deserialized 8 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int8 UInt8(Byte* data);

			/// <summary> Converts 2 Bytes into a 16 bit integer.
			/// <para>[Byte* data] Data should point to a 16 bit integer that's currently stored as 2 chars.</para>
			/// <returns>[Returns] the deserialized 16 bit integer.</returns>
			/// </summary>
			static __int16 Int16(Byte* data);

			/// <summary> Converts 2 Bytes into a 16 bit unsigned integer.
			/// <para>[Byte* data] Data should point to a 16 bit unsigned integer that's currently stored as 2 chars.</para>
			/// <returns>[Returns] the deserialized 16 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int16 UInt16(Byte* data);

			/// <summary> Converts 4 Bytes into a 32 bit integer.
			/// <para>[Byte* data] Data should point to a 32 bit integer that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit integer.</returns>
			/// </summary>
			static __int32 Int32(Byte* data);

			/// <summary> Converts 4 Bytes into a 32 bit unsigned integer.
			/// <para>[Byte* data] Data should point to a 32 bit unsigned integer that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int32 UInt32(Byte* data);

			/// <summary> Converts 8 Bytes into a 64 bit integer.
			/// <para>[Byte* data] Data should point to a 64 bit integer that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit integer.</returns>
			/// </summary>
			static __int64 Int64(Byte* data);

			/// <summary> Converts 8 Bytes into a 64 bit unsigned integer.
			/// <para>[Byte* data] Data should point to a 64 bit unsigned integer that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int64 UInt64(Byte* data);

			/// <summary> Converts 4 Bytes into a 32 bit float.
			/// <para>[Byte* data] Data should point to a 32 bit float that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit float. </returns>
			/// </summary>
			static float Float(Byte* data);

			/// <summary> Converts 8 Bytes into a 64 bit double.
			/// <para>[Byte* data] Data should point to a 64 bit double that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit double. </returns>
			/// </summary>
			static double Double(Byte* data);

		private:
			Deserialize();
			~Deserialize();
		};
	}
}

#endif