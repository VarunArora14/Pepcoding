#include <iostream>
#include "vector"
using namespace std;

int main()
{
  vector<int> v(5);
  v.assign(5, -1);
  cout << v[-1];
  return 0;
}