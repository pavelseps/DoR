#include "ReadInput.h"


ReadInput::ReadInput()
{
}


ReadInput::~ReadInput()
{
}

int ReadInput::read() {
	int n = -1;
	n = _getch();
	n -= 48;
	return n;
}