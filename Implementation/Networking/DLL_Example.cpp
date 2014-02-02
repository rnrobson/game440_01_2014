#include "DLL_Example.h"

DLL_Example::DLL_Example()
{
}


DLL_Example::~DLL_Example()
{
}

// This is an example of an exported variable
NETWORKING_API int mSampleInt = 0;

// This is an example of an exported function.
NETWORKING_API int SampleFunc(void)
{
	return 42;
}