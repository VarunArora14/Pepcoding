#include <iostream>
#include "vector"
using namespace std;

const int N = 1e5 + 4;
vector<int> adj[N], dist;
bool vis[N] = {false}; //  max nodes with their val=N and not more

// keep visiting the first children you see for the node and keep going down
// for all nodes
void dfs(int v)
{
  vis[v] = true;
  cout << v << " ";
  for (auto i : adj[v])
  {
    if (!vis[i])
    {
      dfs(i);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      dfs(i);
    }
  }
  return 0;
}

/*
7 7
1 2
2 3
2 5
3 4
1 6
1 7
*/