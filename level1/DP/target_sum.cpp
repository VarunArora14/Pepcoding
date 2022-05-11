// https://www.youtube.com/watch?v=CqEsqfidKi0&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=10
#include <iostream>
using namespace std;

// int dp[n + 1][val + 1];
bool dp[20][20];

//  make the first row false as not including any the element only have anwer 0
// make the first column true as not including any element will give answer 0
// this makes dp[0][0] as true

// check if without using the current ele do we have the true for dp[i][j]
// meaning do without having ele do we have complete sum and also if we include current
// value then do we get the sum or not
// so check dp[i-1][j] if true or if dp[i][j-a[i]] where a[i] is the value to subtracted from j
// to see if reduced sum has value satisfied or not
// if j is 7 and current is 4, then check if (7-4)=3 is true or not

// else first check if current a[i] is included then the remaining sum is positive or not
// also if dp[i][j] once true, we don't have to check again

// print the last ele meaning dp[n][val] as we had to find ans for val for array of n size

void dp_target(int a[], int n, int val)
{
  // for each element check if we can get the sum by includig and not including the element
  // reason for using 2d array is that we can have 1 element used only once and so have each row
  // for each a[i]. Also subset means we have to have elements in same order each having choice to either
  // be or not be part of the subset
  for (int i = 0; i <= n; i++) //  first row of null or 0 as base case, others a[i]
  {
    for (int j = 0; j <= val; j++)
    {
      // base case for 0,0 then i=0 and j=0
      if (i == 0 && j == 0)
      {
        dp[i][j] = true;
      }
      else if (i == 0)
      {
        dp[i][j] = false;
      }
      else if (j == 0)
      {
        dp[i][j] = true; //  first column
      }
      else
      {
        // keep this outside the if condition as we have to also compare for elements
        // smaller than a[i] as we will use their answer. Since [i-1][j] already true before
        // no need to do any comparisons as we have ans for ele till now
        if (dp[i - 1][j] == true)
        {
          // checks for all j if prev i has any true or not
          dp[i][j] = true;
        }
        else //  see if dp[i][j-data] is true or not
        {
          // as j<a[i] means getting negative indices that make no sense

          // first we check if answer in prev row which gets forwarded by dp[i][j]=dp[i-1][j]
          // if true. Note that we have to maintain the order so if we have answer for 6 then we
          // first check for our new a[i] if dp[i-1][6] has the ans true and if yes keep moving
          // else check dp[i][j-a[i]]. We cannot change the order of a[i] as we want subsets which are
          // 2^n and not (n!)*2^n where we can change the positions

          int data = a[i - 1]; //  a[i-1] stores the real index as first index is for null/0 for base case
          if (j >= data)
          {
            if (dp[i - 1][j - data] == true)
            {
              dp[i][j] = true;
            }
          }
          // we do dp[i-1][j-data] as we check if prev solution has the answer and then compare
          // without repeating a[i-1] going through i.e. inorder to find target sum for 4, ans should be false
          // and not true for [2,2]
          // Checking prev row makes sure repetition of same a[i-1] does not occur(i-1 as we have i=0 for null or base case)
        }
      }
    }
  }
  cout << dp[n][val];
}

int main()
{
  int a[] = {4, 1, 3, 2, 7}, val = 10;
  int n = sizeof(a) / sizeof(a[0]);
  dp_target(a, n, val);
  return 0;
}
/*
Find if there exists any subsets of array a[] whose sum is exactly val
This can't be solved in 1d array, we need to have a 2d array of size n*n where
n is the length of the a[] array and then while traversing we find if by using and not using the
current element will it give the eaxt sum in a row.
Meaning if first ele is 4 then we see if including 4 and not including 4 will exactly give the ans
we want.

This algo ensures no duplicacy by looking at ans of only previous row by seeing if we include and not include 5
in our subset, does it give answer for j or not(0<=j<=val) and similarly the prev row contains similar ans
that see their prev row if they have answer or not for j

*/