// https://www.youtube.com/watch?v=GHnC5qHexsk&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=13
#include <iostream>
#include "vector"
#include "string"
#include "queue"
using namespace std;

class Edge
{
public:
  int src, nbr;
  Edge(int src, int nbr)
  {
    this->src = src;
    this->nbr = nbr;
  }
};

// we can do without pair, here it is just for illustration purposes
class GraphPair
{
public:
  int v;
  string psf;
  GraphPair(int v, string psf)
  {
    this->psf = psf;
    this->v = v;
  }
};

const int N = 1e5 + 4;
vector<Edge *> adj[N];
bool vis[N] = {false};

// void bfs(int n)
// {
// }

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(new Edge(u, v));
    adj[v].push_back(new Edge(v, u));
  }
  int src;
  cin >> src; //  the starting point of bfs
  queue<GraphPair *> q;
  q.push(new GraphPair(src, to_string(src)));
  while (!q.empty())
  {
    GraphPair *temp_pair = q.front();
    q.pop();
    vis[temp_pair->v] = true; //  mark first ele true
    cout << temp_pair->v << "@" << temp_pair->psf << "\n";
    for (auto i : adj[temp_pair->v])
    {
      // see the adjacent elements and if not visited then visit them by using i->nbr
      if (!vis[i->nbr])
      {
        vis[i->nbr] = true;
        q.push(new GraphPair(i->nbr, temp_pair->psf + to_string(i->nbr)));
        // here what is happening is that if temp_pair->v=1 meaning vertex 1, we check
        // the neighbours
      }
    }
  }
  return 0;
}
/*
7 8
0 1
0 3
1 2
2 3
3 4
4 5
4 6
5 6
2
*/