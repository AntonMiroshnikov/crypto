// CheckInput.h
#pragma once
struct input
{
	char cipherType, operationMode;
	int key;
};
bool IsInteger(const char * str);
input GetInputDataFromArgs(int argc, char * argv[]);
input GetInputDataFromDialog();