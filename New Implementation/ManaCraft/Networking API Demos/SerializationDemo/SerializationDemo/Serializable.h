#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <exception>

namespace ManaCraft {
	namespace Networking {
		/// <summary>
		/// <para>Data represents what parts of the data structure should be serialized.</para>
		/// <para>It allows for more efficient transmission as you don't need to pass the entire data structure through the network.</para>
		/// </summary>
		enum Data : __int8 {
			EVERYTHING,
			POSITION,
			HEALTH,
		};

		class UnsupportedOperationException : public std::exception {
			virtual const char* what() const throw()
			{
				return "ERROR: This operation is unsupported or has not been implemented.\n";
			}
		};

		/// <summary>
		/// <para>Serializable is an abstract class that contains methods used for converting various amounts of class data into an array of bytes.</para>
		/// <para>The base class methods should never be called as they will throw an UnsupportedOperationException since these methods 
		/// are intended to be overridden.</para>
		/// </summary>
		class Serializable
		{
		public:
			virtual ~Serializable() { }

			/// <summary>Converts all class data into an array of bytes for network transmission.
			///	<para>[byte* data] Data should point to an array of preallocated bytes of size SerializedSize().</para>
			/// <para>[Data requiredData] Determines what part of the class should be serialized. </para>
			/// <return>Returns true on success.</return>
			/// </summary>
			virtual bool Serialize(char* data, Data requiredData) { throw UnsupportedOperationException(); }

			/// <summary>
			/// <return>Returns the size of the array if the class were serialized.</return>
			/// <para>[Data requiredData] Helps determine the length of the data for serialization. </para>
			/// </summary>
			virtual int SerializedSize(Data requiredData) const { throw UnsupportedOperationException(); }
		};

		/// <summary>
		/// <para>Deserializable is an abstract class that contains methods used for converting an array of bytes into class data.</para>
		/// <para>The base class methods should never be called as they will throw an UnsupportedOperationException since these methods 
		/// are intended to be overridden by inherited classes</para>
		/// </summary>
		class Deserializable
		{
		public:
			virtual ~Deserializable() { }

			/// <summary>Converts all the array of bytes into class data.
			///	<para>[char* data] Data should point to an array of preallocated bytes of size SerializedSize().</para>
			/// <return>Returns true on success.</return>
			/// </summary>
			virtual bool Deserialize(char* data) { throw UnsupportedOperationException(); }
		};
	}
}

#endif