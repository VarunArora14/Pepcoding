// https://www.youtube.com/watch?v=0nF-BMYy7tc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=19
#include <iostream>
using namespace std;

long count_build(int n)
{

  // base case for 1 as n=0 means 0 buildings
  long old_b = 1, old_s = 1;
  for (int i = 2; i <= n; i++)
  {
    long new_b = old_s;
    long new_s = old_b + old_s;

    old_b = new_b;
    old_s = new_s;
  }
  return (old_s + old_b) * (old_s + old_b);
}

int main()
{
  int n;
  cin >> n;
  cout << count_build(n);

  return 0;
}