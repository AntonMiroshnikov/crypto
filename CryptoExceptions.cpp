// CryptoExceptions.cpp
#include "CryptoExceptions.h"

// ���������� ������ what ��� CryptoExceptions
const char* CryptoExceptions::what() const noexcept
{
	switch (t)
	{
	case InvalidArgNumber: return "Error: invalid number of arguments.\n"; break;
	case InvalidCipherType: return "Error: invalid cipher type.\n"; break;
	case InvalidOperationMode: return "Error: invalid operation mode.\n"; break;
	case InvalidKeyFormat: return "Error: invalid key format.\n"; break;
	default: return "Unknown error in equation\n";
	}
}
