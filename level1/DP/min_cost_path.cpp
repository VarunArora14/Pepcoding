// https://www.youtube.com/watch?v=f8Vdifn2YjQ&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=72&t=1s
#include <iostream>
#include "vector"
using namespace std;

// this returns the count, we need the path
int min_cost(vector<vector<int>> nums, int n, int m)
{
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      // base case for dest
      if (i == n - 1 && j == m - 1)
      {
        dp[i][j] = nums[i][j];
      }
      // make base cases for last row and column and both i and j will be calculated as dp[i][j] = min(dp[i+1][j], dp[i][j+1])
      if (i == n - 1)
      {
        // last row so dont consider next row
        dp[i][j] = dp[i][j + 1] + nums[i][j];
      }
      else if (j == m - 1)
      {
        dp[i][j] = dp[i + 1][j] + nums[i][j];
      }
      else
      {
        dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + nums[i][j];
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> nums(n, vector<int>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> nums[i][j];
    }
  }
  return 0;
}

// to have the min_cost paths, we make a vector<vector<string>> paths which takes the path vector and if ans > path_value then make paths
// empty and push_back path_so_far