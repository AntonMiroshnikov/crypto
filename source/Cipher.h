// Cipher.h
#pragma once

class Cipher
{
protected:
	int key;
public:
	virtual char * encrypt(char * str) = 0;
	virtual char * decrypt(char * str) = 0;
};