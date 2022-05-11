// https://www.youtube.com/watch?v=ZBhZ1DXGrhA&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=14
#include <iostream>
#include "vector"
#include "queue"
using namespace std;

const int N = 1e5 + 4;
vector<int> adj[N];
bool vis[N] = {false};
// using int array of visited to mark the level visited or simply use dist
vector<int> dis;

bool Bipartite(vector<int> adj[], int src)
{
  dis.assign(10, -1);
  // without assign(), we can't use dis[idx] as it ends the program
  queue<int> q;
  q.push(src);
  vis[src] = true;
  dis[src] = 0;

  while (!q.empty())
  {
    int val = q.front();
    // rather than int, use Edge and pass level as parameter with value and then compare dist[val] and val->level
    // if they are not same means graph non-bipartite
    q.pop();
    // use adj[val] and not src as we need for each level and not just src neighbours
    for (auto i : adj[val])
    {
      // visit if not visited
      if (!vis[i])
      {
        vis[i] = true;
        q.push(i);
        dis[i] = dis[val] + 1; //  make 1 level more than prev neighbour
      }
      else
      {
        // work to do
      }
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

  // Apply get connected component code here where you go through all the vertices as broken graphs exist
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      // for each vertex i, check for bipartite
      bool isBipartite = Bipartite(adj, i);
      if (!isBipartite)
      {
        cout << "false";
        return;
      }
    }
  }
  cout << "true";
  return 0;
}

/*

A graph is called bipartite if it can be made into 2 sets which are mutually exclusive and exhaustive
such that all edges are across set meaning no 2 edges meaning not within set.
Example
0 1
0 3
1 2
2 3

Two sets are S1 and S2. S1 has [0,2] and S2 has [1,3]. They are mutually exclusive as they don't have intersection
and are exhaustive as they combine to make all the vertices.
Edges are [0,1], [0,3],[1,2],[2,3] which are all across set

Mutually exclusive means no common vertice and exhaustive means both add to make all vertices.

The easy way to find it is that if you have a cycle of odd length then it cannot be bipartite. Or there should not
exist a cycle because every non-cyclic graph is bipartite.
In a non-cyclic graph, go bfs and put every bfs row in alternate set to see if the condition holds true.

Acyclic graphs are bipartite. Cyclic graphs with even number of cycles are also bipartite.
Cyclic graphs with odd number of nodes is non-bipartite.

The reason is if you do bfs of say a triangle graph of edges {[0,1], [1,2], [0,2]}
then you do bfs for putting ele in sets. Now, starting with 0, put 0 in S1 and it's neighbours in S2 to make it across edge.
S1 has [0] and S2 has [1,2]. At this point the queue has [1,2] and 0 has been visited. Now, when we go at 1, we visit 1
and then add it's non visited neighbour to S1 which is now 2. So S1 now has [0,2] and S2 has [1,2]. Since they have
common members, they are non-bipartite.
Because of odd length cycle, "2" in both S1 and S2.
"2" is in S2 as it is connected to "0" as it's neighbour but at same time it is in S1 as it is connected with "1"
*/