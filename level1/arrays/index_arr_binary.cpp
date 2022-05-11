// https://www.youtube.com/watch?v=PFaoQ72ziNk&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=371
#include <iostream>
using namespace std;

int main()
{
  int a[] = {10, 10, 20, 20, 20, 30, 40, 50, 50};
  int val = 20;
  int n = sizeof(a) / sizeof(a[0]);
  int lo = 0, hi = n - 1;
  int fi = -1; //  first index
  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
    if (a[mid] < val)
    {
      lo = mid + 1;
    }
    else if (a[mid] > val)
    {
      hi = mid - 1;
    }
    else
    {
      // when you have a[mid] as the ele you find
      fi = mid; // potential
      // now this is where the change is, go left for first index of arr
      hi = mid - 1;
    }
  }
  cout << "the first index is " << fi;

  // do the same for last index too
  lo = 0;
  hi = n - 1;
  int li = -1;
  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
    if (a[mid] < val)
    {
      lo = mid + 1;
    }
    else if (a[mid] > val)
    {
      hi = mid - 1;
    }
    else
    {

      // here change the li making it as potential answer(mid) and then go right
      li = mid;
      lo = mid + 1;
    }
  }
  cout << "\n the last index is " << li;
  return 0;
}
/*
modify binary search in a way that that ina sorted array of repeating ele, you find
first and last index of a number given in the input. Do binary search normally except for case
when a[mid]=val, where you store mid as a potential answer let's say for hi and continue binary search
forward till a[mid]>val and if greater then u have hi final value.
Similarly, mark lo when a[mid]=val and do binary search for left side till u have smaller ele than val

*/