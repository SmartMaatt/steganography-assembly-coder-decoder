#pragma once
#include <string>
#include <bitset>
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
	char *txtData;
	unsigned char *bmpData, *headerInfo;

public:
	FileManager();
	String^ readFile(System::Object^ sender, System::EventArgs^ e, bool bmp);
	bool readBmp(String^ adres);
	int readTxt(String^ adres);

	String^ saveFile(System::Object^ sender, System::EventArgs^ e, bool bmp);
	void saveBmp(String^ adres);
	void saveTxt(String^ adres);

	int getBmpSize();
	int getTxtLength();

	unsigned char* getBmpData();
	unsigned char* getBmpKey(int index);
	char* getText();

	void encodeTextLength();
	void decodeTextLength();

	void deleteData(bool bmp, bool txt);
};