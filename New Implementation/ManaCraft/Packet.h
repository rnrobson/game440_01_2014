#ifndef PACKET_H
#define PACKET_H

typedef char Byte;

namespace ManaCraft {
	namespace Networking {
		class Packet {
		private:
			short mProtocolID;
			short mDataLength;
			const Byte* mSecurityHeader;
			Byte* mData;
			Byte* mPayload;

			// Rebuild Payload
			void NewPayload();

			// Override copy constructors
			Packet(const Packet&);
			void operator=(const Packet&);

		public:
			/// <summary>[Packet]
			/// <para>Initializes a new Packet and initializes variables as null.</para>
			/// </summary>
			Packet();

			/// <summary>[Packet]
			/// <para>Send data over the current network connection.</para>
			/// <para>[Byte* securityHeader] Should point to 4 pre-allocated Bytes.</para>
			/// <para>[Byte protocolID] A protocol id that represents the type of data being sent.</para>
			/// <para>[Byte* data] A pre-allocated array of Bytes of data to be sent.</para>
			/// </summary>
			Packet(const Byte* securityHeader, short protocolID, Byte* data);

			// Destructor (Not used currently)
			~Packet();

			/// <summary>[SetProtocolID]
			/// <para>[SETTER] Set the packet porotocol ID.</para>
			/// <para>[Byte protocolID] A protocol id that represents the type of data being sent.</para>
			/// </summary>
			void SetProtocolID(short newProtocolID);

			/// <summary>[SetData]
			/// <para>[SETTER] Set the packet data.</para>
			/// <para>[Byte* data] A pre-allocated array of Bytes of data to be sent.</para>
			/// </summary>
			void SetData(Byte* newData);

			/// <summary>[GetSecurityHeader]
			/// <para>[GETTER] Get the packet security header.</para>
			/// <returns>Returns the packet security header.</returns>
			/// </summary>
			const Byte* GetSecurityHeader() const;

			/// <summary>[GetProtocolID]
			/// <para>[GETTER] Get the packet porotocol ID.</para>
			/// <returns>Returns the packet protocol ID.</returns>
			/// </summary>
			short GetProtocolID() const;

			/// <summary>[GetData]
			/// <para>[GETTER] Get the packet's data.</para>
			/// <returns>Returns the packet's data.</returns>
			/// </summary>
			Byte* GetData() const;

			/// <summary>[GetDataLength]
			/// <para>[GETTER] Get the length of the data.</para>
			/// <returns>Returns the length of the data.</returns>
			/// </summary>
			short GetDataLength() const;

			/// <summary>[Payload]
			/// <para>[GETTER] Get the packet in Bytes.</para>
			/// <returns>Returns the packet as an array of Bytes.</returns>
			/// </summary>
			Byte* GetPayload() const;

			/// <summary>[PayloadSize]
			/// <para>[GETTER] Get the size of the payload.</para>
			/// <returns>Returns the size of the payload.</returns>
			/// </summary>
			int PayloadSize() const;
		};
	}
}
#endif