// https://www.youtube.com/watch?v=5KdvH15NJjc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=10
#include <iostream>
using namespace std;

int dp[10][10] = {};

int goldmine(int a[][4], int n, int m)
{
  // initalising the first and last row will not make sense as their ele can also be max of prev value from bottom
  // so initalise them for i=0, dp[i][j] = max(dp[i][j+1], dp[i+1][j+1])+a[i][j]
  // The main thing here to notice is that we use the last column's elements for current row elements always
  // and so it is important we have all elements of a column definded before moving to next so we use column as outer
  // loop and row variable as inner loop

  // We travel from right to left from rightmost column to leftmost
  // outer loop is j as we have to travel column in outer loop

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cout << a[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  for (int j = m - 1; j >= 0; j--)
  {
    // for i we can go down to up or up to down
    for (int i = n - 1; i >= 0; i--)
    {
      // initialise the last column, first and last row
      if (j == m - 1)
      {
        // last column, define dp[][] as a[i][j]
        dp[i][j] = a[i][j];
      }
      else if (i == 0)
      {
        // max of right and bottom right node + current for first row
        dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]) + a[i][j];
      }
      else if (i == n - 1)
      {
        // max of right and upper right + current of last row
        dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + 1]) + a[i][j];
      }
      else
      {
        dp[i][j] = max(dp[i][j + 1], max(dp[i + 1][j + 1], dp[i - 1][j + 1])) + a[i][j];
      }
    }
  }
  // for dp make sure the element u are dependent on having ans are already solved
  // At the end find the max of the first column and return

  int max_val = dp[0][0];
  for (int i = 0; i < n; i++)
  {
    max_val = max(max_val, dp[i][0]);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
  return max_val;
}

int main()
{
  int n = 4, m = 4;
  int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 12, 11}, {13, 14, 15, 16}};
  cout << "the max gold collected is \n"
       << goldmine(a, n, m);
  return 0;
}
/*
start digging anywhere in left column to right column(can start from any a[i][0]) till any a[i][m]
In each move he can either go [i-1][j+1] or [i][j+1] or [i+1][j+1]
The direction is good if from left to right as the final destination is not fixed
We need to store the value of prev dp[][] to move forward, since we can do [][j+1], [i+1][j+1] and [i-1][j+1]
we will initialise the first column and i=0 and i=n-1 row and then dp[i][j] = max(dp[i][j-1], dp[i-1][j-1], dp[i+1][j-1]) + a[i][j]
i.e. reversed the signs as we move forward with prev results and then at the end we find the min of last column
and print the answer. Note we have to calculate the max gold and not min
*/