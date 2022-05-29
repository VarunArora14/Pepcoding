// https://www.youtube.com/watch?v=gkINMhbbIbU
// https://youtu.be/VuNzLtd8PBg
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

void floodfill(vvi &grid, int i, int j, queue<pii> &q, vector<vector<bool>> &vis)
{
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1 || vis[i][j] == true)
    return;
  q.push({i, j});
  // mark the current grid[i][j] as -1 for visited
  vis[i][j] = true;
  floodfill(grid, i, j, q, vis);
  floodfill(grid, i, j, q, vis);
  floodfill(grid, i, j, q, vis);
  floodfill(grid, i, j, q, vis);
}

// floodfill can be made better if we check before calling func instead of calling func and then checking for valid

int sol(vvi grid)
{
  int n = grid.size();
  int m = grid[0].size();
  // we first push the island onto the queue
  vvi dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  queue<pii> q;
  vector<vector<bool>> vis(n, vector<bool>(n));
  bool flag = false;
  // first we brute force to find the src then do floodfill
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vis[i][j] == false && grid[i][j] == 1)
      {
        floodfill(grid, i, j, q, vis);
        flag = 1;
        break;
        // do floodfill once as we have to find source once and then we do bfs
      }
    }
    if (flag)
      break;
  }
  int steps = 0;
  while (!q.empty())
  {
    int qsize = q.size();
    for (int i = 0; i < qsize; i++)
    {
      auto [r, c] = q.front();
      q.pop();

      for (auto dir : dirs)
      {
        int row = r + dir[0];
        int col = c + dir[1];
        if (row >= 0 && col >= 0 && row < n && col < m && vis[row][col] == false)
        {
          // check valid and find neighbours pushing in queue, return steps if dest
          if (grid[row][col] == 1)
            return steps;
          else
          {
            q.push({row, col});
            vis[row][col] = true;
          }
        }
      }
    }
    steps++; // at each level increase steps
  }
  return -1;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vvi grid(n, vi(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  return 0;
}
/*
Here we have to find the shortest path form src to dest but we have src connected to more 1's so a path from any of those 1's will also be valid
we have to find min 0's we can swap to make a bridge. For this we start from src and mark the island first of src
Then we push all those ele in queue and do bfs for non visited finding a non visited num which is our dest
we make queue<pair<int,int>> for starting src 1's for bfs later

At start it takes 0 flips to reach dest, for the neighbours of the island it takes 1 flip.
we can do that we make count=0 and traverse the initial queue till q.size(), if found then return count. else when queue size done and q not
empty, do count++ as we have the neighbours in the queue

initially we brute force to find the first island and then we do dfs or floodfill to get the entire island.
Time would be O(n^2)
memory is O(n^2) for queue and visited array

class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool isValid(int i,int j,int n)
    {
        if(i<0 || j<0 || i>=n || j>=n)
            return false;
        return true;
    }
    void dfs(int i ,int j,vector<vector<int>>&visited,vector<vector<int>>&grid,int n, queue<pair<int,int>>&q)
    {
        visited[i][j]=true;
        q.push({i,j});
        for(int x=0;x<4;x++)
        {
            int ni = i+dx[x];
            int nj = j+dy[x];
            if(isValid(ni,nj,n)&& visited[ni][nj]==false && grid[ni][nj]==1)
                dfs(ni,nj,visited,grid,n,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid)
    {
        int n= grid.size();
        vector<vector<int>>visited(n,vector<int>(n,false));
        bool flag = false;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==false && grid[i][j]==1)
                {
                    dfs(i,j,visited,grid,n,q);
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        int count=0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto tp = q.front();
                q.pop();
                int i = tp.first;
                int j = tp.second;
                for(int x=0;x<4;x++)
                {
                    int ni = i+dx[x];
                    int nj = j+dy[x];
                    if(isValid(ni,nj,n)&& visited[ni][nj]==false)
                    {
                        if(grid[ni][nj]==1)
                            return count;
                        else
                        {
                            q.push({ni,nj});
                            visited[ni][nj]=true;
                        }
                    }
                }
            }
            count++;
        }
        return count;

    }
};

*/