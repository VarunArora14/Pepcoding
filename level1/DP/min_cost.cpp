// https://www.youtube.com/watch?v=BzTIOsC0xWM&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=8
#include <iostream>
#include "cstring"
using namespace std;

int dp[10][10] = {};
// This is from left to right or the direction in which we solve bigger subproblems first
// and then come close to smaller
void dp_ans(int a[][3], int n, int m)
{
  // first initialise the first row and top column

  // base case initalization
  // first row
  dp[0][0] = a[0][0];
  for (int i = 1; i < n; i++)
  {
    dp[i][0] = dp[i - 1][0] + a[i][0];
  }
  // top column
  for (int j = 1; j < m; j++)
  {
    dp[0][j] = dp[0][j - 1] + a[0][j];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      // base case

      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    }
  }
  cout << dp[n - 1][m - 1] << "\n";
}

// The reason we had dp[0][0] initalised is bcos we had to find the sum and for base case
// if dp[i][0]=dp[i-1][0]+a[i][0] had to be done as we needed the sum and not individual cells

// what if we go from right to left or smaller to bigger subrpoblem i.e. goinf from a[n][m] to a[0][0]

int dp2[10][10] = {};
void dp_reverse(int a[][3], int n, int m)
{
  // base case when i==n-1 and j==m-1
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      // base case for a[n][m]
      if (i == n - 1 && j == m - 1)
      {
        dp2[i][j] = a[i][j];
      }
      // other case for bottom row, we goinf right to left as j changing
      else if (i == n - 1)
      {
        dp2[i][j] = dp2[i][j + 1] + a[i][j];
      }
      // other case when we at last column and i is changing
      // It is similar to initialisation for dp[i][0] but in opposite way
      else if (j == m - 1)
      {
        dp2[i][j] = dp2[i + 1][j] + a[i][j];
      }
      else
      {
        dp2[i][j] = min(dp2[i + 1][j], dp2[i][j + 1]) + a[i][j];
      }
    }
  }
  cout << dp2[0][0];
}

int main()
{
  int n = 3, m = 3;
  int a[][3] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
  dp_ans(a, n, m);
  dp_reverse(a, n, m);
  return 0;
}
/*
Given a matrix with each cell having it's weights, you can only go down or right
find the min cost where each cell represents it's cost
for a 1 by 1, the cost is a[0][0]
for 2 by 2 you have to take min(a[i+j][j],a[i][j+1])
making sure i<n && j<m
*/