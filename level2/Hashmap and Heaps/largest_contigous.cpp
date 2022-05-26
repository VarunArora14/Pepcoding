#include <iostream>
#include "set"
#include <vector>
#include <algorithm>
#include <chrono>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;
using namespace chrono;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void sol(vi nums, int n)
{

  int longest = 1;
  for (int i = 0; i < n - 1; i++)
  {
    int curr_max = nums[i], curr_min = nums[i];
    set<int> s;
    // dont forget to insert nums[i] as it will be the first ele otherwise the first 23 will never be inserted
    s.insert(nums[i]);
    for (int j = i + 1; j < n; j++)
    {
      if (s.find(nums[j]) != s.end())
      {
        break;
      }
      s.insert(nums[j]);
      curr_max = max(curr_max, nums[j]);
      curr_min = min(curr_min, nums[j]);
      if (curr_max - curr_min > n)
        break;
      if (curr_max - curr_min == j - i)
      {
        // print2(curr_max, curr_min);
        // print2(i, j);

        longest = max(longest, j - i + 1);
        // print1(longest);
        // cout << "\n";
      }
    }
  }
  cout << "the longest contigous is " << longest;
}

int main()
{
  int n;
  cin >> n;
  vi nums(n);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  auto start1 = high_resolution_clock::now();
  sol(nums, n);
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);

  cout << endl
       << duration.count() / 1000;
  return 0;
}

/*
16
9 2 7 5 6 23 25 22 23 26 19 17 18 16 39 0

Consider case 9 2 7 5 6 23 24 22 23 19 17 18 16 39 0

Here the longest length of contious ele are 19 17 18 16 because when sorted they are in increasing order
23 24 22 is also a continuous one but of length as duplicates are not allowed .
Similarly 7 5 6 is also continous.
For finding a contigous subarray there is a property that for a subarray => max-min = j-i
meaning the nax of subarray - min of it is same as the difference between the starting idx and ending idx
Consider case 7 5 6, max is 7, min is 5
7-5=2 and idx of first ele is 2, last ele is 4 and 4-2=2 which are same and so they are continous.
This also checks for non-duplicates as for 22 23 24 23, max is 24, min is 22 so diff=2 but j-i=3

Here we need to have a hashset to avoid duplicacy as current only looks for max-min=j-i but not if they are valid too
Consider case 23 25 22 23 26
This must be invalid as 24 missing but it gives longest as 5 as max=26, min=22 and j-i=4 same as their diff
*/