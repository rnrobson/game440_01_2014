#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MATHFUNCS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MATHFUNCS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DATABASE_EXPORTS
#define DATABASE_API __declspec(dllexport)
#else
#define DATABASE_API __declspec(dllimport)
#endif

// This class will be exported to database.dll
class DATABASE_API DLL_Example
{
public:
	DLL_Example();
	~DLL_Example();
};

// Exporting a variable seperate from class
extern DATABASE_API int mSampleInt;

// Exporting a function seperate from class
DATABASE_API int SampleFunc();
