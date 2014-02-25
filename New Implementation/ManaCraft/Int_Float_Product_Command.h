#ifndef INT_FLOAT_PRODUCT_COMMAND_H
#define INT_FLOAT_PRODUCT_COMMAND_H

//#include <iostream>
#include "ServerIncludes.h"

class Int_Float_Product_Command : public ServerCommand
{
public:
	
	Int_Float_Product_Params* params;

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
#endif