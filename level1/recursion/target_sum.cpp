// https://www.youtube.com/watch?v=zNxDJJW40_k&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=419
#include <iostream>
#include "vector"
#include "string"
using namespace std;

// here we decided to go through all the possible recursion cases and have smart checks and conditions to see
// if it works correctly or not

void target_sum(int a[], int i, int n, int target, string set, int sos)
{
  if (i == n)
  {
    // check if sum same as target and print
    if (sos == target)
    {
      cout << set << ".\n";
    }
    return;
  }
  // your ele has 2 choices, to be or not to be in the set. If you have the curr ele in set
  target_sum(a, i + 1, n, target, set + to_string(a[i]) + ",", sos + a[i]);
  // Another choice to not be in the set
  target_sum(a, i + 1, n, target, set, sos);
}
// Here you have index i, string set which is the current subset, sos is sum of subset and target is the target value
// to be reached

int main()
{
  int a[] = {10, 20, 30, 40, 50}, val = 70;
  int n = sizeof(a) / sizeof(a[0]);
  target_sum(a, 0, n, val, "", 0);
  return 0;
}
/*
Note - no repetition of numbers allowed meaning no [10,10,10,10,10,10]
here you have to see whether an ele becomes a part of subset or not
*/