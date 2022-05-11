// https://www.youtube.com/watch?v=v62IKeJtj0k&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=40
#include <iostream>
using namespace std;

int main()
{
  int n, i, j, k, m;
  cin >> n >> i >> j >> k >> m;
  int onmask = (1 << i);
  int offmask = ~(1 << j);
  int toggle_mask = (1 << k);
  int check_mask = (1 << m);

  // set the ith bit 1 using onmask
  cout << (n | onmask);                           //  make ith bit on by using or operation with onmask
  cout << (n & offmask);                          //  make the jth bit off by taking and of n and off_maks with all 1's except at jth value where it is 0
  cout << (n ^ toggle_mask);                      //  toggle kth bit using xor where if it was 0, 0^1=1 and if it was 1 then 1^1=0
  cout << ((n & check_mask) == 0 ? false : true); //  if false then bit was off else it was on

  // left shift means moving n number of 0's to right or multiply the number 2^n times
  // 5<<2 means 5*(2^2) and 5<<4 means 5*2^4
  // Don't forget to use braces otherwise cout<<1<<3 will print 13 not 8
  return 0;
}