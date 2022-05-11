// https://www.youtube.com/watch?v=PSy0yJQx050&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=4
#include <iostream>
#include "vector"
#include "string"
#include "queue"
#include "climits"
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

// smallest, largest, ceil and floor paths
string spath, lpath, cpath, fpath;
int spathwt = INT_MAX, lpathwt = INT_MIN, cpathwt = INT_MAX, fpathwt = INT_MIN;
// use priority queueto get kth largest as it puts ele based on pq order
priority_queue<pair<int, string>> pq; //  int is wt and string is the kth string ans

// path so far and weight so far
void multisolver(vector<Edge *> adj[], int src, int dest, int criteria, int k, string psf, int wsf)
{
  if (src == dest)
  {
    cout << psf << "@" << wsf << "\n";
    // check at the dest if you have found a smaller wt path and if yes then store it
    if (wsf < spathwt)
    {
      spath = psf;
      spathwt = wsf;
    }
    // check for larger wt now
    if (wsf > lpathwt)
    {
      lpathwt = wsf;
      lpath = psf;
    }
    // ceil path
    if (wsf > criteria && wsf < cpathwt)
    {
      cpathwt = wsf;
      cpath = psf;
    }
    if (wsf < criteria && wsf > fpathwt)
    {
      fpathwt = wsf;
      fpath = psf;
    }
    // check first if priority queue size less than k and if yes then insert
    // the top will always have the largest so instead of wsf use -wsf which will put kth largest on top
    if (pq.size() < k)
    {
      // earlier 50 was not in pq but since it is largest to smallest, 50 at the top
      pq.push({-wsf, psf});
    }
    else
    {
      // changed -wsf < pq.top().first as if -wsf=50 and then top be -48 and not -38
      // The whole point of -wsf and -wsf < pq.top().first is to keep largest ele lowest in queue
      // and kth largest at top
      if (-wsf < pq.top().first)
      {
        pq.pop();
        pq.push({-wsf, psf});
      }
    }
    return;
  }
  vis[src] = true;
  // find neighbours of src
  for (auto i : adj[src])
  {
    if (!vis[i->nbr])
    {
      multisolver(adj, i->nbr, dest, criteria, k, psf + to_string(i->nbr), wsf + i->wt);
    }
  }
  vis[src] = false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back(new Edge(u, v, wt));
    adj[v].push_back(new Edge(v, u, wt));
  }
  int src, dest;
  cin >> src >> dest;

  // criteria for ceil and floor(a number) and k for kth largest
  int criteria, k;
  cin >> criteria >> k;

  // for (int i = 0; i < n; i++)
  // {
  //   for (auto j : adj[i])
  //   {
  //     cout << j->src << ":" << j->nbr << "\n";
  //   }
  //   cout << "\n";
  // }

  string start = to_string(src);

  // printPath(adj, src, dest, start + "");
  multisolver(adj, 0, 6, criteria, k, start + "", 0);
  cout << "smallest path is " << spath << "@" << spathwt << "\n";
  cout << "largest path is " << lpath << "@" << lpathwt << "\n";
  cout << "ceil path is " << cpath << "@" << cpathwt << "\n";
  cout << "floor path is " << fpath << "@" << fpathwt << "\n";
  cout << k << "th  largest path is " << pq.top().second << "@" << -pq.top().first << "\n";
  // minus prefix to change -40 to 40
  // cout << "current priority queue is \n";
  // while (!pq.empty())
  // {
  //   cout << pq.top().second << "@" << pq.top().first << "\n";
  //   pq.pop();
  // }
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
// criteria and k
40 3
*/