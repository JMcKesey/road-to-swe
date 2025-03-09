#include <iostream>

int main()
{
  int apples{5};

  {
    std::cout << apples << '\n';
    // temporarily shadow the value of apples
    int apples{0};
    apples = 10;

    std::cout << apples << '\n';
  }
  // output is 5 where apples was orignally declared
  std::cout << apples << '\n';
  return 0;
}

// best practice: avoid shadowing
// gcc -Wshadow
