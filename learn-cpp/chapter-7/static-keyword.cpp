#include <iostream>

void incrementAndPrint()
{
  static int s_value{1};
  ++s_value;
  std::cout << s_value << '\n';
}

int main()
{
  // despite the value being reintialized in incrementAndPrint the value is saved from previous calls
  incrementAndPrint();
  incrementAndPrint();
  incrementAndPrint();

  return 0;
}
