// https://www.youtube.com/watch?v=TCDPgRgCNr0&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=362
#include <iostream>
#include "vector"
using namespace std;

int main()
{
  int a[] = {3, 4, 1, 2, 0};
  int n = sizeof(a) / sizeof(a[0]);
  vector<int> b(n);
  for (int i = 0; i < n; i++)
  {
    int val = a[i];
    b[val] = i;
  }
  for (auto i : b)
  {
    cout << i << " ";
  }
  return 0;
}
/*
Inverse means for the array of size n, we have values inside it from 0 to n,
make the a[i] has value x then make a[x] as value i
*/