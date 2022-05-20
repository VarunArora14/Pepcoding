// https://www.youtube.com/watch?v=Dq3dGS_0Z6o&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=5
#include <iostream>
#include "vector"
#include "queue"
using namespace std;

void rotten_oranges(vector<vector<int>> nums)
{
  int n = nums.size();
  int m = nums[0].size();
  int fresh = 0, days = 0;
  vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (nums[i][j] == 2)
        q.push({i, j});
      else if (nums[i][j] == 1)
        fresh++;
    }
  }
  if (fresh == 0)
  {
    cout << "no fresh so ans is 0";
    return;
  }
  while (!q.empty() && fresh > 0)
  {
    queue<pair<int, int>> q1;

    // no need for curr_size as we use 2 queues
    while (!q.empty() && fresh > 0)
    {
      auto [row, col] = q.front();
      q.pop();
      for (auto dir : directions)
      {
        int new_row = row + dir[0];
        int new_col = col + dir[1];
        if (new_row >= 0 && new_row <= n - 1 && new_col >= 0 && new_col <= m - 1 && nums[new_row][new_col] == 1)
        {
          // valid and fresh found then push their index in queue, fresh-- and mark rotten
          q1.push({new_row, new_col});
          nums[new_row][new_col] = 2;
          fresh--;
        }
      }
    }
    // swap both of them
    q = q1;
    q1 = {};
    days++;
  }
  cout << "\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << nums[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  if (fresh > 0)
  {
    // means some oranges were isolated and cant be infected so return -1;
    cout << " some oranges= " << fresh << " left so ans is -1";
    return;
  }
  cout << "days are " << days;
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
  rotten_oranges(nums);
  return 0;
}

/*
given matrix with values 0,1 and 2 where 0 is for empty cell, 1 for orange and 2 for rotten orange.
If an orange has any orange on top, left, right and bottom then it becomes rotten too.
if [0,2] then ans is 0 as no change.
for [
  [2,1,1],
  [1,1,0],
  [0,1,1]
]

it takes 4 days by going bfs.
Go bfs, push initially all the rotten oranges indices and then check for valid positions and nums[i][j]=1, mark it as rotten and keep going till
prev queue empty and then swap secondary and first queue or loop q.size() for keeping count for days and increase day only after q.size() done or at
time of swapping.

Note that we have to return -1 if impossible. For finding impossible we have to travel all the nums[i][j]=1 indices and see if their adjcaent

3 3
2 1 1
1 1 0
0 1 1
*/