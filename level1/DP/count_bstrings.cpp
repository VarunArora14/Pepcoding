// https://www.youtube.com/watch?v=nqrXHJWMeBc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=18
#include <iostream>
using namespace std;

int dpz[20] = {}, dpo[20] = {};
int count_string(int n)
{
  //  base case
  dpz[1] = 1;
  dpo[1] = 1;
  // for 0, dp[0]=0, the above is a better base case for start
  for (int i = 2; i <= n; i++)
  {
    // for sum of 0, it sum sum of
    dpz[i] += dpo[i - 1];
    dpo[i] += dpo[i - 1] + dpz[i - 1]; //  sum of both prev 0 and 1 ans as 2 0's not together with 1
  }
  return dpo[n] + dpz[n]; //  return sum of strings that end with 0 and 1
}

int count_string2(int n)
{
  // we can simply use variables instead of array also
  int old_zero = 1, old_one = 1; //  base case
  for (int i = 2; i <= n; i++)
  {
    int new_zero = old_one;
    int new_one = old_one + new_one;

    old_zero = new_zero;
    old_one = new_one;
  }
  return old_zero + old_one;
}

int main()
{
  int n;
  cin >> n;
  cout << count_string(n);
  return 0;
}
/*
Find count of number of strings such that no 2 consecutive 0's come together
Now we make a array of size n where n is the size of string and at any point in array
i we store the number of appropriate ways we can achieve i length binary strings ending with 1 and 0.
Since a binary string can end with either 1 or 0, depiction of ith string is as follows -
  0 1 2 3 4 5 6
0       .
1       .

Here first dot a 2 means number of working strings that end with 0 and 2nd dot for strings ending with 1
Base case for string of length has has 0 strings of ending with 0 and 1.

For n=1, we get 2 strings "0" and "1" which means 1 string of 0 namely "0" and 1 string of one, namely "1"
For n=2, if we put "1" after any of the above then it gives us strings that end with 1, so we have "11" and "01"
for 0, we cant use 2 0's or "00" so we have 1 string for that which is "10"

For strings ending with "1", we include all the prev strings of i-1 of both "0" and "1" but for 0, we use
only strings of "1" of i-1 as we don't want 2 0's together so for string 10, if we put 0 it will violate the condition.
*/