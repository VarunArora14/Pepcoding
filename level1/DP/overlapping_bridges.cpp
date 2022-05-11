// https://www.youtube.com/watch?v=o1h3aoeSTOU&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=68
#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

void lis_func(vector<pair<int, int>> vec, int n)
{
  vector<int> lis(n, 1);
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      // check if second or south coordinate of prev ele smaller and lis[j] > lis[i] then lis[i]=lis[j]
      if (vec[j].second < vec[j].first && lis[j] + 1 > lis[i])
      {
        lis[i] = lis[j] + 1; // +1 for current ele
      }
    }
  }
  // now we have the lis, we have to print the max value
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, lis[i]);
  }
  cout << "ans is " << ans << "\n";
}
bool compare(pair<int, int> f, pair<int, int> s)
{
  // if 2 first ele same then return on basis of smaller south
  if (f.first == s.first)
    return f.first < s.first;
  return f.second < s.second; // comparison operator, return true if prev ele smaller
}
int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i].first >> vec[i].second;
  }

  sort(vec.begin(), vec.end(), compare); // sorted based on the first value which is the north coordinate

  // for (auto i : vec)
  // {
  //   cout << i.first << " " << i.second << "\n";
  // }
  lis_func(vec, n);
  return 0;
}

/*
9
87 68
57 35
18 97
3 65
54 97
87 53
88 49
62 43
97 26

  Here we have to consider all the subsets of the ways we can make the bridges because if we do simple lis with
  dp[0]=1 for first bridge we will be wrong as it might be case that north coordinate is 1 and south coordinate is very large
  giving ans as 1 as other bridges with overlap instead of checking whether the in between bridges can be more in number.
  First we make 2^n subsets of the bridges as the way we can choose which bridges can be selected.
  Then for all the selections check if valid by checking all pairs if they overlap or not making the time (2^n)* n^2
  as for each pair you have to check if both north and south smaller.
  Better way to sort based on their north coordinate ordrer and then you apply lis on it's south coordinate meaning we south
  bank will also be increasing and we have to find the longest subsequence.
  The reason this works is that once we have sorted the north ones, they are all in increasing order so no overlapping from their
  side. For reducing the overlapping of south ones, we have to find those south ones which satisfy condition that for given i,
  nums[j] < nums[i] where j from 0 to i-1 to find the lis and then add 1 for current num. This way we can find non overlapping bridges

Why do we care about 2 north values being same?
Consider the 3 bridges in order abc and acb here - https://youtu.be/o1h3aoeSTOU?t=2255
Now abc is correct answer as a before b and b before c. So answer here is 3.
For case acb, lis of a is 1, lis of c is 2 because by sort function if 2 values are same, they are taken in order of input.
Now for c, a is before so lis of c is 2. Note here b is not considered as c entered first as input and both have same values
Then for b, a has smaller value but c has larger so result of this lis is 2.
But correct answer is 3. To avoid these make a compare() for sorting which selects the smaller south so that we get abc and not acb
as c and b intersect at starting point.

Tou can further urse LIS when you have a case where you have to find how many elements before the current element
satisfy a condition and return max elements of any and not necessarily the last element. Meaning while we need ans of n bridges,
if any n-x bridge has more bridges that can be put, we return ans for that.
If for an index we have to find the valid prev indices satisfying the conditions then that comes under LIS group of ques.
*/