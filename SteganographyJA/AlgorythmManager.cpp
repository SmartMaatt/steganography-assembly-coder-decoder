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
		std::cout << "Leci cpp kodowanie " << fileMan->getText()[params->Item3] << std::endl;
		cppSteganographyDecode(fileMan->getBmpKey(params->Item3), fileMan->getText(), (params->Item3) - 3);
	}
	else
		std::cout << "Leci asm kodowanie " << fileMan->getText()[params->Item3] << std::endl;
	//asmSteganographyEncode();
}

//Funkcja zarządzająca wywołaniem funkcji kodowania c++ lub asm
void AlgorythmManager::operateEncode(Object^ parameter)
{
	Tuple<FileManager^, bool, int>^ params = (Tuple<FileManager^, bool, int>^) parameter; // krotka z parametrami
	FileManager^ fileMan = params->Item1;

	if (params->Item2) // jeœli wybrano bibliotekê cpp
	{
		std::cout << "Leci cpp kodowanie " << params->Item3 << std::endl;
		cppSteganographyEncode(fileMan->getBmpKey(params->Item3), fileMan->getText()[(params->Item3)-3]);
	}
	else
		std::cout << "Leci asm kodowanie " << fileMan->getText()[params->Item3] << std::endl;
		//asmSteganographyEncode();
}
