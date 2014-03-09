#ifndef SERVER_LIASON_H
#define SERVER_LIASON_H

#include "Connection.h"
#include <iostream>

namespace ManaCraft {
	namespace Client {
		class ServerLiason {
			private:
				static int SendToServer(void*);
				static int ListenToServer(void*);
				static void CloseConnection();
				static void ProcessData(Byte* data, int len);

			public:
				static void Start();
		};
	}
}
#endif
