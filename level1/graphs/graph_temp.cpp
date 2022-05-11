#include <iostream>
#include "vector"
#include "string"
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

const int N = 1e5 + 4;
vector<int> adj[N];
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
  int src;
  cin >> src;
  return 0;
}