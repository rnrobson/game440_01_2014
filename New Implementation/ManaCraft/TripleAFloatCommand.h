#ifndef TRIPLE_FLOAT_H
#define TRIPLE_FLOAT_H

//#include <iostream>
#include "ServerIncludes.h"
#include "ServerCommandIncludes.h"
namespace ManaCraft {
	namespace ServerSpace {
		class TripleAFloatCommand : public ServerCommand
		{
		public:
			struct Params
			{
				float x;
			};
			Params params;

			TripleAFloatCommand(void* _data)
			{
				data = _data;
				params = *(Params*)data;
				printf("\nTripleAFloatCommand: Initialized --data = %f", params.x);
			}
			~TripleAFloatCommand(){}

			void Execute()
			{
				params.x *= 3.0f;
				printf("\nTripleAFloatCommand: Executed --data = %f", params.x);
			}

		};
	}
}
#endif