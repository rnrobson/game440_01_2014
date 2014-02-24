#ifndef PACKET_H
#define PACKET_H

typedef char byte;

namespace ManaCraft {
	namespace Networking {
		class Packet {
		private:
			short mProtocolID;
			short mDataLength;
			const byte* mSecurityHeader;
			byte* mData;
			byte* mPayload;

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
			/// <para>[byte* securityHeader] Should point to 4 pre-allocated bytes.</para>
			/// <para>[byte protocolID] A protocol id that represents the type of data being sent.</para>
			/// <para>[byte* data] A pre-allocated array of bytes of data to be sent.</para>
			/// </summary>
			Packet(const byte* securityHeader, short protocolID, byte* data);

			// Destructor (Not used currently)
			~Packet();

			/// <summary>[SetProtocolID]
			/// <para>[SETTER] Set the packet porotocol ID.</para>
			/// <para>[byte protocolID] A protocol id that represents the type of data being sent.</para>
			/// </summary>
			void SetProtocolID(short newProtocolID);

			/// <summary>[SetData]
			/// <para>[SETTER] Set the packet data.</para>
			/// <para>[byte* data] A pre-allocated array of bytes of data to be sent.</para>
			/// </summary>
			void SetData(byte* newData);

			/// <summary>[GetSecurityHeader]
			/// <para>[GETTER] Get the packet security header.</para>
			/// <returns>Returns the packet security header.</returns>
			/// </summary>
			const byte* GetSecurityHeader() const;

			/// <summary>[GetProtocolID]
			/// <para>[GETTER] Get the packet porotocol ID.</para>
			/// <returns>Returns the packet protocol ID.</returns>
			/// </summary>
			short GetProtocolID() const;

			/// <summary>[GetData]
			/// <para>[GETTER] Get the packet's data.</para>
			/// <returns>Returns the packet's data.</returns>
			/// </summary>
			byte* GetData() const;

			/// <summary>[GetDataLength]
			/// <para>[GETTER] Get the length of the data.</para>
			/// <returns>Returns the length of the data.</returns>
			/// </summary>
			short GetDataLength() const;

			/// <summary>[Payload]
			/// <para>[GETTER] Get the packet in bytes.</para>
			/// <returns>Returns the packet as an array of bytes.</returns>
			/// </summary>
			byte* GetPayload() const;

			/// <summary>[PayloadSize]
			/// <para>[GETTER] Get the size of the payload.</para>
			/// <returns>Returns the size of the payload.</returns>
			/// </summary>
			int PayloadSize() const;
		};
	}
}
#endif