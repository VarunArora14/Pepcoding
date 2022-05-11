// https://www.youtube.com/watch?v=uNqoQ0sNZCM&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=427
#include <iostream>
#include "climits"
using namespace std;

int dp[10] = {};

int stairs_min(int a[], int n, int a_size)
{
  // base case for 0 as 0 moves to go from n to n
  dp[n] = 0;

  // the iteration or tabulation method must relove around dp[i]=min(dp[i],dp[i+j])
  for (int i = n - 1; i >= 0; i--)
  {
    int min_val = INT_MAX;
    if (a[i] > 0)
    {
      for (int j = 1; j <= a[i] && (i + j) <= n; j++)
      {
        // only take min where dp[i+j]!=nullptr or int_max
        if (dp[i + j] != INT_MAX)
        {
          min_val = min(min_val, dp[i + j]);
        }
      }
      if (min_val != INT_MAX)
      {
        dp[i] = min_val + 1;
      }
      // else let the dp[i] contain the max
    }
  }
  // for (int i = 0; i <= n; i++)
  // {
  //   cout << dp[i] << " ";
  // }
  cout << "\n";
  return dp[0];
}

int main()
{
  int n = 6;
  int a[] = {3, 0, 2, 4, 1};
  int a_size = sizeof(a) / sizeof(a[0]);
  for (int i = 0; i < n; i++)
  {
    dp[i] = INT_MAX;
  }
  cout << stairs_min(a, n, a_size);
  return 0;
}