// https://www.youtube.com/watch?v=jdfpGSSyN2I&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=67&t=41s
#include <iostream>
#include "vector"
using namespace std;

vector<int> lis_func(vector<int> nums, int n)
{
  vector<int> lis(n, 0);
  lis[0] = 1; // first ele has lis of 1
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      // find lis to i and store the value for comparison
      if (nums[i] > nums[j] && lis[j] > lis[i])
      {
        lis[i] = lis[j];
      }
    }
    lis[i] += 1; // add 1 for current ele
  }
  return lis;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  vector<int> lis(n), lds(n);
  lis = lis_func(nums, n);
  reverse(nums.begin(), nums.end());
  lds = lis_func(nums, n);

  for (auto i : lis)
  {
    cout << i << " ";
  }

  cout << "\n";
  for (auto i : lds)
  {
    cout << i << " ";
  }

  // Now for each ele we have the lis and lds. If we find the sum of lis[i] and lds[i] -1 and find it's max
  // we get the bitonix subsequence length. -1 as nums[i] repeats twice
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, (lis[i] + lds[i] - 1));
  }
  cout << "\n"
       << ans;
  return 0;
}
/*
8
1 11 2 10 4 5 2 1

6
8 6 3 4 2 1
*/