#include "DLL_Example.h"

DLL_Example::DLL_Example()
{
}


DLL_Example::~DLL_Example()
{
}

// This is an example of an exported variable
DATABASE_API int mSampleInt = 0;

// This is an example of an exported function.
DATABASE_API int SampleFunc(void)
{
	return 42;
}