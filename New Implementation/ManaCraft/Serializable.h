#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <exception>
#include <SDL.h>

typedef char Byte;

namespace ManaCraft {
	namespace Networking {
		/// <summary>
		/// <para>Data represents what parts of the data structure should be serialized.</para>
		/// <para>It allows for more efficient transmission as you don't need to pass the entire data structure through the network.</para>
		/// </summary>
		enum NetData : Uint16 {
			FLAG_01 = 0x0001,
			FLAG_02 = 0x0002,
			FLAG_03 = 0x0004,
			FLAG_04 = 0x0008,

			FLAG_05 = 0x0010,
			FLAG_06 = 0x0020,
			FLAG_07 = 0x0040,
			FLAG_08 = 0x0080,

			FLAG_09 = 0x0100,
			FLAG_10 = 0x0200,
			FLAG_11 = 0x0400,
			FLAG_12 = 0x0800,

			FLAG_13 = 0x1000,
			FLAG_14 = 0x2000,
			FLAG_15 = 0x4000,
			FLAG_16 = 0x8000
		};

		/// <summary>
		/// <para>This exception is used when a certain type of Data (shown above in Serializable.h) has not</para>
		/// <para>been implemented for a given class that inherits from Serializable/Deserializable.</para>
		/// </summary>
		class UnsupportedOperationException : public std::exception {
			virtual const char* what() const throw()
			{
				return "ERROR: This operation is currently unsupported.\n";
			}
		};

		/// <summary>
		/// <para>Serializable is an abstract class that contains methods used for converting various amounts of class data to and from an array of Bytes.</para>
		/// <para>The base class methods should never be called as they will throw an UnsupportedOperationException since these methods 
		/// are intended to be overridden.</para>
		/// </summary>
		class Serializable
		{
		public:
			virtual ~Serializable() { }

			/// <summary>Converts all class data into an array of Bytes for network transmission.
			///	<para>[Byte* data] Data should point to an array of preallocated Bytes of size SerializedSize().</para>
			/// <para>[Data requiredData] Determines what part of the class should be serialized. </para>
			/// <return>Returns true on success.</return>
			/// </summary>
			virtual bool Serialize(Byte* data, Uint16 dataFlags) { throw UnsupportedOperationException(); }

			/// <summary>
			/// <return>Returns the size of the array if the class were serialized.</return>
			/// <para>[Data requiredData] Helps determine the length of the data for serialization. </para>
			/// </summary>
			virtual int SerializedSize(Uint16 dataFlags) const { throw UnsupportedOperationException(); }

			/// <summary>Converts all the array of Bytes into class data.
			///	<para>[char* data] Data should point to an array of preallocated Bytes of size SerializedSize().</para>
			/// <return>Returns true on success.</return>
			/// </summary>
			virtual bool Deserialize(Byte* data) { throw UnsupportedOperationException(); }
		};
	}
}

#endif