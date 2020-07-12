#include "Colors.h"

bool Color::operator==(Color & color) const
{
	return dword == color.dword;
}
