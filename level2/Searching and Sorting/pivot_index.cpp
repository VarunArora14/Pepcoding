#include <iostream>
#include "vector"
using namespace std;

int pivot_idx(vector<int> nums, int n)
{
  int mid = n / 2;
  // if we do binary search and then check for left and right subarrays then time would be nlogn
  // but if we go to mid having found once the left and right sum and if left_sum<right_sum then  left_sum+a[mid], mid++, right_sum - a[mid]
  int left_sum = 0, right_sum = 0;
  for (int i = 0; i < mid; i++)
  {
    left_sum += nums[i];
  }
  for (int i = mid + 1; i < n; i++)
  {
    right_sum += nums[i];
  }
  int count = n / 2;

  while (count--)
  {
    if (left_sum == right_sum)
      return mid;
    else if (left_sum < right_sum)
    {
      left_sum += nums[mid];
      mid++;
      right_sum -= nums[mid];
    }
    else
    {
      right_sum += nums[mid];
      mid--;
      left_sum -= nums[mid];
    }
  }

  return -1;
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
  cout << pivot_idx(nums, n);
  return 0;
}

/*
6
1 7 3 6 5 6
*/