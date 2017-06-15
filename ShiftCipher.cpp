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
			if ((str[i] >= 'a') && (str[i] <= 'z')) // Для нижнего регистра
			{
				unsigned char ch = str[i];
				ch += key;
				if (ch > 'z')
					ch -= 26;
				if (ch < 'a')
					ch += 26;
				str[i] = ch;
			}
			if ((str[i] >= 'A') && (str[i] <= 'Z')) // Для верхнего регистра
			{
				unsigned char ch = str[i];
				ch += key;
				if (ch > 'Z')
					ch -= 26;
				if (ch < 'A')
					ch += 26;
				str[i] = ch;
			}
		}
		return str;
	}
