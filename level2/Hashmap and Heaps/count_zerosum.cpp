// https://www.youtube.com/watch?v=C9-n_H7dsvU&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=6
#include <iostream>
#include <vector>
#include <algorithm>
#include "map"

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

void sol(vi nums, int n)
{
  map<int, int> m1;
  int sum = 0, count = 0;
  for (int i = 0; i < n; i++)
  {
    // here sum is the prefix sum of all ele till now
    sum += nums[i]; // acquire the element in the sum
    if (m1.find(sum) == m1.end())
    {
      // if not in map then push it
      m1[sum] = 1; // if found first time then make it's val as 1 so that next time if same sum we we add this to count and m1[sum]++
      // if same sum found again
    }
    else
    {
      // we have found a subarray whose sum is 0
      // dont count++ but add m1[sum] as it contains the occurences
      count = count + m1[sum];
      m1[sum]++;
      // if m1[sum]=1 means sum has occured once before so 1 subarray, if m1[sum]=2 means same sum has occured twice and now thrice
      // so it will make 2 subarrays of sum=0, one when m1[sum]=0 index and then from m1[sum]=1 index
    }
  }
  cout << "num of subarray with 0 sum is " << count;
}

int main()
{
  int n;
  cin >> n;
  vi nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  sol(nums, n);
  return 0;
}

/*
This ques is like prev zerosum ques where you have to find if sum of subarray is 0 but you have to find count only.
There is one big caveat in this ques ans that if you find a subarray with sum previously found more than once then it means it does not have 1 but
2 subarrays with sum 0
example: 2 8 -3 -5 2 -4 6 1 2 1 -3 4
Consider only the subarray with sum as 7
2 8 -3 has first sum=7 which is not in map
2 8 -3 -5 2 -4 6 1 gives  sum=7 but as in map, count++
Now comes the important case  - at -3, the current sum till now is 7 which should mean 2(i=0) to -3(i=11) gives sum as 7 but
2(i=9) and -3(i=11) also gives sum=0 and till i=8 we also found subarray sum=7 which means 7 has 3 subarrays total and not 2

To calculate this, in hash we maintain the sum as key value as occurences of the sum, at the end we add the sum for values more than 1
which means subarray of 0 sum found.
*/