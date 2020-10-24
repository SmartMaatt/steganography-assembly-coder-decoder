#include "AlgorythmManager.h"

//Konstruktor klasy AlgorythmManager
AlgorythmManager::AlgorythmManager()
{
}

//Funkcja zarządzająca wywołaniem funkcji dekodowania c++ lub asm
void AlgorythmManager::operateDecode(Object^ parameter)
{
	Tuple<FileManager^, bool, int>^ params = (Tuple<FileManager^, bool, int>^) parameter; // krotka z parametrami
	FileManager^ fileMan = params->Item1;

	if (params->Item2) // jeœli wybrano bibliotekê cpp
	{
		cppSteganographyDecode(fileMan->getBmpKey(params->Item3), &(fileMan->getText()[(params->Item3) - 3]));
	}
	else 
	{
		asmSteganographyDecode(fileMan->getBmpKey(params->Item3), &(fileMan->getText()[(params->Item3) - 3]));
	}
}

//Funkcja zarządzająca wywołaniem funkcji kodowania c++ lub asm
void AlgorythmManager::operateEncode(Object^ parameter)
{
	Tuple<FileManager^, bool, int>^ params = (Tuple<FileManager^, bool, int>^) parameter; // krotka z parametrami
	FileManager^ fileMan = params->Item1;
	int index = (params->Item3);

	if (params->Item2) // jeœli wybrano bibliotekê cpp
	{
		cppSteganographyEncode(fileMan->getBmpKey(params->Item3), &(fileMan->getText()[(params->Item3)-3]));
	}
	else 
	{
		asmSteganographyEncode(fileMan->getBmpKey(params->Item3), &(fileMan->getText()[(params->Item3) - 3]));
	}
}
