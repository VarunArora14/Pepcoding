// https://www.youtube.com/watch?v=8UBwFE8H4Mc&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=5&t=2s
#include <iostream>
#include "vector"
using namespace std;

const int N = 1e5 + 4;

class Edge
{
public:
  int src, nbr, wt;
  Edge(int u, int v, int wt)
  {
    this->src = u;
    this->nbr = v;
    this->wt = wt;
  }
};

vector<Edge *> adj[N];
bool vis[N] = {false};
// pass vector by reference to get the nodes connected
void connected_path(vector<Edge *> adj[], int src, vector<int> &temp_ans)
{
  vis[src] = true; //  important to mark the visited edge true
  temp_ans.push_back(src);
  for (auto i : adj[src])
  {
    if (!vis[i->nbr])
    {
      connected_path(adj, i->nbr, temp_ans);
    }
  }
}

void isConnected(vector<vector<int>> ans)
{
  // Graph considered connected when from 1 node you can reach all the nodes in a bidirectional graph
  // The only thing we have to see if there are more than 1 vector in vector<vector<int> ans
  // as more than 1 means disconnected
  if (ans.size() == 1)
  {
    cout << "Connected graph";
  }
  else
    cout << "diconnected graph";
}

int main()
{
  int n, m;
  // n for vertices and m for edges
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back(new Edge(u, v, wt));
    adj[v].push_back(new Edge(v, u, wt));
  }
  // In CPH judge this case not working but working for terminal
  vector<vector<int>> ans;

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      vector<int> temp_ans = {};
      connected_path(adj, i, temp_ans);
      ans.push_back(temp_ans);
    }
  }
  cout << "\n";
  for (int i = 0; i <= n; i++)
  {
    for (auto j : ans[i])
    {
      cout << j << " ";
    }
    cout << "\n";
  }

  return 0;
}

/*
Print a vector of a vector<Edge*> which stores the nodes which are connected to each other. example -
7 5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

Ans - [[0,1], [2,3], [4,5,6]]
*/