#include <iostream>
#include "external_a.cpp"

extern int g_x;
extern const int g_y;

int main()
{
	std::cout << g_x << ' ' << g_y << '\n';
	return 0;
}


// best practice: only use extern for global variable forward declarations or const global variable definitions
// Do not use extern for non-const global variable definitions(they are already external)
