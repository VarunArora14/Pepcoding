// https://www.youtube.com/watch?v=_c_R-uIi-zU&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=27
#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int dp[20] = {};
  for (int i = 1; i < m; i++)
  {
    dp[i] = 1; //  till i is smaller than m, you cant put them horizontally so all vertical have 1 way
  }
  dp[m] = 2; //  all horizontal and vertical so 2 ways

  // recursively f(n,m)=f(n-1,m) + f(n-m,m)
  for (int i = m + 1; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - m];
  }
  cout << dp[n];
  return 0;
}
/*
You hav n*m floor with tile of size m*1
now tile can be vertical as board has m columns but can be horizontal only when n>m
if vertical then remaining n-1 problems and for horizontal, n-m problems
*/