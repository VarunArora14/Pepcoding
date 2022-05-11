#include <iostream>
using namespace std;

int main()
{
  string s = "2";
  s.back() += 1;
  cout << s;
  return 0;
}
// Since max 32 alphabets, number can be max 32 or last 2 digits of the string
// Check 2nd last and last if num, if yes then change the num to num+1
// else if check last, if num