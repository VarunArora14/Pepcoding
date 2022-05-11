#include <iostream>
#include "vector"
using namespace std;

// int rec_lis(vector<int> v, int n, int max = 1)
// {
//   // for recursive code for f(n) we have to find 1 + max(f(1),f(2),f(3)...f(n-1)) because it is possible that numbers can be in decreasing order
//   // inside the array
//   // initially the max lis is 1

//   if (n == 1)
//     return 1; //  base case
// }

int dp_lis(vector<int> v, int n)
{
  vector<int> dp(n);
  dp[0] = 1;
  int ans = 0;
  for (int i = 1; i < n; i++)
  {
    // for inner loop go to each ele and check if prev num smaller than it or not and for the smaller ones
    // store the max dp[j] and add 1 to it
    int maxval = 0; // here we initalise it 0 to and at end add 1 making it minimum 1 which is for all cases
    for (int j = 0; j < i; j++)
    {
      // checking if prev ele smaller then use the max of their  results
      if (v[i] > v[j] && maxval < dp[j])
      {
        maxval = dp[j];
      }
    }
    dp[i] = maxval + 1;    //  +1 for adding the current ele adding the length of lis
    ans = max(ans, dp[i]); // checking ans everytime and storing the max value
  }

  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  cout << dp_lis(v, n);
  return 0;
}
/*
5
3 10 2 1 20
*/