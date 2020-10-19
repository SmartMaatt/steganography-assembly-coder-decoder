#pragma once
#include <string>
#include <bitset>

void cppSteganographyEncode(unsigned char* bmpKey, char symbol);
void cppSteganographyDecode(unsigned char* bmpData, char* txtData, int index);