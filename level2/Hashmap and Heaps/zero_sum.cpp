#include <iostream>
#include "map"
#include "unordered_map"
#include <vector>

#define sz(x) (int)x.size();
#define lt(x) (int)x.length();
#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

// O(n^2) time, O(1) space
void n2_ans(vi nums, int n)
{
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];
      if (sum == 0)
        ans = max(ans, j - i + 1);
    }
  }
  cout << "max len is " << ans;
}

// O(n) time and O(n) space
void hash_ans(vi nums, int n)
{
  // here we create a map for sums where sum till now is the key and it's idx as value, once we do m1.find(curr_sum)!=m1.end(), the indices are
  // i and m1[curr_sum] as start and end.
  map<int, int> hash;
  // hash[0] = -1;
  int sum = 0, maxval = 0;
  for (int i = 0; i < n; i++)
  {
    sum += nums[i];

    // if there is already sum in map then don't add it again as it will lead to prev idx being ignored and wrong answer

    // insert in hash table if not before
    if (hash.find(sum) == hash.end())
    {
      hash[sum] = i; // insert in hashmap
    }
    else
    {
      // we have found a prev value having same sum so we take it's value(the starting idx of subarray - 1 as it is it's prev ele)
      // which is the value of m1[sum] and then current ending idx of subarray is i, so we do ans=max(ans,i-m1[hash[sum]])
      int start_idx = hash[sum];
      // i is ending index
      int len = i - start_idx; // finding the len of subarray
      // print2(i, start_idx);
      maxval = max(maxval, len);
    }
  }
  for (auto i : hash)
    cout << i.first << " " << i.second << "\n";
  cout << "ans is " << maxval;
}

int main()
{
  int n;
  cin >> n;
  vi nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  hash_ans(nums, n);
  return 0;
}

/*

Here we have to find find a subarray whose sum is 0. For this we start at i=0 and j=0 where i marks the starting point and j marks ending
point of subarray and we return the max j-i+1 value
Another way of doing with map is that in single iteration we push the sum till now, meaning for i=0;i<n;i++ we keep pushing the sum till now
and everytime we check if sum same as prev entered.
                0 1  2 3 4 5
Consider case - 1 2 -2 0 2 3
The sum at 2(idx=1) is 3 and sum at idx=4 is 3 meaning that in between the subarray sum is 0, so we use this to our help
More in the video.


13
-1 2 8 -3 -5 2 -4 6 1 2 1 -3 4
*/