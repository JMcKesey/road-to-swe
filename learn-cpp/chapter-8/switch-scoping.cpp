#include <iostream>

int main()
{
  switch(2)
  {
    case 1:
      std::cout << 1 << '\n';
    case 2:
      std::cout << 2 << '\n';
      [[fallthrough]]; // intentional fallthrough - null statement
    case 3:
      std::cout << 3 << '\n';
    default:
      std::cout << "this is default" << '\n';
  }
}

// cases after 2 will be printed because there's no break or return
// this is called fallthrough
