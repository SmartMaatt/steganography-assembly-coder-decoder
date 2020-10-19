#include "FileManager.h"

//Konstruktor klasy FileManager
FileManager::FileManager()
{
	this->bmpData = nullptr;
	this->headerInfo = nullptr;
	this->txtData = nullptr;
	this->height = 0;
	this->width = 0;
	this->size = 0;
	this->txtLenght = 0;
}

//Funkcja odczytująca pliki bmp lub txt w zależności od przekazanych przełączników
String^ FileManager::readFile(System::Object^ sender, System::EventArgs^ e, bool bmp)
{
	Stream^ myStream;
	OpenFileDialog^ dialog = gcnew OpenFileDialog();	//Utworzenie okna dialogowego

	if(bmp) dialog->Filter = "bmp files(*.bmp)|*.bmp";	//Filtr plików .bmp lub .txt w zależności od parametru
	else dialog->Filter = "txt files(*.txt)|*.txt";

	if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)	//Sprawdzenie załadowania okna dialogowego
	{
		if ((myStream = dialog->OpenFile()) != nullptr)	//Sprawdzenie czy okno dialogowe jest otwarte
		{
			String^ file_adres = dialog->InitialDirectory + dialog->FileName;	//Odczyt adres pliku
			myStream->Close();	//Zamknięcie strumienia

			if (bmp) { if (!readBmp(file_adres)) return "Error3"; }	//Bezpośredni odczyt
			else 
			{ 
				int tmp = readTxt(file_adres);
				if (tmp == 0) return "Error3";	//Nie udało się otworzyć pliku
				else if (tmp == -1) return "Error4";	//Plik jest pusty
			}
		}
		else return "Error2";
	}
	else return "Error1";

	return dialog->FileName;	//Zwrócenie błędów lub ścieżki do pliku
}


//Odczyt plików bmp w wykorzystaniu opcji języka C (bo najbardziej wolę)
bool FileManager::readBmp(String^ adres)
{
	string loaded_adres_std = msclr::interop::marshal_as<string>(adres);	//Konwersja System::String na std::string
	bool success = false;	//Zmienna definiująca wynik operacji
	const char *cfilename = loaded_adres_std.c_str();	//Zapis ścieżki do pliku do char*

	FILE* f;	//Zmienna plikowa
	if ((f = fopen(cfilename, "rb")) == NULL) return success;	//Otwacie w trybie "rb"
	this->headerInfo = new unsigned char[54]; // alokowanie 54 bajtów na header pliku
	fread(this->headerInfo, sizeof(char), 54, f); // zczytanie headera

	// informacje o rozmiarze obrazu z headera
	width = *(int*)&headerInfo[18];
	height = *(int*)&headerInfo[22];

	size = 3 * width * height;
	if (size <= 1920 * 1080 * 3 && size > 9)	//Obraz nie może być większy od FHD
	{
		bmpData = new unsigned char[size]; // 3 bajty na piksel
		fread(bmpData, sizeof(char), size, f); // zczytanie reszty pliku
		success = true;
	}
	else delete[] headerInfo; //Zwolnienie pamięci headerInfo

	fclose(f); // zamkniêcie pliku
	return success;
}


//Odczyt plików txt z wykorzystaniem możliwości System::IO
int FileManager::readTxt(String^ adres)
{
	bool succes = 0;	//Status operacji
	String^ loaded_file = File::ReadAllText(adres);	//Oczyt całości pliku do zmiennej
	string loaded_file_std = msclr::interop::marshal_as<string>(loaded_file);	//Konwersja System::String na std::string

	if (loaded_file_std.length() < 1) return -1;

	if(loaded_file_std.length() < (((this->size)-24)/8))	//Sprawdzenie czy tekst zmieści się w zdjęciu
	{
		this->txtData = new char[loaded_file_std.length() + 1];	//Alokacja miejsca na tekst
		strcpy(this->txtData, loaded_file_std.c_str());	//Przypisanie wartosci do char*
		this->txtData[loaded_file_std.length()] = '\0';	//Dodanie znaku końca łańcucha
		this->txtLenght = loaded_file_std.length();	//Zapis długości tekstu
		succes = 1;
	}

	return succes;	//Zwracanie statusu sytuacji
}


//Funkcja wykonuje zapis do plików i zarządza mniejszymi metodami zapisu
String^ FileManager::saveFile(System::Object^ sender, System::EventArgs^ e, bool bmp)
{
	Stream^ myStream;
	SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();	//Utworzenie okna dialogowego

	if(bmp) saveFileDialog->Filter = "bmp files (*.bmp)|*.bmp";
	else saveFileDialog->Filter = "txt files (*.txt)|*.txt";

	saveFileDialog->FilterIndex = 1;

	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = saveFileDialog->OpenFile()) != nullptr)
		{
			String^ file_adres = saveFileDialog->FileName;	//Odczyt adres pliku
			myStream->Close();

			if (bmp) saveBmp(file_adres);
			else saveTxt(file_adres);
		}
		else return "Error2";
	}
	else return "Error1";

	return saveFileDialog->FileName;
}


//Zapisanie obrazu do .bmp
void FileManager::saveBmp(String^ adres)
{
	//Konwersja System::String na std::string
	string loaded_adres_std = msclr::interop::marshal_as<string>(adres);
	//Konwersja na char*
	const char *cfilename = loaded_adres_std.c_str();

	//Zapisanie do pliku
	FILE* f = fopen(cfilename, "wb");
	fwrite(this->headerInfo, sizeof(unsigned char), 54, f);
	fwrite(this->bmpData, sizeof(unsigned char), size, f);
	fclose(f);
}


//Zapisanie pliku .txt
void FileManager::saveTxt(String^ adres)
{
	//Konwersja System::String na std::string
	string loaded_adres_std = msclr::interop::marshal_as<string>(adres);
	//Konwersja na char*
	const char *cfilename = loaded_adres_std.c_str();

	//Zapisanie do pliku
	FILE* f;
	fopen_s(&f, cfilename, "wb");
	fwrite(txtData, sizeof(char), strlen(txtData), f);
	fclose(f);		//Zamkniêcie pliku
}


//Zwraca wielkość pliku .bmp
int FileManager::getBmpSize() { return this->size; }

//Zwraca długość tekstu .txt
int FileManager::getTxtLength() { return this->txtLenght; }

//Zwraca wskaźnik na klucz
unsigned char* FileManager::getBmpKey(int index) { return this->bmpData + (8 * index); }

//Zwraca wskaźnik na bitmapę
unsigned char* FileManager::getBmpData() { return this->bmpData; }

//Zwraca zawartość pliku tekstowego
char* FileManager::getText() { return this->txtData; }

//Koduje informacje o długości tekstu na pierwszych 24 bitach pliku
void FileManager::encodeTextLength()
{
	//Długość tekstu zakodowana do postaci binarnej
	std::bitset<24> txtLengthBits = std::bitset<24>(this->txtLenght);
	//Zmienna tymczasowa na bity zdjecia
	std::bitset<8> bmpBits;
	//Schowek na wskaźnik na początek tablicy znaków
	unsigned char* tmpBmpKey = this->bmpData;

	//Pętla szyfrująca dane o długości łańcucha na pierwszych 24 bitach do wykorzystania
	for (int i = 0; i < 24; i++) 
	{
		bmpBits = std::bitset<8>(tmpBmpKey[i]);
		bmpBits[0] = txtLengthBits[i];
		this->bmpData[i] = static_cast<unsigned char>(bmpBits.to_ulong());
	}
}

//Dekoduje informacje o długości tekstu z 24 pierwszych 24 bitów pliku i alokuje pamięć na nią
void FileManager::decodeTextLength()
{
	//Pojemnik na długość tekstu zakodowaną do postaci binarnej
	std::bitset<24> txtLengthBits;
	//Zmienna tymczasowa na bity zdjecia
	std::bitset<8> bmpBits;
	//Schowek na wskaźnik na początek tablicy znaków
	unsigned char* tmpBmpKey = this->bmpData;

	//Pętla odszyfrowująca dane o długości łańcucha na pierwszych 24 bitach do wykorzystania
	for (int i = 0; i < 24; i++)
	{
		bmpBits = std::bitset<8>(tmpBmpKey[i]);
		txtLengthBits[i] = bmpBits[0];
	}

	//Wpisanie długości tesktu do zmiennej w postaci int
	this->txtLenght = static_cast<int>(txtLengthBits.to_ulong());

	this->txtData = new char[this->txtLenght + 1];	//Alokacja miejsca na tekst
	this->txtData[this->txtLenght] = '\0';	//Dodanie znaku końca łańcucha
}

//Usuwa dynamicznie zaalokowaną pamięć
void FileManager::deleteData(bool bmp, bool txt)
{
	if (bmp)
	{
		this->width = 0;
		this->height = 0;
		this->size = 0;
		if (this->headerInfo) 
		{
			delete[] this->headerInfo; 
			this->headerInfo = nullptr;
		}
		if (this->bmpData)
		{
			delete[] this->bmpData;
			this->bmpData = nullptr;
		}
	}
	
	if (txt)
	{
		this->txtLenght = 0;
		if (txtData)
		{
			delete[] this->txtData;
			this->txtData = nullptr;
		}
	}
}