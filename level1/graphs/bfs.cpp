//
#include <iostream>
#include "queue"
#include "vector"
using namespace std;

const int N = 1e5 + 4;    //  max number as well as value of vertices
vector<int> adj[N], dist; //  the reason dist is not 2d vector is that we only need to define for all nodes
// that can be done linearly
bool vis[N] = {false};

// v is first vertex to start with and n for number of edges
// we only need n for assigning all dis.assign(n+1,-1) and not for anything else
void bfs(int v, int n) // , int n
{
  dist.assign(n + 1, -1);
  queue<int> q;
  q.push(v);
  vis[v] = true;
  // first distance is 0
  dist[v] = 0;
  while (!q.empty())
  {
    int first = q.front();
    cout << first << " ";
    q.pop();
    for (int i : adj[first])
    {
      if (!vis[i])
      {
        vis[i] = true;
        q.push(i);
        // change the distance making dist[i] as dist[first]+1 as the ele would be connected to first
        dist[i] = dist[first] + 1;
      }
    }
  }
  cout << "\n";
  for (int i = 1; i < 8; i++) //  as first ele is 1 of bfs(1,n)
  {
    // print dist
    cout << dist[i] << " ";
  }
}
int main()
{
  int n, m;
  // n is number of vertices and m number of edges where m>=n always for this case
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); //  edge u to v
    adj[v].push_back(u); //  edge v to u
  }
  bfs(1, n);
  return 0;
}
/*
We make bst using  - https://ncduy0303.github.io/Competitive-Programming/
and Apna college playlist https://www.youtube.com/playlist?list=PLPGzQiibj6TRgF8lrGWrQ4892RgKi9Q4W
*/