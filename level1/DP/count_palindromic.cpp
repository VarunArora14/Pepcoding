// https://www.youtube.com/watch?v=XmSOWnL6T_I&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=70
#include <iostream>
#include "string"
#include "vector"

using namespace std;

int main()
{

  string str;
  cin >> str;
  int n = str.length();
  vector<vector<bool>> dp(n, vector<bool>(n));
  int count = 0;
  // travel the diagonals based on their gaps. Gap varies from 0 to n-1 so travel from 0 to n-1
  // g is gap
  for (int g = 0; g < n; g++)
  {
    // now travel the diagonal, each diagonal starts with i=0
    // column for each diagonal is j=i+g, at start i=0 then j increases for first diagonal of dp
    // j smaller than length as i+g < n. look at 0th diagonal
    for (int i = 0, j = g; j < n; i++, j++)
    {
      // both i and j will in crease for the 0th diagonal
      // if gap is 0 then dp[i][j]=true as single ele
      if (g == 0)
        dp[i][j] = true;

      // for gap=1, compare the first and 2nd characters, if same then true else false
      else if (g == 1)
      {
        // check if str[i] same as str[j] because dp[i][j] computes isPalindrome() of substring starting from i and ending at j
        // so if gap is 1 i and j are adjacent but we don't know which one is smalller or larger so simply use below

        if (str[i] == str[j]) // or str[i]==str[i+1] as j=1 at start and both i,j change at same rate
          dp[i][j] = true;

        else
          dp[i][j] = false;
      }
      else
      {
        // gap more than 1, then check the extremes first which are str[i] and str[j] and then check dp[i+1][j-1] which is middle
        if (str[i] == str[j] && dp[i + 1][j - 1] == true)
          dp[i][j] = true;
        else
          dp[i][j] = false;
      }

      // check if curr dp[i][j] true then count++
      if (dp[i][j] == true)
        count++;
    }
  }

  cout << "number of palindromic substrings are " << count;
  return 0;
}

/*
total substrings = n(n+1)/2 where number of ways of choosing substrings of size 1 is n, ways of choosing size 2 is n-2 and so on
 n + n-1 + n-2 +...1 is same as 1+2+3+...n-1 + n = n(n+1)/2 (Arithmetic Progression)
 If we check for each substring then total time would be n^2.n = n^3

 By using DP we can do in n^2 space and time

For 0th diagonal ,i=0, j=0
for 1st => i=0,j=1 ,
for 2nd => i=0, j=2,
for 3rd => i=0, j=3 and so on till n-1 (as we included 0)
then j changes as j++ where j is j=i+g, starting at g
We will stop i loop when i+g==n-1 as 0th diagonal went till last row, 1st diagonal till 2nd last row

Each diagonal starts from 0th row and ends at nth column always
*/