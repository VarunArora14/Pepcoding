// https://www.youtube.com/watch?v=WpYHNHofwjc&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=71
#include <iostream>
#include "vector"
using namespace std;

int main()
{
  string str;
  cin >> str;
  int n = str.length();
  vector<vector<bool>> dp(n, vector<bool>(n));
  int lps = 1;
  // from gap=0 to gap=n-1
  for (int g = 0; g < n; g++)
  {
    // move along the diagonal increasing i and j starting with j=g so we find the palidromic substring for between str[i] and str[j]
    // we need to do j<n as with each column, ending point of i decreases by 1 as g increases so it's manily dependent on j
    for (int i = 0, j = g; j < n; i++, j++)
    {
      // if gap is 0 then i==j means single char so dp[i][j]=1
      if (g == 0)
      {
        dp[i][j] = true;
      }
      else if (g == 1)
      {
        // two chars, str[i] and str[j] so just compare them
        if (str[i] == str[j])
        {
          dp[i][j] = true;
        }
        else
          dp[i][j] = false;
      }
      else
      {
        // gap more than 1 so check if end points same meaning str[i] and str[j] and check inner palindrome or not
        if (str[i] == str[j] && dp[i + 1][j - 1] == true)
        {
          dp[i][j] = true;
        }
        else
          dp[i][j] = false;
      }
      if (dp[i][j] == true)
        lps = g + 1; // or max() if you want but same thing as gap increases
      // here g+1 is gap+1, with higher g we go to left of the 2d vector and if dp[i][j] is true and length more
      // than lps, we store it's value. g+1 is the length of the substring as g=0 means single char, g=1 means 2 chars and so on.
      // since gap always increasing, we can simply use lps=g+1 instead of using max()
    }
  }
  cout << "longest palindromic substring is " << lps;
  return 0;
}

// instead of using int as inside of dp, we can use true and false and if true we can check the gap value. If gap+1 more than prev result
// then store ans as gap+1 as gap+1 is the length of the paindromic substring so instead of storing nums in them and checking, we use bool
// and value gap+1