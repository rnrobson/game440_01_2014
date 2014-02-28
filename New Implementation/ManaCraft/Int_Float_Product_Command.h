#ifndef INT_FLOAT_PRODUCT_COMMAND_H
#define INT_FLOAT_PRODUCT_COMMAND_H

//#include <iostream>
#include "ServerIncludes.h"
#include "ServerCommandIncludes.h"
namespace ManaCraft {
	namespace ServerSpace {
		struct Int_Float_Product_Params
		{
		public:
			float x;
			int y;
			float result;
			Int_Float_Product_Params(float _x, int _y)
			{
				x = _x;
				y = _y;
				result = 0;
			}
			~Int_Float_Product_Params(){}
		};
		class Int_Float_Product_Command : public ServerCommand
		{
		private:
			Int_Float_Product_Params* params;

		public:

			Int_Float_Product_Command(void* _data)
			{
				data = _data;
				params = (Int_Float_Product_Params*)data;
				printf("\nInt_Float_Product_Command: Initialized --float = %f", params->x);
				printf("\nInt_Float_Product_Command: Initialized --int = %i", params->y);
			}
			~Int_Float_Product_Command(){}

			void Execute()
			{
				params->result = params->x*params->y;
				printf("\nInt_Float_Product_Command: Executed --result = %f", params->result);
			}

		};
	}
}
#endif