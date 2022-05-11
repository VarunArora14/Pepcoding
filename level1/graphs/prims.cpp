// https://www.youtube.com/watch?v=Vw-sktU1zmc&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=16
// Time Complexity: O(mlogn)
#include <iostream>
#include "vector"
#include "queue"
using namespace std;

typedef pair<int, int> iPair;
const int N = 100;

vector<iPair> adj[N];
bool vis[N] = {false};

void prims(int n, int s = 0)
{
  int cost = 0;
  // min heap having the smallest ele on top
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
  vis[s] = true;
  cout << s << " ";
  for (auto [u, d] : adj[s]) //  adhacency list has stored in order vertex and distance
  {
    // but priority queue stores distance first as we need to order them on the basis of distance
    if (!vis[u])
      pq.push({d, u});
  }
  // Now we have all the neighbours of starting ele in the priority queue from smallest to largest weight
  while (pq.size())
  {
    auto [d, u] = pq.top();
    pq.pop();
    // checking if not visited before printing
    if (!vis[u])
    {
      vis[u] = true;
      cost += d;
      cout << u << " ";
      // this is the smallest distance ele and whole leading to the path being printed

      // check for neighbours of u now
      for (auto [v, w] : adj[u])
      {
        // checking for repeated node that has been seen previously seen as neighbour of any other node
        if (!vis[v])
        {
          pq.push({w, v});
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      cout << "MST not possible";
      exit(0);
    }
    // if any i not visited it means MST not possible
  }
  cout << "\n"
       << cost;
  // this is the cost of the path
}
int main()
{
  int n, m; //  n for nodes and m for edges
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  prims(n);
  return 0;
}
/*
Given a set of vertices and length btw them, find the minimum length required connecting all together
First we learn about MST. MST is a subgraph, one which looks like a tree, all components connected driectly or indirectly and is acyclic.
It is also spanning(meaning it has all the vertices). There are many spanning trees, Minimum Spanning Tree is one which has edges sum minimum.
@ algorithms are for MST - Prims and Kruskal, we study here prims.
Prims is like Dijkstra and uses priority queue and is greedy method
Start from a node, add it's neighbours in priority queue marking the first ele as visited and then in loop go through the
neighbours of pq.top(), if not visited then visit them and add the neighbours of this node to pq if not visited.
Here we maintain 2 visited checks especially inner one to avoid adding repeated node to the priority queue and outer one to
for printing and maintaing the cost.

7 8
0 1 10
0 3 40
1 2 10
2 3 10
3 4 2
4 5 3
5 6 3
4 6 8
*/