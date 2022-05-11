// https://www.youtube.com/watch?v=t0r04fYdT7U&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=1
#include <iostream>
#include "vector"

const int N = 1e5 + 4;

using namespace std;

class Edge
{
public:
  int src, nbr, wt;
  // source, neighbour and weight
  Edge(int src, int nbr, int wt)
  {
    this->nbr = nbr;
    this->src = src;
    this->wt = wt;
  }
};
vector<Edge *> adj[N];
bool vis[N] = {false};
// if problem the pass by reference

// recursive solution similar to flood fill
// vector<int> ans;
// make adj[] not just adj as
bool hasPath(vector<Edge *> adj[], int src, int dest)
{
  // base case when src==dest
  if (src == dest)
  {
    return true;
  }
  // putting vis[src]=true before base case would make other paths to
  // dist not possible as it would be considered visited
  vis[src] = true;
  // check if any of your neighbour has path to dest
  // check the neghbours of src and recursively call the function till it returns true
  for (auto i : adj[src])
  {
    // visit only if neighbour not visited
    if (!vis[i->nbr])
    {
      bool isTrue = hasPath(adj, i->nbr, dest);
      if (isTrue)
      {
        return true;
      }
    }
  }
  return false;
}
int main()
{
  int n, m;
  // n for vertices
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    // Edge edge(u, v, wt), edge2(v, u, wt); //  create 2 edges from u to v and v to u
    // adj[u].push_back(edge);
    // adj[v].push_back(edge2);
    adj[u].push_back(new Edge(u, v, wt)); //  passing reference to object here not value
    adj[v].push_back(new Edge(v, u, wt));
  }

  // enter start and end point
  int src, dest;
  cin >> src >> dest;

  cout << hasPath(adj, 0, 6);
  cout << "\n";
  for (int i = 0; i < 7; i++)
  {
    for (auto j : adj[i])
    {
      cout << j->src << ":" << j->nbr << "\n";
    }
    cout << "\n";
  }

  return 0;
}
/*
// vertices and edges
7 8
0 3 40
0 1 10
1 2 10
3 2 10
3 4 2
4 5 3
4 6 8
5 6 3
// source and destination
0 6
*/