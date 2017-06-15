// CheckInput.cpp
#include "CheckInput.h"
#include "CryptoExceptions.h"
#include <string>
#include <iostream>
using namespace std;
bool IsInteger(const char * str)
{
	char* endptr = 0;
	double temp = strtod(str, &endptr);
	if ((*endptr != '\0' || endptr == str) || (temp != int(temp)))
		return false;
	return true;
}
input GetInputDataFromArgs(int argc, char * argv[])
{
	input result;
	if (argc != 4)
		throw CryptoExceptions(CryptoExceptions::InvalidArgNumber);
	if (((argv[1][0] != '1') && (argv[1][0] != '2')) || (argv[1][1] != '\0'))
		throw CryptoExceptions(CryptoExceptions::InvalidCipherType);
	if (((argv[2][0] != 'e') && (argv[2][0] != 'd')) || (argv[2][1] != '\0'))
		throw CryptoExceptions(CryptoExceptions::InvalidOperationMode);
	if (!IsInteger(argv[3]))
		throw CryptoExceptions(CryptoExceptions::InvalidKeyFormat);
	result.cipherType = argv[1][0];
	result.operationMode = argv[2][0];
	result.key = atoi(argv[3]);
	return result;
}

input GetInputDataFromDialog()
{
	input result;
	string temp;
	cout << "Select type of cipher (1 - ShiftCipher, 2 - SubstitutionCipher): \n";
	cin >> temp;
	if (((temp[0] != '1') && (temp[0] != '2')) || (temp[1] != '\0'))
		throw CryptoExceptions(CryptoExceptions::InvalidCipherType);
	result.cipherType = temp[0];
	cout << "Select operation mode. (e - Encrypt, d - Decrypt): \n";
	cin >> temp;
	if (((temp[0] != 'e') && (temp[0] != 'd')) || (temp[1] != '\0'))
		throw CryptoExceptions(CryptoExceptions::InvalidOperationMode);
	result.operationMode = temp[0];
	cout << "Enter the key:\n";
	cin >> temp;
	if (!IsInteger(temp.c_str()))
		throw CryptoExceptions(CryptoExceptions::InvalidKeyFormat);
	result.key = stoi(temp);
	return result;
}
