// https://www.youtube.com/watch?v=qbQq-k75bcY&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=12
#include <iostream>
#include "vector"
#include "queue"
#include "string"
using namespace std;

class Edge
{
public:
  int src, nbr;
  Edge(int src, int nbr)
  {
    this->nbr = nbr;
    this->src = src;
  }
};

class GraphPair
{
public:
  int v;
  string psf;
  GraphPair(int v, string psf)
  {
    this->v = v;
    this->psf = psf;
  }
};

const int N = 1e5 + 4;
vector<Edge *> adj[N];
bool vis[N] = {false};
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

  // If while doing bfs we go to a node again, then it means it had more than 1 path to be reached meaning cycle

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
    }
    // traverse
  }

  queue<GraphPair *> q;
  q.push(new GraphPair(src, to_string(src)));
  // src and string src as the first elements, now go through the others by bfs
  vis[src] = true;
  while (!q.empty())
  {
    // [0,"0"]
    GraphPair *temp_pair = q.front();
    cout << temp_pair->v << "@" << temp_pair->psf << "\n";
    q.pop();
    // go through adjacency list of 0 to see connected members and if not visited, mark visited
    // and in queue push pair of i->nbr(which is the node connected to src in the loop which let's say is 1)
    // and to the second parameter do temp_pair->psf + to_string(i->nbr)
    for (auto i : adj[temp_pair->v])
    {
      if (i->nbr == src)
      {
        cout << "cycle found";
        exit(0);
      }
      if (!vis[i->nbr])
      {
        // if not visited neighbour of src, then mark and push
        vis[i->nbr] = true;
        q.push(new GraphPair(i->nbr, temp_pair->psf + to_string(i->nbr)));
      }
    }
  }
  return 0;
}

/*
0 1
0 3
1 2
2 3

0 1
1 2
2 3

if we start from 0, then we have 2 paths with bfs - "01" and "03"
then we have "012" and "032". Two paths to 2 means a cycle exists

Here we also have to apply connected_path concept as graph may be broken and not fully connected
*/