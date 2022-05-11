// https://www.youtube.com/watch?v=MOFUK3PyOPw&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=384
// 384 to 389

#include <iostream>
using namespace std;

void print(int a[], int n)
{
  if (n == 0)
    return;
  cout << a[n - 1] << "\n";
  print(a, n - 1);
}

int big = 0;
void max_arr(int a[], int n)
{
  if (n == 0)
    return;
  if (big < a[n - 1])
    big = a[n - 1];
  max_arr(a, n - 1);
}

int fo = -1;
// go from left to right as we have to find the first idx and not last so preorder
void first_occur(int a[], int n, int val, int idx)
{
  // base case
  if (idx == n - 1)
    return;
  // ele found then set the pos and return to exit the func
  if (val == a[idx])
  {
    fo = idx;
    return;
  }
  first_occur(a, n, val, idx + 1);
}

int lo = -1;
void last_occur(int a[], int n, int val)
{
  if (n == 0)
    return;
  // check in preorder with the last ele
  if (val == a[n - 1])
  {
    lo = n - 1;
    return;
    // exit when last ele found
  }
  last_occur(a, n - 1, val);
}

// why traverse the whole if you have to find the first occurence, so pass
// idx and n both in the function for going left ro right else O(n) time always

int main()
{
  int a[] = {1, 2, 13, 4, 5, 4, 2};
  int n = sizeof(a) / sizeof(a[0]);
  first_occur(a, n, 2, 0);
  cout << "first index is " << fo;
  last_occur(a, n, 2);
  cout << "\nlast index is " << lo;
  return 0;
}
/*
Print arr using recursion without any iteration
*/