#ifndef INT_FLOAT_PRODUCT_PARAMS_H
#define INT_FLOAT_PRODUCT_PARAMS_H
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

#endif