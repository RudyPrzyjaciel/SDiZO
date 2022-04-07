#include "pointInt2.h"


pointInt2::pointInt2(int a = 0, int b = 0) : x(a), y(b) {}
pointInt2::pointInt2(void) : x(0), y(0) {}

int pointInt2::xCoord()
{
	return x;
}

int pointInt2::yCoord()
{
	return y;
}
