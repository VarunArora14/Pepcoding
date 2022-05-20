// https://www.youtube.com/watch?v=TXyKxUmj5XU&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=2
#include <iostream>
#include "vector"
using namespace std;

void floodfill(vector<vector<int>> &nums, int i, int j)
{
  // we travel in all directions marking 1's as 0
  if (i < 0 || j < 0 || i == nums.size() || j == nums[0].size() || nums[i][j] == 0)
    return;
  // valid then make it 0
  nums[i][j] = 0;
  floodfill(nums, i, j + 1);
  floodfill(nums, i, j - 1);
  floodfill(nums, i + 1, j);
  floodfill(nums, i - 1, j);
}

int enclaves(vector<vector<int>> &nums, int n, int m)
{
  // first travel the boundary and find if 1's and if yes the floodfill
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i * j == 0 || i == n - 1 || j == m - 1)
      {
        floodfill(nums, i, j);
      }
    }
  }
  // after this we have to calculate the total nums in the 2d vector
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      sum += nums[i][j];
    }
  }
  return sum;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> nums(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> nums[i][j];
    }
  }
  cout << "sum is " << enclaves(nums, n, m);
  return 0;
}

/*
Find the valid 1's which cannot cross the boundary, meaning if any 1 at boundary then it's connected components are invalid.
For this we travel the boundary and then
5 5
0 0 0 1 0
0 1 1 0 0
0 1 0 0 1
0 0 1 0 0
0 0 1 0 0
*/