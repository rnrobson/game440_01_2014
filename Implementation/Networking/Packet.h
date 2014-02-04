// Packet.h
#ifndef PACKET_H
#define PACKET_H

#ifdef NETWORKING_EXPORTS
#define NETWORKING_API __declspec(dllexport)
#else
#define NETWORKING_API __declspec(dllimport)
#endif

typedef char byte;

namespace ManaCraft {
	namespace Networking {
		class NETWORKING_API Packet {
		private:
			byte* mSecurityHeader;
			byte mProtocolID;
			byte mObjTypeID;
			byte mObjNumID;
			byte* mData;
			int mDataLength;

		public:
			/// <summary>[Packet]
			/// <para>Initializes a new Packet and initializes variables as null.</para>
			/// </summary>
			Packet();

			/// <summary>[Packet]
			/// <para>Send data over the current network connection.</para>
			/// <param name="securityHeader">[byte* securityHeader] Should point to 4 pre-allocated bytes.</param>
			/// <param name="protocolID">[byte protocolID] A protocol id that represents the type of data being sent.</param>
			/// <param name="objTypeID">[byte objTypeID] The id of the object's type being sent.</param>
			/// <param name="objectNumID">[byte objectNumID] ID of the object.</param>
			/// <param name="data">[byte* data] A pre-allocated array of bytes of data to be sent.</param>
			/// <param name="dataLength">[int dataLength] The length of data.</param>
			/// </summary>
			Packet(byte* securityHeader, byte protocolID, byte objTypeID, byte objNumID, byte* data, int dataLength);

			// Destructor (Not used currently)
			~Packet();

			/// <summary>[SetSecurityHeader]
			/// <para>[SETTER] Set the packet security header.</para>
			/// <param name="newHeader">[byte* newHeader] Should point to 4 pre-allocated bytes.</param>
			/// </summary>
			void SetSecurityHeader(byte* newHeader);

			/// <summary>[SetProtocolID]
			/// <para>[SETTER] Set the packet porotocol ID.</para>
			/// <param name="protocolID">[byte protocolID] A protocol id that represents the type of data being sent.</param>
			/// </summary>
			void SetProtocolID(byte newProtocolID);

			/// <summary>[SetObjTypeID]
			/// <para>[SETTER] Set the packet object type ID.</para>
			/// <param name="objTypeID">[byte objTypeID] The id of the object's type being sent.</param>
			/// </summary>
			void SetObjTypeID(byte newObjTypeID);

			/// <summary>[SetObjNumID]
			/// <para>[SETTER] Set the packet object number ID.</para>
			/// <param name="objectNumID">[byte objectNumID] ID of the object.</param>
			/// </summary>
			void SetObjNumID(byte newObjNumID);

			/// <summary>[SetData]
			/// <para>[SETTER] Set the packet data.</para>
			/// <param name="data">[byte* data] A pre-allocated array of bytes of data to be sent.</param>
			/// </summary>
			void SetData(byte* newData);

			/// <summary>[GetSecurityHeader]
			/// <para>[GETTER] Get the packet security header.</para>
			/// <returns>Returns the packet security header.</returns>
			/// </summary>
			byte* GetSecurityHeader() const;

			/// <summary>[GetProtocolID]
			/// <para>[GETTER] Get the packet porotocol ID.</para>
			/// <returns>Returns the packet protocol ID.</returns>
			/// </summary>
			byte GetProtocolID() const;

			/// <summary>[GetObjTypeID]
			/// <para>[GETTER] Get the packet object type ID.</para>
			/// <returns>Returns the packet object type ID.</returns>
			/// </summary>
			byte GetObjTypeID() const;

			/// <summary>[GetObjNumID]
			/// <para>[GETTER] Get the packet object number ID.</para>
			/// <returns>Returns the packet object number ID.</returns>
			/// </summary>
			byte GetObjNumID() const;

			/// <summary>[GetData]
			/// <para>[GETTER] Get the packet data.</para>
			/// <returns>Returns the packet data.</returns>
			/// </summary>
			byte* GetData() const;

			/// <summary>[GetDataLength]
			/// <para>[GETTER] Get the length of the data.</para>
			/// <returns>Returns the length of the data.</returns>
			/// </summary>
			int GetDataLength();
		};
	}
}
#endif