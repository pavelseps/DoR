#include <conio.h>
#pragma once
class ReadInput
{
public:
	ReadInput();
	~ReadInput();

	//Read input from keyboard (prepared for numbers 0-9, return real value of this numbers)
	int read();
};

