// https://www.youtube.com/watch?v=kQx7nvN_8e4&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=369
#include <iostream>
using namespace std;

int main()
{
  int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int val;
  cin >> val;
  int n = sizeof(a) / sizeof(a[0]);
  int arr_ceil, arr_floor;
  arr_ceil = 0;
  arr_floor = 0;
  int lo = 0, hi = n - 1;

  // make the loop work like binary search
  while (lo <= hi)
  {
    int mid = (hi + lo) / 2;
    if (a[mid] < val)
    {
      // move to the right part of the array and make floor as mid
      // bcos a[mid] is smaller than val and we need the largest smaller value for floor

      arr_floor = a[mid]; //  store a[mid] and not mid
      lo = mid + 1;
    }
    else if (a[mid] > val)
    {
      arr_ceil = a[mid];
      hi = mid - 1;
    }
    else
    {
      // val equal to a[mid], make the ceil and floor same as a[mid]
      arr_ceil = arr_floor = a[mid];
      // break in this case as this is the solution, other if conditions have possible solutions
      break;
    }
  }
  // print the ceil and floor
  cout << arr_ceil << " " << arr_floor;
  return 0;
}
/*
find ceil and floor of a given number from a sorted array, don't go linear but
move like binary search travelling n/2 distance
Now, if mid ele is greater than ele we have to find ceil and floor of, then change the high
to mid-1, floor as mid and find the middle ele again. If the mid is smaller than ele we have then make
ceil as mid and low as mid+1.

*/