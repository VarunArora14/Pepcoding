// https://www.youtube.com/watch?v=u3A64HQq_Dw&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=4
#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
  vector<int> nums{-4, -1, 0, 3, 10};

  vector<int> res;
  int start = 0, end = nums.size() - 1;
  while (start < end)
  {
    if (abs(nums[start]) >= abs(nums[end]))
    {
      res.push_back(nums[start]);
      start++;
    }
    else
    {
      res.push_back(nums[end]);
      end--;
    }
  }
  // This works in O(n)
  for (auto &i : res)
    i = i * i;

  for (auto i : res)
    cout << i << " ";
  return 0;
}

/*
What we do here is in nums vector, we find the numbers whose square will be of max value and put those numbers in another vector. Here the
problem is not with space but time as it is reduced to O(n). We look at the leftmost and righmost ele of nums and see which has the abs high
value as that will make the first ele of our solution. Create 2 pointers, start and end, and while(start<end) if abs[nums[start] > abs[nums[end]]]
push the nums[start] in vector and do start++
*/

// The caveat to this question is that we have to do this in order of n but here the sort takes order nlogn
/*
int main()
{
  vector<int> nums{-4, -1, 0, 3, 10};

  for (int i = 0; i < nums.size(); i++)
  {
    nums[i] = nums[i] * nums[i];
  }
  sort(nums.begin(), nums.end());
  for (auto i : nums)
    cout << i << " ";
  return 0;
}
*/
