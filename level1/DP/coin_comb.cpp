// https://www.youtube.com/watch?v=Ph1EB07Q4pA&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=12
#include <iostream>
using namespace std;

// 2d for no duplicacy, 1d can have
// dp[val+1]
int dp[20] = {};
// The main reason to use 2d array in targetSum and not use here is bcos here we can have
// multiple instances of a[i] for coin sum whereas there we could choose 1 a[i] max that too
// in same order. Here with linear array we make it easier to have multiple instances of a[i]
// as well as save the number of times we have sum=target

// Inorder to avoid permutation and only combination, we process 2 first and only after it we have 3 and then 5
// This is why we have outer loop as i to n. If we had outer as val and for each i we would have checked
// if i == a[j] then it would generate permutations

// outer loop has till n or a[i] in increasing order to have all ways to achieve target for combinations only
void dp_comb(int a[], int n, int val)
{
  // start with smaller denomination and there check if dp[j] += dp[j-a[i]] reason being that
  // make the base case dp[0]=0. For a[i]=2, dp[2]+=dp[0]=1 as all initalised to 0
  // Once 2 is seen, we move to other denomination greater and check the same. In case val=5, we have
  // 2 combinations, first 2 and 3 make 5 so during 3 we will have dp[5]=1 and when a[i]=5, then
  // we have dp[5]+=dp[5-5]=dp[0] or dp[5]+=1 making dp[5]=2

  // base case
  dp[0] = 1;
  for (int i = 0; i < n; i++)
  {
    // since we have outer loop for denomination and that too in increasing order
    // we help printing the combinations only
    for (int j = a[i]; j <= val; j++)
    {
      // starting j=0 makes no sense as j must be atleast a[i] as negative indices are not reachable
      dp[j] += dp[j - a[i]];
      // dp[4] will always be evaluated after dp[2]
    }
  }

  cout << "the combinations are " << dp[val];

  // making empty for permutations
  for (int i = 0; i <= val; i++)
  {
    dp[i] = 0;
  }
  cout << "\n";
}
// In order to get the combinations, make sure that the array is sorted as it gives unique only combinations

// Outer loop has till target or val so that for each i in target, we can find how many different ways to achieve it
// to obtain permutations
void dp_perm(int a[], int n, int val)
{
  // for permutations, for each val, check if any denomination can give any answer where the
  // outer loop is of val and inner of n so that [3,2] and [2,3] are 2 permutations and not
  // considered 1

  // base case
  dp[0] = 1;

  for (int i = 1; i <= val; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // putting this if condition within loop statement leaves the loop
      // completely than just one iteration
      if (i >= a[j])
      {
        dp[i] += dp[i - a[j]];
      }
    }
    // for dp[i] which varies i from 1 to val as 0 is pre defined, we add
    // dp[i-a[j]] as when we include a[j] for each j, we see if there is a number with
    // remaining sum
    // dp[5] has 2 ans [2,3] and [3,2] if a[]={2,3} as for i=5 it will traverse in inner loop
    // a[0]=2 and a[1]=3 so dp[5]+=dp[2] and dp[5]+=dp[3] both will happen in inner loop
    // which means first we have 2 and then see if remaining answer 3 can be solved and then
    // see if we have 3 then remaining 5-3=2 can be solved and so the ans is [2,3] and [3,2]
  }
  for (int i = 0; i <= val; i++)
  {
    cout << dp[i] << " ";
  }
}

int main()
{
  int a[] = {2, 3, 5};
  int n = sizeof(a) / sizeof(a[0]);
  int val = 7;
  dp_comb(a, n, val);
  dp_perm(a, n, val);
  return 0;
}
/*
Given denominations [2,3,5] and value, find the combinations and permutations
for value=7, combinations are { [2,2,3], [2,5] } but the permutations are -
{[2,2,3],[2,3,2],[3,2,2],[2,5],[5,2]}

Note - In the targetSum ques, we could not take duplicates and therefore created 2d array where
each row had it's own a[i] and we checked if it gave answer or not. Here we have linear array
as we can have same a[i] used many times too so no restriction but time remains n^2

You will get permutations when you find all a[j] that can solve for all i where i varies from 1 to val
and a[j] has j varying from 0 to n-1 where inner loop is a[j] searching all ways to make sum equal to i

You will get combinations if all i from i=0 to val have a solution for a[j] where j varies from 0 to n-1
where inner loop is i where we find all solutions of i giving solution for a[j] and it's multiples
i.e. if a[j]=2 then find for all i%2=0 answers by dp[i]=dp[i-a[j]] as both give same answers.
*/