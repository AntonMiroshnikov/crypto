// SubstitutionCipher.cpp
#include <iostream>
#include <cstdlib>
#include "SubstitutionCipher.h"


	SubstitutionCipher::SubstitutionCipher(int new_key = 0)
	{
		key = new_key;
		for (char i = 0; i < 26; i++)
			tab[i] = 0;
		makeTable();
	}
	char * SubstitutionCipher::encrypt(char * str)
	{
		for (int i = 0; str[i] != '\0'; i++)
			if ((str[i] >= 'a') && (str[i] <= 'z'))
				str[i] = tab[str[i] - 'a'];
			else if ((str[i] >= 'A') && (str[i] <= 'Z'))
				str[i] = tab[str[i] - 'A'] - 'a' + 'A';
		return str;
	}
	char * SubstitutionCipher::decrypt(char * str)
	{
		for (int i = 0; str[i] != '\0'; i++)
			for (int j = 0; j < 26; j++)
			{
				if ((str[i] >= 'a') && (str[i] <= 'z'))
					if (str[i] == tab[j])
					{
						str[i] = j + 'a';
						break;
					}
				if ((str[i] >= 'A') && (str[i] <= 'Z'))
					if ((str[i] - 'A' + 'a') == tab[j])
					{
						str[i] = j + 'A';
						break;
					}
			}
		return str;
	}
	void SubstitutionCipher::makeTable()
	{
		srand(key);
		for (char i = 0; i < 26; i++)
		{
			int rnd = rand() % (26 - i);
			int k = 0;
			for (int j = 0; j < 26; j++)
			{
				if (tab[j] == 0)
				{
					if (k == rnd)
					{
						tab[j] = 'a' + i;
						break;
					}
					else
						++k;
				}
			}
		}
	}
