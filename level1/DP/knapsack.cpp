// https://www.youtube.com/watch?v=bUSaenttI24&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=16
#include <iostream>
using namespace std;

// int dp[n+1][W+1]
int dp[20][20] = {};
// make all ele 0
void dp_knapsack(int a[], int val[], int n, int W)
{
  // base case 0,0 and dp[0][j] row will have 0 for base case
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
        if (a[i - 1] <= j)
        {
          // a[i-1] has our first index kindof base case for empty bag or no weight making first row 0
          int data = a[i - 1];
          // remaining weight cannot be negative
          dp[i][j] = max(dp[i][j], dp[i - 1][j - data] + val[i - 1]);
          // we use dp[i-1][j-data] as we don't want a situation where things to repeat
          // so we use only prev row answers
          // Remember to use val[i-1] and a[i-1] as both have to use 1 index smaller for
          // their current elements
        }
      }
    }
    // In case i=3 and data or a[i-1]=2, it will give repetitive answers if we do
    // dp[i][j-data] which will change the answers for j=4 and dp[3][4] = max(dp[2][4], dp[3][2]+val[i-1])
    // as we already have dp[3][2] value, we will use it again leading to repetitive use of a[i-1] but here we
    // only want 1 ele used once so use prev row [i-1][j]
  }
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  int a[] = {2, 5, 1, 3, 4}, val[] = {15, 14, 10, 45, 30}, W = 7;
  int n = sizeof(a) / sizeof(a[0]);
  // both a[] and val have same size
  dp_knapsack(a, val, n, W);
  return 0;
}

/*
It revolves around same problem that we can only put 1 item once and have a max weight
to to achieve or get close to. Like target sum, we use 2d array here to avoid duplicacy and
since we need max weight W, 2d array would be of size [n+1][W+1]

base case would be dp[0][0]=1

We check previous row if we have sum j(0<=j<=W) till now by max of dp[i-1][j] and dp[i-1][j-a[i]]
unsure if 2nd will be [i-1][j-a[i]] or [i][j-a[i]] and then add to the max value val[i]
*/