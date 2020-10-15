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

	/*
	void saveBmp(string filename);
	void saveTxt(string filename);
	void setTxtData(char* newData);
	void deleteData();


	unsigned char* getBmpData();
	char* getTxtData();
	int getBmpSize();
	int getTxtLength();
	*/
};