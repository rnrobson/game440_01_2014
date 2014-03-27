#ifndef DATABASE_API_H
#define DATABASE_API_H

#include <exception>
#include <string>
#include <vector>
#include <mysql++.h>
#include "DataDefinitions.h"
#include "TableInfo.h"

//-- Data Structures
//#include "Element.h"

using namespace mysqlpp;

namespace ManaCraft {
	namespace Database {

		class DatabaseAPI {

		private:
			static Connection* conn;
			static std::string db_Name, server, login, password;

			DatabaseAPI() { }
			~DatabaseAPI();

		public:
			/// <summary> Set parameters used to connect to database.
			/// <para>[string] Name of the data base to connect to. </para>
			/// <para>[string] Server IP Address to connect to. </para>
			/// <para>[string] Login account name. </para>
			/// <para>[string] Login password. </para>
			/// </summary>
			static void setConnectionParams(const std::string& _db_Name, const std::string& _server, const std::string& _login, const std::string& _password);

			/// <summary> Checking this function is unneccessary for connecting and disconnecting, as internal functions already check for an established connection.
			/// <returns>[Returns] a bool. True if database is connected. </returns>
			/// </summary>
			static bool isConnected();

			/// <summary> Establishes a connection to a database.
			/// <returns>[Returns] a bool. True if connection was established. </returns>
			/// </summary>
			static bool connectToDatabase();

			/// <summary> Disconnects from the database if a connection is already established. </summary>
			static void disconnectFromDatabase();

			static Query getQuery();

			/// <summary> Querys database if connected.
			/// <para>[string] SQL formatted query. </para>
			/// <returns>[Returns] mySQLpp::Query object. Call Query.use() to use results. </returns>
			/// </summary>
			static Query queryDatabase(const std::string& queryStr);

			class IDNotFound : public std::exception
			{
			public:
				IDNotFound() throw() { }
				const char* what() const throw() { return "IDNotFoundException: Could not find ID in the Database.\n"; }
			};

		};
	}
}
#endif