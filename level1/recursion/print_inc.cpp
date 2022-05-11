// https://www.youtube.com/watch?v=V-WSKmGTWxk&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=375
// 375 to 380
#include <iostream>
using namespace std;

void print_inc_dec(int n)
{
  if (n == 0)
    return;
  cout << n << "\n";
  print_inc_dec(n - 1);
  cout << n << "\n";
}

// multiply x n times
int power(int x, int n)
{
  // base case
  if (n == 0)
    return 1;
  return x * power(x, n - 1);
}

// make the time complexity log2 n times
int power_log(int x, int n)
{
  if (n == 0)
    return 1;
  // else if (n == 1)
  //   return x;
  int xn2 = power_log(x, int(n / 2));
  // if we do power_log(x, int(n / 2))*power_log(x, int(n / 2)) then we call it
  // many times which is 2*log n/2 instead of log n/2
  int xn = xn2 * xn2;
  if (n % 2 == 1)
    xn = xn * x;
  return xn;
}

// x^n can be written as x^(n/2) * x^(n/2) where x is even and
// x^(n/2) * x^(n/2)*x for n is odd

int main()
{
  int n = 3;
  cout << "power is " << power_log(2, 9);
  return 0;
}
/*
Given n, print in same output 1 ton and n to 1 like -
3
2
1
1
2
3

If print function passes 2 then ans would be
2
1
1
2

We see a pattern that n gets printed before the recursive call and after the recursive call
Since recursion has stack calls of functions, we know that 2 will be printed at the end after the
recursive call of 1 and printing 1 later too
*/