// https://www.youtube.com/watch?v=vk8sfizNtsY&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=366
#include <iostream>
#include "cmath"
using namespace std;

int main()
{
  int a[] = {1, 2, 3};
  string ans;
  int n = sizeof(a) / sizeof(a[0]);
  int lim = pow(2, n);
  for (int i = 0; i < lim; i++)
  {
    for (int j = n - 1; j >= 0; j++) //  reason for n-1 to 0 is to print in correct order whil putting in string
    {
      // convert i to binary 0's and 1's ro see whether to print ele or not
      int r = i % 2; //  find if even or odd
    }
  }
  return 0;
}
/*
subsets work in a way that if we hav e array "abc" then it has 8 subsets like
_ _ _
_ _ c
_ b _
a _ _ and so on

Now we have to find a way to print all 2^n permutations so with limit 2^n, we do outer loop
of 2^n and then for each character as it can be true or false for being printed

for 1 ele "c", it will have 2^1 subsets _ and c
*/