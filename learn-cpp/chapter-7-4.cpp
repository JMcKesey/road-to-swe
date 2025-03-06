#include <iostream>

namespace Foo 
{
 int g_x{}; 
}

void doSomething()
{
  Foo::g_x = 3;
  std::cout << Foo::g_x << '\n';
}

int main()
{
  doSomething();
  std::cout << Foo::g_x << '\n'; 
  Foo::g_x = 5; 
  std::cout << Foo::g_x << '\n';
  return 0;
}

// g_x can be used in any function
// goes out of scope after main closing curly brace
// define global variables inside a namespace 
// Variables with static duration are zero-intialized by default
// constant global variables must be intialized
