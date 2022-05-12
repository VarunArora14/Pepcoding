// https://www.youtube.com/watch?v=1otAwCQG7XM&list=PL-Jc9J83PIiHhXKonZxk7gbEWsmSYP5kq&index=6
#include <iostream>
#include "vector"
#include "queue"
using namespace std;

vector<int> k_closest(vector<int> nums, int k, int target)
{

  // max heap which pushes ele on basis of their value, since pair then first value of pair
  // for popping, it opos the top element which is the largest ele in case of max heap
  priority_queue<pair<int, int>> q;
  for (auto i : nums)
  {
    if (q.size() < k)
    {
      q.push({abs(i - target), i});
    }
    else
    {
      int val = abs(i - target);
      if (val < q.top().first)
      {
        q.pop();
        q.push({val, i});
        // if top abs larger than curr then pop the top and push new in priority queue
      }
    }
  }
  // remember to sort the pair after this as we need answers in ascending order of pair.second values
  vector<int> ans;
  for (int i = 0; i < k; i++)
  {
    ans.push_back(q.top().second);
    q.pop();
  }

  sort(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int n, k, target;
  cin >> n >> k >> target;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<int> ans = k_closest(nums, k, target);
  for (auto i : ans)
    cout << i << " ";
  return 0;
}

/*
6 3 45
10 20 30 40 50 60

Instead of making pair of n values, we make priority_queue of size k and enter pair of diff, nums[i] as max heap and not min heap(greater<>)
At the top of the pair we have
*/