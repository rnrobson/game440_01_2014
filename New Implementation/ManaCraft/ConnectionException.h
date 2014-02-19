#pragma once

#include <exception>

namespace ManaCraft {
	namespace Networking {

		/// <summary>[ConnectionOpenException]
		/// <para>Thrown when a Connection is already open and an attempt is made to open it again.</para>
		/// </summary>
		class ConnectionOpenException : public std::exception {
		public:
			ConnectionOpenException() throw() { }
			const char* what() const throw() { return "ConnectionOpenException: Connection being opened is already open"; }
		};

		/// <summary>[ConnectionNotOpenException]
		/// <para>Thrown when a Connection needs to be open to perform an action.</para>
		/// </summary>
		class ConnectionNotOpenException : public std::exception {
		public:
			ConnectionNotOpenException() throw() { }
			const char* what() const throw() { return "ConnectionNotOpenException: Connection being used is accessing a method which requires an open Connection."; }
		};

		/// <summary>[ConnectionNotServerTypeException]
		/// <para>Thrown when an attempt is made to perform an action only a server may perform.</para>
		/// </summary>
		class ConnectionNotServerTypeException : public std::exception {
		public:
			ConnectionNotServerTypeException() throw() { }
			const char* what() const throw() { return "ConnectionNotServerTypeException: Connection being opened is accessing a method which requires a Connection set to act as a server."; }
		};
	}
}