#include "DLL_Example.h"

DLL_Example::DLL_Example()
{
}


DLL_Example::~DLL_Example()
{
}

// This is an example of an exported variable
DATA_API int mSampleInt = 0;

// This is an example of an exported function.
DATA_API int SampleFunc(void)
{
	return 42;
}