// ShiftCipher.h
#pragma once

#include "Cipher.h"

class ShiftCipher: public Cipher
{
private:
	char * shift(char * str); // сдвиг алфавита
public:
	ShiftCipher(int new_key);
	virtual char * encrypt(char * str);
	virtual char * decrypt(char * str);
};