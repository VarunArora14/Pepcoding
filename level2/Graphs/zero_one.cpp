// https://www.youtube.com/watch?v=BJbaUH9dN24&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=4
#include <iostream>
#include "vector"
#include "queue"
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
  // we push all the 0's in the queue
  // vector<vector<int>> dirs = {
  //           {-1,0},
  //   {0,-1},          {0,1},
  //           {1,0}
  // };
  // maintain a dist 2d vector as to save the answer. Doing on same would be problem and little more diff
  queue<pair<int, int>> q; // queue for indices

  // first push all the indices with 0 in them as we find the 1's with distance 1

  int n = mat.size();
  int m = mat[0].size();
  vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
  vector<vector<int>> dist(n, vector<int>(m, -1)); // assign non visited as -1
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == 0)
      {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  // assign 0 to all 0's first while pushing them in queue as we use the queue to find their adjacent

  while (!q.empty())
  {
    auto [row, col] = q.front();
    q.pop();
    // for given row, col of pair, go in directions
    for (auto dir : directions)
    {
      int new_row = row + dir[0];
      int new_col = col + dir[1];
      if (new_row >= 0 && new_row <= n - 1 && new_col >= 0 && new_col <= m - 1 && dist[new_row][new_col] == -1)
      {
        // validation check, especially dist[new_row][new_col]=-1 which means not visited
        dist[new_row][new_col] = dist[row][col] + 1;
        q.push({new_row, new_col});
      }
    }
  }
  return dist;
}

// also instead of dist matrix, we can use the same matrix by assigning initially all non-zeros as -1 and checking mat[new_row][col]==-1

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
  vector<vector<int>> ans = updateMatrix(nums);
  return 0;
}
/*
Here, for each 1 in the matrix we have to find the distance to closest 1
Consider the below example -
0 0 0
0 1 0
1 1 1

the output vector would be
0 0 0
0 1 0
1 2 1

as the 1,2 position 1 has to first go to any other 1 and then go to 0. We can also say we have to find the min of left, right and top values.
if(nums[i][j]==0) then dist[i][j]=0

Better to find ones connected to 0's and if we start with 1's then things get difficult as we have to backtrack to store the values of inner 1's
and then update to min values too.
Here what we can do is assign all the indices as INT_MAX and then for all indices 0 mark dist[i][j] as 0. Then go to left, right, top and bottom of each 0
and if any 1 found mark dist as dist[i][j] = dist[zero_i][zero_j] + 1 or simply 1 as all 0's have distance 0 so dist[zero_i][zero_j] always 0.
Better to first do it for all 0's first so they get out of picture and we have 1's to consider only, especially inner ones and for each 1 where
dis[i][j] is INT_MAX, do

*/