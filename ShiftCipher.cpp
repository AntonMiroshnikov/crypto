// ShiftCipher.cpp
#include "ShiftCipher.h"


    ShiftCipher::ShiftCipher(int new_key = 0)
	{
		key = new_key;
	}
	char * ShiftCipher::encrypt(char * str)
	{
		return shift(str);
	}
	char * ShiftCipher::decrypt(char * str)
	{
		key = -key;
		return shift(str);
	}
	char * ShiftCipher::shift(char * str)
	{
	  key %= 26;
		for (int i = 0; str[i] != '\0'; i++)
		{
			int upperCaseShift = -1; // -1 - если не является буквой
			if ((str[i] >= 'a') && (str[i] <= 'z'))
				upperCaseShift = 0;
			if ((str[i] >= 'A') && (str[i] <= 'Z'))
				upperCaseShift = 'a' - 'A';
			if (upperCaseShift != -1)
			{
				unsigned char ch = str[i];
				ch += key;
				if (ch > ('z' - upperCaseShift))
					ch -= 26;
				if (ch < ('a' - upperCaseShift))
					ch += 26;
				str[i] = ch;
			}
		}
	}
