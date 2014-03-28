#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <vector>
#include <cassert>
#include <iostream>

namespace ManaCraft {
	namespace Networking {
		/// <summary>
		/// Provides a clean and abstracted interface for simple serialization and deserialization.
		/// </summary>
		class Serializer {
		public:
			/// <summary>
			/// Represents where the data will be serialized to, or deserialized from.
			/// </summary>
			std::vector<char> mBytes;


			/// <summary> Converts an 8 bit integer into 1 char(s) and adds it to the container of characters.
			/// <para>[__int8 num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const __int8 num);

			/// <summary> Converts an unsigned 8 bit integer into 1 char(s) and adds it to the container of characters.
			/// <para>[unsigned __int8 num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const unsigned __int8 num);

			/// <summary> Converts an 16 bit integer into 2 char(s) and adds it to the container of characters.
			/// <para>[__int16 num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const __int16 num);

			/// <summary> Converts an unsigned 16 bit integer into 2 char(s) and adds it to the container of characters.
			/// <para>[unsigned __int16 num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const unsigned __int16 num);

			/// <summary> Converts an 32 bit integer into 4 char(s) and adds it to the container of characters.
			/// <para>[__int32 num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const __int32 num);

			/// <summary> Converts an unsigned 32 bit integer into 4 char(s) and adds it to the container of characters.
			/// <para>[unsigned __int32 num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const unsigned __int32 num);

			/// <summary> Converts an 64 bit integer into 8 char(s) and adds it to the container of characters.
			/// <para>[__int64 num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const __int64 num);

			/// <summary> Converts an unsigned 64 bit integer into 8 char(s) and adds it to the container of characters.
			/// <para>[unsigned __int64 num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const unsigned __int64 num);

			/// <summary> Converts an 32 bit floating point type into 4 char(s) and adds it to the container of characters.
			/// <para>[float num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const float num);

			/// <summary> Converts an 64 bit floating point type into 8 char(s) and adds it to the container of characters.
			/// <para>[double num] Represents the number that will be converted and added to the container of characters.</para>
			/// </summary>
			Serializer& operator<<(const double num);


			/// <summary> Converts the 1 char(s) at the top of the container into an 8 bit integer removing it.
			/// <para>[__int8 num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(__int8& num);

			/// <summary> Converts the 1 char(s) at the top of the container into an unsigned 8 bit integer removing it.
			/// <para>[unsigned __int8 num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(unsigned __int8& num);

			/// <summary> Converts the 2 char(s) at the top of the container into an 16 bit integer removing it.
			/// <para>[__int16 num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(__int16& num);

			/// <summary> Converts the 2 char(s) at the top of the container into an unsigned 16 bit integer removing it.
			/// <para>[unsigned __int16 num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(unsigned __int16& num);

			/// <summary> Converts the 4 char(s) at the top of the container into an 32 bit integer removing it.
			/// <para>[__int32 num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(__int32& num);

			/// <summary> Converts the 4 char(s) at the top of the container into an unsigned 32 bit integer removing it.
			/// <para>[unsigned __int32 num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(unsigned __int32& num);

			/// <summary> Converts the 8 char(s) at the top of the container into an 64 bit integer removing it.
			/// <para>[__int64 num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(__int64& num);

			/// <summary> Converts the 8 char(s) at the top of the container into an unsigned 32 bit integer removing it.
			/// <para>[unsigned __int64 num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(unsigned __int64& num);

			/// <summary> Converts the 4 char(s) at the top of the container into an 32 bit floating point type removing it.
			/// <para>[float num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(float& num);

			/// <summary> Converts the 8 char(s) at the top of the container into an 64 bit floating point type before removing it.
			/// <para>[double num] Represents the number that will be set in the function.</para>
			/// <para>[WARNING] This function asserts that the vector is at least of size sizeof(num)</para>
			/// </summary>
			Serializer& operator>>(double& num);

		private:
			/// <summary> Adds characters to the top of the container for later use.
			/// <para>[unsigned int num] Represents how many characters will be added to the top of the container.</para>
			/// </summary>
			void AddSpace(const unsigned int num);

			/// <summary> Removes characters from the top of the container.
			/// <para>[unsigned int num] Represents how many characters will be removed from the top of the container.</para>
			/// </summary>
			void RemoveSpace(const unsigned int num);
		};

		/// <summary>
		/// Provides tools to convert data into arrays of characters.
		/// </summary>
		class Serialize {
		public:
			/// <summary> Converts a 8 bit integer into 1 char.
			/// <para>[char* data] Data should point to 1 pre-allocated char.</para>
			/// <para>[__int8 num] Num represents a 8 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int8) for convenience.</returns>
			/// </summary>
			static char* Int8(char* data, const __int8 num);

			/// <summary> Converts a 8 bit integer into 1 char and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[__int8 num] Num represents a 8 bit integer.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void Int8(std::vector<char>& buffer, const unsigned int index, const __int8 num);

			/// <summary> Converts a 8 bit unsigned integer into 1 char.
			/// <para>[char* data] Data should point to 1 pre-allocated char.</para>
			/// <para>[unsigned __int8 num] Num represents a 8 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int8) for convenience.</returns>
			/// </summary>
			static char* UInt8(char* data, const unsigned __int8 num);

			/// <summary> Converts a 8 bit unsigned integer into 1 char and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[unsigned __int8 num] Num represents a 8 bit unsigned integer.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void UInt8(std::vector<char>& buffer, const unsigned int index, const unsigned __int8 num);

			/// <summary> Converts a 16 bit integer into 2 chars.
			/// <para>[char* data] Data should point to 2 pre-allocated chars.</para>
			/// <para>[__int16 num] Num represents a 16 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int16) for convenience.</returns>
			/// </summary>
			static char* Int16(char* data, const __int16 num);

			/// <summary> Converts a 16 bit integer into 2 chars and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[__int16 num] Num represents a 16 bit integer.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void Int16(std::vector<char>& buffer, const unsigned int index, const __int16 num);

			/// <summary> Converts a 16 bit unsigned integer into 2 chars.
			/// <para>[char* data] Data should point to 2 pre-allocated chars.</para>
			/// <para>[unsigned __int16 num] Num represents a 16 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int16) for convenience.</returns>
			/// </summary>
			static char* UInt16(char* data, const unsigned __int16 num);

			/// <summary> Converts a 16 bit unsigned integer into 2 chars and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[unsigned __int16 num] Num represents a 16 bit unsigned integer.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void UInt16(std::vector<char>& buffer, const unsigned int index, const unsigned __int16 num);

			/// <summary> Converts a 32 bit integer into 4 chars.
			/// <para>[char* data] Data should point to 4 pre-allocated chars.</para>
			/// <para>[__int32 num] Num represents a 32 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int32) for convenience.</returns>
			/// </summary>
			static char* Int32(char* data, const __int32 num);

			/// <summary> Converts a 32 bit integer into 4 chars and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[__int32 num] Num represents a 32 bit integer.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void Int32(std::vector<char>& buffer, const unsigned int index, const __int32 num);

			/// <summary> Converts a 32 bit unsigned integer into 4 chars.
			/// <para>[char* data] Data should point to 4 pre-allocated chars.</para>
			/// <para>[unsigned __int32 num] Num represents a 32 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int32) for convenience.</returns>
			/// </summary>
			static char* UInt32(char* data, const unsigned __int32 num);

			/// <summary> Converts a 32 bit unsigned integer into 4 chars and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[unsigned __int32 num] Num represents a 32 bit unsigned integer.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void UInt32(std::vector<char>& buffer, const unsigned int index, const unsigned __int32 num);

			/// <summary> Converts a 64 bit integer into 8 chars.
			/// <para>[char* data] Data should point to 8 pre-allocated chars.</para>
			/// <para>[__int64 num] Num represents a 64 bit integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(__int64) for convenience.</returns>
			/// </summary>
			static char* Int64(char* data, const __int64 num);

			/// <summary> Converts a 64 bit integer into 8 chars and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[__int64 num] Num represents a 64 bit integer.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void Int64(std::vector<char>& buffer, const unsigned int index, const __int64 num);

			/// <summary> Converts a 64 bit unsigned integer into 8 chars.
			/// <para>[char* data] Data should point to 8 pre-allocated chars.</para>
			/// <para>[__int64 num] Num represents a 64 bit unsigned integer.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(unsigned __int64) for convenience.</returns>
			/// </summary>
			static char* UInt64(char* data, const unsigned __int64 num);

			/// <summary> Converts a 64 bit unsigned integer into 8 chars and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[unsigned __int64 num] Num represents a 64 bit unsigned integer.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void UInt64(std::vector<char>& buffer, const unsigned int index, const unsigned __int64 num);

			/// <summary> Converts a 32 bit float into 4 chars.
			/// <para>[char* data] Data should point to 4 pre-allocated chars.</para>
			/// <para>[float num] Num represents a 32 bit floating point number.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(float) for convenience.</returns>
			/// </summary>
			static char* Float(char* data, const float num);

			/// <summary> Converts a 32 bit floating point type into 4 chars and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[float num] Num represents a 32 bit floating point type.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void Float(std::vector<char>& buffer, const unsigned int index, const float num);

			/// <summary>Converts a 64 bit double into 8 chars.
			/// <para>[char* data] Data should point to 8 pre-allocated chars.</para>
			/// <para>[double num] Num represents a 64 bit floating point number.</para>
			/// <returns>[Returns] a pointer to the data that's been incremented by the sizeof(double) for convenience.</returns>
			/// </summary>
			static char* Double(char* data, const double num);

			/// <summary> Converts a 64 bit floating point type into 8 chars and stores it at the specified index in the provided vector of chars.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the indices that the serialized data will be stored at.</para>
			/// <para>[double num] Num represents a 64 bit floating point type.</para>
			/// <para>[WARNING] This function asserts that the index provided is valid given the size of the char vector.</para>
			/// </summary>
			static void Double(std::vector<char>& buffer, const unsigned int index, const double num);

		private:
			Serialize();
			~Serialize();
		};

		/// <summary>
		/// Provides tools to convert arrays of characters into usable data.
		/// </summary>
		class Deserialize {
		public:
			/// <summary> Converts 1 char into a 8 bit integer.
			/// <para>[char* data] Data should point to a 8 bit integer that's currently stored as 1 char.</para>
			/// <returns>[Returns] the deserialized 8 bit integer.</returns>
			/// </summary>
			static __int8 Int8(char* data);

			/// <summary> Converts 1 char into a 8 bit integer.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 8 bit integer.</returns>
			/// </summary>
			static __int8 Int8(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 1 char into a 8 bit unsigned integer.
			/// <para>[char* data] Data should point to a 8 bit unsigned integer that's currently stored as 1 char.</para>
			/// <returns>[Returns] the deserialized 8 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int8 UInt8(char* data);

			/// <summary> Converts 1 char into a 8 bit unsigned integer.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 8 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int8 UInt8(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 2 chars into a 16 bit integer.
			/// <para>[char* data] Data should point to a 16 bit integer that's currently stored as 2 chars.</para>
			/// <returns>[Returns] the deserialized 16 bit integer.</returns>
			/// </summary>
			static __int16 Int16(char* data);

			/// <summary> Converts 2 chars into a 16 bit integer.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 16 bit integer.</returns>
			/// </summary>
			static __int16 Int16(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 2 chars into a 16 bit unsigned integer.
			/// <para>[char* data] Data should point to a 16 bit unsigned integer that's currently stored as 2 chars.</para>
			/// <returns>[Returns] the deserialized 16 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int16 UInt16(char* data);

			/// <summary> Converts 2 chars into a 16 bit unsigned integer.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 16 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int16 UInt16(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 4 chars into a 32 bit integer.
			/// <para>[char* data] Data should point to a 32 bit integer that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit integer.</returns>
			/// </summary>
			static __int32 Int32(char* data);

			/// <summary> Converts 4 chars into a 32 bit integer.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 32 bit integer.</returns>
			/// </summary>
			static __int32 Int32(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 4 chars into a 32 bit unsigned integer.
			/// <para>[char* data] Data should point to a 32 bit unsigned integer that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int32 UInt32(char* data);

			/// <summary> Converts 4 chars into a 32 bit unsigned integer.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 32 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int32 UInt32(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 8 chars into a 64 bit integer.
			/// <para>[char* data] Data should point to a 64 bit integer that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit integer.</returns>
			/// </summary>
			static __int64 Int64(char* data);

			/// <summary> Converts 8 chars into a 64 bit integer.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 64 bit integer.</returns>
			/// </summary>
			static __int64 Int64(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 8 chars into a 64 bit unsigned integer.
			/// <para>[char* data] Data should point to a 64 bit unsigned integer that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int64 UInt64(char* data);

			/// <summary> Converts 8 chars into a 64 bit unsigned integer.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 64 bit unsigned integer.</returns>
			/// </summary>
			static unsigned __int64 UInt64(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 4 chars into a 32 bit float.
			/// <para>[char* data] Data should point to a 32 bit float that's currently stored as 4 chars.</para>
			/// <returns>[Returns] the deserialized 32 bit float. </returns>
			/// </summary>
			static float Float(char* data);

			/// <summary> Converts 4 chars into a 32 bit floating point type.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 32 floating point type.</returns>
			/// </summary>
			static float Float(std::vector<char>& buffer, const unsigned int index);

			/// <summary> Converts 8 chars into a 64 bit double.
			/// <para>[char* data] Data should point to a 64 bit double that's currently stored as 8 chars.</para>
			/// <returns>[Returns] the deserialized 64 bit double. </returns>
			/// </summary>
			static double Double(char* data);

			/// <summary> Converts 8 chars into a 64 bit floating point type.
			/// <para>[std::vector char buffer] Buffer should point to a valid char vector.</para>
			/// <para>[unsigned int index] Index represents the index that a serialized number is stored at.</para>
			/// <returns>[Returns] the deserialized 64 floating point type.</returns>
			/// </summary>
			static double Double(std::vector<char>& buffer, const unsigned int index);

		private:
			Deserialize();
			~Deserialize();
		};
	}
}

#endif