#pragma once
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "FileManager.h"

/*TUTAJ BĘDZIE IMPLEMENTACJA FUNKCJI ASM*/

using namespace std;
using namespace System;

public ref class AlgorythmManager
{
public:
	AlgorythmManager();
	void operateDecode(Object^ parameter);
	void operateEncode(Object^ parameter);
};