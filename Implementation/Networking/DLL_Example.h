#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MATHFUNCS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MATHFUNCS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef NETWORKING_EXPORTS
#define NETWORKING_API __declspec(dllexport)
#else
#define NETWORKING_API __declspec(dllimport)
#endif

// This class will be exported to networking.dll
class NETWORKING_API DLL_Example
{
public:
	DLL_Example();
	~DLL_Example();
};

// Exporting a variable seperate from class
extern NETWORKING_API int mSampleInt;

// Exporting a function seperate from class
NETWORKING_API int SampleFunc(void);
