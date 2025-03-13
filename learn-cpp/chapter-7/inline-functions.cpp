#include <iostream>

inline int min(int x, int y)
{
	return (x<y) ? x : y;
}


int main()
{
	std::cout << min(5, 6) << '\n';
	std::cout << min(3, 2) << '\n';

	return 0;
}

// best practice: do not use inline keyword, modern compilers are already really good at optimization
// inline function allow duplication however
// c++17 inline variables:
// variables that are allowed to be defined in multiple files.
