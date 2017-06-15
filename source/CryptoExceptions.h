// CryptoExceptions.h
#pragma once
#include <exception>

class CryptoExceptions : public std::exception
{
public:
	enum ErrorType { InvalidArgNumber, InvalidCipherType, InvalidOperationMode, InvalidKeyFormat };
private:
	ErrorType t;
public:
	CryptoExceptions(ErrorType T) :t(T) {};
	const char* what() const noexcept;
};
