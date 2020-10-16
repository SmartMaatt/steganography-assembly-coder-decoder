#pragma once
#include <string>
#include <direct.h>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//Klasa zarządzająca plikami .bmp oraz .txt
//posiada metody do zapisu, odczytu, oraz operacji na owych plikach
//oraz ich parametry
public ref class FileManager
{
private:
	int width, height, size, txtLenght;
	char *bmpData, *txtData, *headerInfo;

public:
	FileManager();
	String^ readFile(System::Object^ sender, System::EventArgs^ e, bool bmp);
	bool readBmp(String^ adres);
	bool readTxt(String^ adres);

	int getBmpSize();
	int getTxtLength();

	/*
	void saveBmp(string filename);
	void saveTxt(string filename);
	void setTxtData(char* newData);
	void deleteData();


	unsigned char* getBmpData();
	char* getTxtData();
	*/
};