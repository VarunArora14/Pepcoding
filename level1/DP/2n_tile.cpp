// https://www.youtube.com/watch?v=dVT9JeUMMDE&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=26
#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int dp[20] = {};
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2]; //  n-1 for vertical and n-2 for horizontal
    // here we have to find ways to arrange tile of size 2*1 which can be put vertical or horizontal
    // so total ways comprise of them taking horizontal and vertical area.
    // Note - If 1 tile horizontal then only 1 way for other above it to be same side.
  }
  cout << dp[n];
  return 0;
}
/*
Given a number n, find the number of ways you can align tiles in a 2*n area
for n=1, we have vertical tile, for n=2 we have 2 tiles horizontal and vertical
dp[1]=1 and dp[2]=2
Now, for n=3 we have a 2*3 plane. For this we can use 3 vertical, 2 horizontal and 1 vertical
and 1 vertical and then 2 horizontal.

You can place either vertical or horizontal only as 2*n will be the area. Now if you keep it vertical, you have
n-1 cases to solve now. If you keep it horizontal(you keep 2 dominoes horizontal) and have remaining n-2 left.
Even if u put 1 in horizontal and remaining n-2 have their own ways, the remaining one space for horizontal tile can be
filled in only 1 way that is to keep it horizontal too.
So all the tiles of 2*n can be made for vertical and horizontal tiles leaving n-1 and n-2 problem to be solved.
dp[n]=dp[n-1]+dp[n-2];

*/