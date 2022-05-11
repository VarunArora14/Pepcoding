// https://www.youtube.com/watch?v=DrQ-eTN2v3A&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=3
#include <iostream>
#include "vector"
#include "string"
using namespace std;

const int N = 1e5 + 4;
class Edge
{
public:
  int src, nbr, wt;

  Edge(int src, int nbr, int wt)
  {
    this->nbr = nbr;
    this->src = src;
    this->wt = wt;
  }
};

vector<Edge *> adj[N];
bool vis[N] = {false};

// we have to go from src to dest so we see the neighbours of src and keep going deep recursively till
// true returned
// To printPath, remove the return statements as we store things in string
void printPath(vector<Edge *> adj[], int src, int dest, string psf)
{
  // base case
  if (src == dest)
  {
    // print path if found
    cout << "\n"
         << psf;
    return;
  }

  // don't mark last ele visited to print all paths
  vis[src] = true; //  so that the dest ele can always be visited and we don't mark true for dest again
  for (auto i : adj[src])
  {
    // go to all neighbours of src
    if (!vis[i->nbr])
    {
      // if neighbour not visited then visit them
      string c = to_string(i->nbr);
      printPath(adj, i->nbr, dest, psf + c);
    }
    // we need to have vis[] as the graph is bidirectional so it can run infinite and give stack overflow
  }
  vis[src] = false;
  // after the loop make the vis[src] as false as you have gone through that path completely by now
  // and inorder to print other paths that have same indices like old paths with some differences
  // you have to unmark indices you have gone through so they can visit them again

  // return false if nodes visited or no next nodes or not found dest
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
    // create a pointer to the edge objects and not pass them
    adj[u].push_back(new Edge(u, v, wt));
    adj[v].push_back(new Edge(v, u, wt));
  }
  int src, dest;
  cin >> src >> dest;
  // print the adjacency list

  // the i<7 is for the total number of vertices=n
  for (int i = 0; i < n; i++)
  {
    for (auto j : adj[i])
    {
      cout << j->src << ":" << j->nbr << "\n";
    }
    cout << "\n";
  }

  string start = to_string(src);

  printPath(adj, src, dest, start + "");
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