// https://www.youtube.com/watch?v=nUgp0RG57wQ&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=9
#include <iostream>
#include "vector"
#include "string"
#include "unordered_set"
using namespace std;

const int N = 1e5 + 4;
// bool vis[N] = {false}; use unordered_set vis to store  the values that have been visited use find() and
// insert, remove func
unordered_set<int> vis = {};
vector<int> adj[N];

// The psf string contains the items that have been visited till you
// and the visited contains the items that have been visited before you
// For this, rather than using bool array we use map and compare the graph size with the map size as
// base case
// The start_src is needed to check hemilton cycle when last edge points to the first edge

void hamilton(int n, int src, vector<int> adj[], string psf, int start_src)
{
  // mark the curr node as true

  // mark true above as we want 6 to be marked true for all visited n to be marked true
  // check the base case as all nodes visited to print and not src==dest

  // if we have gone through n-1 edges and then after for loop we go to the func
  // recursively then that node value ias added to the psf string and now we have to
  // print the string because psf gets the nodes visited till now while the vis set
  // has items visited before you the curr node. If we call 6 in func, then 6 in psf
  // but not in vis set.
  if (vis.size() == n - 1)
  {
    cout << psf;
    // check if hamilton cycle or path
    bool isCycle = false;
    for (int i : adj[src])
    {
      if (i == start_src)
      {
        isCycle = true;
        break;
      }
    }
    if (isCycle)
      cout << "*";
    else
      cout << ".";
    cout << "\n";
    return;
  }

  vis.insert(src);
  // dont forget to insert as unusual end of program
  for (auto i : adj[src])
  {
    // put only when not found meaning vis has not the element
    if (vis.find(i) == vis.end())
    {
      string c = to_string(i);
      // hamilton_path(n,)
      hamilton(n, i, adj, psf + c, start_src);
    }
  }
  // unvisit by erasing the element

  vis.erase(vis.find(src)); //  erase element at position and not the element
}

int main()
{
  int n, m; //  n for vertices and m for edges
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  hamilton(n, 0, adj, "0", 0);

  // starts with 0 so string and src is

  return 0;
}
/*
Here you have to print the hamilton cycle and hamilton path.
Hamilton cycle is in the path where all nodes visited once, the last node points to the first node
Hamilton path is the path where all nodes are visited once(like print_path)

This ques very close to print all path where we visit all neighbours and unvisit for other paths except the
base case where rather than src==dest, check if all vertices visited.
For the path to be printed we have to pass string psf to print the path.

7 9
0 1
0 3
1 2
2 3
3 4
2 5
4 5
4 6
5 6

*/