#include "MyForm.h"
#include <stdio.h>
#include <iostream>
#include <windows.h>

using namespace System;
using namespace std;

[STAThreadAttribute]
int main()
{
	Windows::Forms::Application::Run(gcnew SteganographyJA::MyForm());
	return 0;
}

