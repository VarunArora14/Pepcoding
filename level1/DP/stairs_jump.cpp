// https://www.youtube.com/watch?v=uNqoQ0sNZCM&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=427
#include <iostream>
using namespace std;

int stairs_jump(int n, int a[], int a_size, int dp[])
{
  // base case for dp[n]
  dp[n] = 1; //  number of ways to jump from n to n is 1

  // iterative function for all n-1 to 0 and for each i, traverse through
  // a[i] in inner loop i.e. j=1;j<=a[i] bcos minimum steps=1 and max steps=a[i] and not <a[i]
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 1; j <= a[i] && (i + j) <= n; j++)
    {
      dp[i] += dp[i + j]; //  make sure i+j<dp length
      // Note we are changing i going right to left and not making dp[n] the largest
      // answer would be dp[0]
    }
  }
  // start from n-1 and find the ways it can jump
  // go from right to left and make dp[i]=dp[i+j] where i+j<=n such that we store ways to reach n
  // in right to left order
  return dp[0];
}

int main()
{
  int n = 6;
  // array of 5
  int a[] = {2, 3, 0, 2, 3};
  int a_size = sizeof(a) / sizeof(a[0]);
  int dp[10] = {0};
  cout << stairs_jump(n, a, a_size, dp);
  return 0;
}

/*
You have to go from stair 0 to n and for each stair u are given how many stairs u can climb up
Now for solving DP problem you look at 3 steps -
1. Storage and Meaning - Create n+1 array where for each dp[i] stores the ways to i to n
2. Direction - The smaller problem lies closer to n as at 0 we have to find ways to go up whereas
it is easier to go from n-1(or other closer to n)
3. Travel and solve
*/