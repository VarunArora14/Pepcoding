// https://www.youtube.com/watch?v=SHDu0Ufjyk8&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=28
#include <iostream>
#include "vector"
#include "string"
using namespace std;

void sol(int i, int n, vector<bool> &vis, string curr_ans)
{
  if (i > n)
  {
    // we have found the answer till n
    cout << curr_ans << "\n";
    return;
  }
  // check if already visited i
  if (vis[i] == true)
    sol(i + 1, n, vis, curr_ans);
  // simply move to next ele. This condition is especially useful if we have (1)(23) where i is 2 and j=i+1 is 3 and we make pair (2,3) and function calls for 3 to
  // check whether it should go solo or make pair but since it is already mark visited we move to next element after 3 which here prints the answer for i>n condition

  else
  { // first person has 3 options -
    // 1. come alone
    vis[i] = true;
    sol(i + 1, n, vis, curr_ans + "(" + to_string(i) + ") ");

    // 2. it can form a pair with next elements(only)
    for (int j = i + 1; j < n; j++)
    {
      vis[j] = true;
      sol(j, n, vis, curr_ans + "(" + to_string(i) + to_string(j) + ") ");
      vis[j] = false;
      // for backtracking and finding other answers
    }
    used[i] = false;
    // you must make it false so that you find other options while you backtrack}
  }
}

int main()
{
  int n;
  cin >> n;
  // int dp[20] = {};
  // dp[1] = 1; //  base case for single element staying single
  // dp[2] = 2;
  // for (int i = 3; i <= n; i++)
  // {
  //   dp[i] = dp[i - 1] + dp[i - 2] * (i - 1);
  // }
  // cout << dp[n];
  vector<bool> vis(n, false);
  sol(1, n, vis, "");

  return 0;
}
/*
You have to find the number of ways n people can remain single or can pair. example:
"12" => "1-2" and "12"
"123" => "1-2-3", "12-3", "13-2", "23-1"

Now, if we have 1 element, only 1 possible way that is to stay single
for 2, 2 ways, both stay single or pair.
For 3, there are choices for the 3rd ele, either form a pair or stay single
If it stays single then n-1 ele left so we can use the prev result so dp[n-1]. If it forms a pair, then
it will have n-2 elements left along with (n-1) ways to form pairs, so dp[n-2]*(n-1)

If we have 4 elements, then to find the ways, either the first ele can stay single so remaining 3 ways,
or it can form pair and have remaining 3 pairs as the 1st element has 3 elements to make a pair with
so dp[4] has dp[3] + dp[2] + dp[2] + dp[2] ways = dp[3] + 3*dp[2] ways where 3 is (n-1) as 1st ele form pair with any

Another way of looking at answer is if we have "1234", then for 1, choices are -
1 stays single, solve "234", "12" forms pair, solve "34", "13" forms pair, solve "24", "14" forms pair, solve "23"

Note - Count of answer of a given n remains same and can be used for next n+1
*/