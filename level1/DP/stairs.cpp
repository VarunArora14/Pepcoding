// https://www.youtube.com/watch?v=A6mOASLl2Dg&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=426
#include <iostream>
#include "vector"
using namespace std;

int stairs(int n, int dp[])
{
  // base case for n=0, <0 and check if dp[n]!=-1
  if (n == 0)
    return 1;
  else if (n < 0)
    return 0;

  if (dp[n] != -1)
    return dp[n];

  int n1 = stairs(n - 1, dp);
  int n2 = stairs(n - 2, dp);
  int n3 = stairs(n - 3, dp);

  // total paths is sum of these
  int tp = n1 + n2 + n3;
  // store in dp and return
  dp[n] = tp;
  return tp;
}

// iterative method and not recursive
int stair_tabulation(int n)
{
  int dp[10]; //  should be dp[n+1]
  dp[0] = 1;  //  smaller problem and base case
  for (int i = 1; i < n; i++)
  {
    if (i == 1)
    {
      dp[i] = dp[i - 1];
    }
    else if (i == 2)
    {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    else
    {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
  }
  return dp[n];
}

int main()
{
  int n;
  int dp[10] = {-1};

  return 0;
}
/*
The above method is memoization, tabulation where have few things -
1. Storage and meaning. Create n+1 array where dp[i] stores number of ways to reach from i to 0
2. Direction - first find which side has smaller problem and which has bigger one
3. Travel and solve
*/