// https://youtu.be/SnZ2SQARTVI
#include <iostream>
#include "vector"
#include "set"
using namespace std;

const int inf = 1e7;

int main()
{
  int n, m;
  cin >> n >> m;                               //   n for nodes and m for edges
  vector<int> dist(n + 1, inf);                //  create distance vector and assign all the edges distance as inf
  vector<vector<pair<int, int>>> graph(n + 1); // pair as weight also included
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  int src;
  cin >> src;
  dist[src] = 0;
  set<pair<int, int>> s;
  // {}
  s.insert({0, src}); //  insert a pair of distance of source and source as the graph(n+1) is n vectors of graph[i]
  // where for each graph[i] we have a vector of pair of {distance, node} (node to which it is pointing to)
  // Initially src->src and dist=0 is the starting point and then we look for neighbours of src

  // Note - set implements red black tree meaning it's elements are ordered. Since we have pair, it loos at the first element of the
  // pair which here is distance and so sorts the set based on smallest distance where s.begin() is the smallest distance pair which we use
  // for our dijkstra
  while (!s.empty())
  {
    auto x = *(s.begin()); //  make reference to s.begin() using * and remove the ele
    s.erase(x);
    for (auto i : graph[x.second])
    {
      // go through neighbours of x by using x.second as x.first was for distance and compare the prev distance
      if (dist[i.first] > dist[x.second] + i.second)
      {
        // check distance greater than
      }
    }
  }
  return 0;
}