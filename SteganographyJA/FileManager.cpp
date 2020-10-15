#include "FileManager.h"

FileManager::FileManager()
{
}

String^ FileManager::readFile(System::Object^ sender, System::EventArgs^ e, bool bmp)
{
	Stream^ myStream;
	OpenFileDialog^ dialog = gcnew OpenFileDialog();

	if(bmp) dialog->Filter = "bmp files(*.bmp)|*.bmp";
	else dialog->Filter = "txt files(*.txt)|*.txt";

	if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = dialog->OpenFile()) != nullptr)
		{
			String^ file_adres = dialog->InitialDirectory + dialog->FileName;
			myStream->Close();

			if (bmp) { if (!readBmp(file_adres)) return "Error 3"; }
			else { if (!readTxt(file_adres)) return "Error 3"; }
		}
		else return "Error1";
	}
	else return "Error2";

	return dialog->FileName;
}


bool FileManager::readBmp(String^ adres)
{
	string loaded_adres_std = msclr::interop::marshal_as<string>(adres);
	bool success = false;
	const char *cfilename = loaded_adres_std.c_str();

	FILE* f;
	fopen_s(&f, cfilename, "rb");
	this->headerInfo = new char[54]; // alokowanie 54 bajtów na header pliku
	fread(this->headerInfo, sizeof(char), 54, f); // zczytanie headera

	// informacje o rozmiarze obrazu z headera
	width = *(int*)&headerInfo[18];
	height = *(int*)&headerInfo[22];

	size = 3 * width * height;
	if (size <= 1920 * 1080 * 3 && size > 9)
	{
		bmpData = new char[size]; // 3 bajty na piksel
		fread(bmpData, sizeof(char), size, f); // zczytanie reszty pliku
		success = true;
	}
	else delete[] headerInfo; //Zwolnienie pamięci headerInfo

	fclose(f); // zamkniêcie pliku
	return success;
}


bool FileManager::readTxt(String^ adres)
{
	bool succes = false;
	String^ loaded_file = File::ReadAllText(adres);
	string loaded_file_std = msclr::interop::marshal_as<string>(loaded_file);

	if(loaded_file_std.length() < (this->size)/8)
	{
		this->txtData = new char[loaded_file_std.length() + 1];
		this->txtData[loaded_file_std.length() + 1] = '\0';
		this->txtLenght = loaded_file_std.length();
		succes = true;
	}

	return succes;
}