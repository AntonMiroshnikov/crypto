// main.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "ShiftCipher.h"
#include "SubstitutionCipher.h"
#include "CryptoExceptions.h"
#include "CheckInput.h"

using namespace std;

int main(int argc, char * argv[])
{
	char ans = 'n'; // ответ пользователя 
	do
	{
		input inp;
		try
		{
			if (argc == 1)
				inp = GetInputDataFromDialog(); // получения данных во время диалога с пользователем
			else
				inp = GetInputDataFromArgs(argc, argv); // получения данных из параметров командной строки
		}
		catch (CryptoExceptions& e)
		{
			cerr << e.what();
			return 1;
		}
		cout << "Enter the text:\n";
		char *buffer = NULL;
		if (argc == 1)
		{
			string sbuffer;
			cin >> sbuffer;
			buffer = new char[sbuffer.length() + 1];
			strcpy_s(buffer, sbuffer.length() + 1, sbuffer.c_str());
		}
		else
		{
			buffer = new char[256];
			cin.get(buffer, 256);
		}
		Cipher * ciph;
		if (inp.cipherType == '1')
			ciph = new ShiftCipher(inp.key);
		else
			ciph = new SubstitutionCipher(inp.key);
		if (inp.operationMode == 'e')
			cout << ciph->encrypt(buffer);
		else
			cout << ciph->decrypt(buffer);
		delete[] buffer;
		if (argc == 1)
		{
			cout << "\nOnce more?(y/n)\n"; // запрос на повторное выполнение
			cin >> ans;
		}
	}
	while (ans == 'y');  // выполняется пока пользователь отвечает "y"
	return 0;
}


