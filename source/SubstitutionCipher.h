// SubstitutionCipher.h
#pragma once
#include "Cipher.h"

class SubstitutionCipher : public Cipher
{
private:
	char tab[26]; // таблица замены
	void makeTable(); // создание таблицы замены
public:
	SubstitutionCipher(int new_key);
	virtual char * encrypt(char * str);
	virtual char * decrypt(char * str);
};