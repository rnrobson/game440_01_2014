#pragma once

#include <vector>
#include "DatabaseAPI.h"
#include "DataDefinitions.h"

namespace ManaCraft {
	namespace DataStructures {
		class Element {
		public:
			
			Database::ElementTypes id;

			std::string type;
			std::string weakness;
			std::string strength;

			Element();
			~Element();

			static Element* loadFromDB(ManaCraft::Database::Row);
		};

	}
}
