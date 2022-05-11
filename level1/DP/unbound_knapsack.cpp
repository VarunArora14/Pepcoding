// https://www.youtube.com/watch?v=jgps7MXtKRQ&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=17
#include <iostream>
using namespace std;

int dp[20] = {};
void unbound_knapsack(int a[], int val[], int n, int W)
{
  // since we can use duplicates, how abt using linear array with inner loop for a[i] which gives the
  // max value fo any j(0<=j<=val)
  // This follows tabulation method so first storage and meaning. Storage is [W+1] and smaller subproblem on left
  dp[0] = 0; //  base case
  int max_val = 0;
  for (int i = 1; i <= W; i++)
  {
    // we need to calc the max for each W and then store in dp[i]
    for (int j = 0; j < n; j++)
    {
      // dp[i] = max(dp[i], dp[i - a[j]] + val[j]);
      // having if condition outside makes more sense than in loop as if we have
      // i>=a[j] inside the loop then we have dp[] as [0,0,15,15,30,60,70,80]
      // the reason being for i=1 and a[0]=2 the loop does not run but should run
      // as a[2] is 1. The condition in for loop completely leaves the loop and not just
      // one iteration. For single iteration to be left(what we want) have the if condition
      // inside loop
      if (i >= a[j])
      {
        // max_val = max(dp[i], dp[i - a[j]] + val[j]);
        dp[i] = max(dp[i], dp[i - a[j]] + val[j]);
      }
      // dp[i] = max_val;
    }
  }

  for (int i = 0; i <= W; i++)
  {
    cout << dp[i] << " ";
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j <= W; j++)
  //   {
  //     if (a[i] <= j)
  //     {
  //       int data = j - a[i];
  //       dp[j] = max(dp[j], dp[data] + val[i]);
  //     }
  //   }
  // }
}

// Since here duplicacy is allowed, like targetSum it was 2d as no duplicacy but here duplicacy so 1d
// like coin combinations
int main()
{
  int a[] = {2, 5, 1, 3, 4}, val[] = {15, 14, 10, 45, 30}, W = 7;
  int n = sizeof(a) / sizeof(a[0]);
  unbound_knapsack(a, val, n, W);
  return 0;
}
/*
Understand the diff between targetSum and coin change
Here we are looking for permutations to find the maximum value that can generate from
permutations of weights with their values.
In this question both permutation and combination would have given the same answer
as weight [3,3,1] and [3,1,3] will give
*/