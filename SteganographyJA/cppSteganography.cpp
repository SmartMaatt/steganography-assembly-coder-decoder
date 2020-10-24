#include "cppSteganography.h"

// funkcja odpowiedzialna za zapisanie przekazanego tekstu do tablicy pikseli obrazu
void cppSteganographyEncode(unsigned char* bmpKey, char* symbol)
{
	int k = 0;

		// zamiana znaku na tablicê bitów
		std::bitset<8> txtBits = std::bitset<8>(*symbol);
		// zamiana 8 danych z tablicy wartoœci rgb na tablicê bitów,
		// tyle jest wtmaganych aby zakodowaæ jeden znak
		std::bitset<8> bmpBits1 = std::bitset<8>(bmpKey[k]);
		std::bitset<8> bmpBits2 = std::bitset<8>(bmpKey[k + 1]);
		std::bitset<8> bmpBits3 = std::bitset<8>(bmpKey[k + 2]);
		std::bitset<8> bmpBits4 = std::bitset<8>(bmpKey[k + 3]);
		std::bitset<8> bmpBits5 = std::bitset<8>(bmpKey[k + 4]);
		std::bitset<8> bmpBits6 = std::bitset<8>(bmpKey[k + 5]);
		std::bitset<8> bmpBits7 = std::bitset<8>(bmpKey[k + 6]);
		std::bitset<8> bmpBits8 = std::bitset<8>(bmpKey[k + 7]);

		// wpisanie wartoœci, bit o indeksie 0 jest najmniej znacz¹cy
		bmpBits1[0] = txtBits[0];
		bmpBits2[0] = txtBits[1];
		bmpBits3[0] = txtBits[2];
		bmpBits4[0] = txtBits[3];
		bmpBits5[0] = txtBits[4];
		bmpBits6[0] = txtBits[5]; 
		bmpBits7[0] = txtBits[6];
		bmpBits8[0] = txtBits[7];

		// zamiana wartoœci bitowych spowrotem na znak
		bmpKey[k++] = static_cast<unsigned char>(bmpBits1.to_ulong());
		bmpKey[k++] = static_cast<unsigned char>(bmpBits2.to_ulong());
		bmpKey[k++] = static_cast<unsigned char>(bmpBits3.to_ulong());
		bmpKey[k++] = static_cast<unsigned char>(bmpBits4.to_ulong());
		bmpKey[k++] = static_cast<unsigned char>(bmpBits5.to_ulong());
		bmpKey[k++] = static_cast<unsigned char>(bmpBits6.to_ulong());
		bmpKey[k++] = static_cast<unsigned char>(bmpBits7.to_ulong());
		bmpKey[k++] = static_cast<unsigned char>(bmpBits8.to_ulong());
}

// funkcja dekoduje zapisane w obrazie znaki do tablicy znaków, aby uzyskaæ tekst
void cppSteganographyDecode(unsigned char* bmpKey, char* symbol)
{
	// zamiana znaku na wartoœæ bitow¹ 
	int k = 0;
	char txtChar = '.';
	std::bitset<8> txtBits = std::bitset<8>(txtChar);

		// zamiana wartoœci obrazu na wartoœæ bitow¹
		std::bitset<8> bmpBits1 = std::bitset<8>(bmpKey[k++]);
		std::bitset<8> bmpBits2 = std::bitset<8>(bmpKey[k++]);
		std::bitset<8> bmpBits3 = std::bitset<8>(bmpKey[k++]);
		std::bitset<8> bmpBits4 = std::bitset<8>(bmpKey[k++]);
		std::bitset<8> bmpBits5 = std::bitset<8>(bmpKey[k++]);
		std::bitset<8> bmpBits6 = std::bitset<8>(bmpKey[k++]);
		std::bitset<8> bmpBits7 = std::bitset<8>(bmpKey[k++]);
		std::bitset<8> bmpBits8 = std::bitset<8>(bmpKey[k++]);

		// wprowadzenie danych z obrazu do danych znaku
		txtBits[0] = bmpBits1[0];
		txtBits[1] = bmpBits2[0];
		txtBits[2] = bmpBits3[0];
		txtBits[3] = bmpBits4[0];
		txtBits[4] = bmpBits5[0];
		txtBits[5] = bmpBits6[0];
		txtBits[6] = bmpBits7[0];
		txtBits[7] = bmpBits8[0];

		*symbol = static_cast<char>(txtBits.to_ulong()); // zamiana wartoœci bitowej na znak
}