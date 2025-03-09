#include <iostream>
// what is internal linkage? can be seen within a single translation unit(file with all the headers) but it is 
// not accessible from other translation units. If two source files have identically named ids with internal linakage,
// those ids will ne treated as independant.

static int g_x{} // non-const globals have external linkage by def, static makes it internal linkage

const int g_y{1}; // have internal linkage by default
constexpr int g_z{ 2 };

int main()
{
	std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
	return 0;
}

// best practice: give ids internal linkage when you have an explicit reason to disallow access from other files.
// Consider giving all ids you don't wnat accessible to other files internal linkage
// static gives default 0 intialization
