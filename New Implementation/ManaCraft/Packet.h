#ifndef PACKET_H
#define PACKET_H

#include <vector>

namespace ManaCraft {
	namespace Networking {
		class Packet {
		private:
			int mSecurityHeader;
			short mProtocolID;
			std::vector<char> mData;
			std::vector<char> mPayload;

			/// <summary>[Packet]
			/// <para>Initializes a new Packet and initializes variables as null.</para>
			/// </summary>
			Packet();

		public:
			/// <summary>[Packet]
			/// <para>Creates a packet with the provided data (You MUST call Initialize() to serialize the packet).</para>
			/// <para>[int securityHeader] Should point to the security header defined in Protocol.</para>
			/// <para>[short protocolID] A protocol id that represents the type of data being sent.</para>
			/// <para>[std::vector<char>& data] A pre-allocated vector of characters.</para>
			/// </summary>
			Packet(int securityHeader, short protocolID, std::vector<char>& data);

			/// <summary>[Initialize]
			/// <para>Serializes the packet into a vector of characters. Use GetPayload() to get the vector.</para>
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
			/// <para>[std::vector<char>& data] A pre-allocated vector of chars.</para>
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
			/// <returns>Returns the packet as a vector of chars.</returns>
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