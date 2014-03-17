#ifndef PACKET_H
#define PACKET_H

#include <vector>

namespace ManaCraft {
	namespace Networking {
		class Packet {
		private:
			short mProtocolID;
			short mDataLength;
			int mSecurityHeader;
			std::vector<char> mData;
			std::vector<char> mPayload;

			/// <summary>[Packet]
			/// <para>Initializes a new Packet and initializes variables as null.</para>
			/// </summary>
			Packet();

		public:
			/// <summary>[Packet]
			/// <para>Creates a packet with the provided data (YOU MUST ).</para>
			/// <para>[int securityHeader] Should point to 4 pre-allocated Bytes.</para>
			/// <para>[short protocolID] A protocol id that represents the type of data being sent.</para>
			/// <para>[std::vector<char>& data] A pre-allocated vector of characters of data to be sent.</para>
			/// </summary>
			Packet(int securityHeader, short protocolID, std::vector<char>& data);

			/// <summary>[Initialize]
			/// <para>Send data over the current network connection.</para>
			/// <para>[Byte* securityHeader] Should point to 4 pre-allocated Bytes.</para>
			/// <para>[Byte protocolID] A protocol id that represents the type of data being sent.</para>
			/// <para>[Byte* data] A pre-allocated array of Bytes of data to be sent.</para>
			/// </summary>
			void Initialize();

			// Destructor (Not used currently)
			virtual ~Packet();

			/// <summary>[SetProtocolID]
			/// <para>[SETTER] Set the packet porotocol ID.</para>
			/// <para>[short protocolID] A protocol id that represents the type of data being sent.</para>
			/// </summary>
			void SetProtocolID(short protocolID);

			/// <summary>[SetData]
			/// <para>[SETTER] Set the packet data.</para>
			/// <para>[Byte* data] A pre-allocated array of Bytes of data to be sent.</para>
			/// </summary>
			void SetData(std::vector<char>& newData);

			/// <summary>[GetSecurityHeader]
			/// <para>[GETTER] Get the packet security header.</para>
			/// <returns>Returns the packet security header.</returns>
			/// </summary>
			const int GetSecurityHeader() const;

			/// <summary>[GetProtocolID]
			/// <para>[GETTER] Get the packet porotocol ID.</para>
			/// <returns>Returns the packet protocol ID.</returns>
			/// </summary>
			short GetProtocolID() const;

			/// <summary>[GetData]
			/// <para>[GETTER] Get the packet's data.</para>
			/// <returns>Returns the packet's data.</returns>
			/// </summary>
			std::vector<char> GetData() const;

			/// <summary>[GetDataLength]
			/// <para>[GETTER] Get the length of the data.</para>
			/// <returns>Returns the length of the data.</returns>
			/// </summary>
			short GetDataLength() const;

			/// <summary>[Payload]
			/// <para>[GETTER] Get the packet in Bytes.</para>
			/// <returns>Returns the packet as an array of Bytes.</returns>
			/// </summary>
			std::vector<char> GetPayload() const;

			/// <summary>[PayloadSize]
			/// <para>[GETTER] Get the size of the payload.</para>
			/// <returns>Returns the size of the payload.</returns>
			/// </summary>
			int GetPayloadSize() const;
		};
	}
}
#endif