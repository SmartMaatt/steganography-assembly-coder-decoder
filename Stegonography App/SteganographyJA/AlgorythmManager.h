#pragma once
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "FileManager.h"
#include "cppSteganography.h"

extern "C" bool checkMMXCapability();
extern "C" void asmSteganographyEncode(unsigned char* bmpKey, char* symbol);
extern "C" void asmSteganographyDecode(unsigned char* bmpKey, char* symbol);

using namespace std;
using namespace System;

public ref class AlgorythmManager
{
public:
	AlgorythmManager();
	void operateDecode(Object^ parameter);
	void operateEncode(Object^ parameter);
};