// https://www.youtube.com/watch?v=yV-b0amHNVM&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=6
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <climits>

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

void sol(vvi nums, int n, int m)
{
  vvi grid(n, vi(m, -1)); // all initialise as -1

  queue<pair<int, int>> q; // for pushing the indices i and j

  // find all the indices having value as 1 and mark their dist as 0
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (nums[i][j] == 1) // mark as 0 and push in queue
      {
        grid[i][j] = 0;
        q.push({i, j}); // push pair of i,j
      }
    }
  }

  // now queue has all indices of 1 and their dist marked as 0, now traverse the queue till empty and for valid indices unmarked, mark their
  // distances. Note - this is bfs which is shortest path finding algorithm so we find the shortest path in one go by checking if grid[i][j]!=-1
  vvi dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  while (!q.empty())
  {
    // take the first ele and go in all directions
    auto [row, col] = q.front();
    q.pop();

    // we go in all dirs
    for (auto dir : dirs)
    {
      int new_r = row + dir[0];
      int new_c = col + dir[1];
      // print2(new_r, new_c);
      // check if valid. grid[r][c]==-1 means not visited
      if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && grid[new_r][new_c] == -1)
      {
        grid[new_r][new_c] = grid[row][col] + 1; // +1 of previous direction
        ans = max(ans, grid[new_r][new_c]);
        q.push({new_r, new_c}); // push important as we keep doing till valid index and non visited dirs
      }
    }
  }
  for (auto i : grid)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "max dist is " << ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vvi nums(n, vi(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> nums[i][j];
    }
  }
  sol(nums, n, m);
  return 0;
}