// https://www.youtube.com/watch?v=sD0lLYlGCJE&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=15
// Time Complexity: O(n+mlogn)
#include <iostream>
#include "vector"
#include "climits"
// #include "string"
#include "queue"

using namespace std;
typedef pair<int, int> iPair;
// change name of pair<int,int> to use it at many places

// https://ncduy0303.github.io/Competitive-Programming/Graphs/Shortest%20Paths/Dijkstra.cpp

const int N = 100;
const int INF = 1e9;
vector<iPair> adj[N];
vector<int> dist;

void dijkstra(int src, int n)
{
  // priority queue of pair of int,int
  // priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
  // greater comparator will put greater on top but we want smallest or less<iPair> which is default
  dist.assign(n + 1, INT_MAX);
  // we wan to implement min heap so we use below declaration with greater<iPair>
  // which is a comparator
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
  dist[src] = 0;
  pq.push({0, src}); //  vector of pair<int,int> with greater comparator

  while (!pq.empty())
  {
    auto [d, u] = pq.top(); //  assign the top priority queue as pair of distance and vertex
    pq.pop();
    // the below if condition can be removed
    if (d > dist[u]) //   we only compute further if distance is smaller, base case has both d and dist[v] as 0
      continue;
    // no point continuing if distance greater than dist[u] already found
    for (auto [v, w] : adj[u]) //  adj[u] has 2 values vertex v and w, the distance from u to v
    {
      if (dist[v] > dist[u] + w) //  if dist[u] + w is smaller than current dist then assign it. It works as visited vector instead of extra one
      {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v}); //  pushing the distance and our new vertex v
      }
    }
  }
}

// Reason for vis condition is same as before that for cyclic cases same element can be more than
// 2 times in the pq so check both in loop and outside before loop. Make vis[]=true only once in outer
// before the print statement.
// if (vis[temp->v])
//   continue;

// vis[temp->v] = true;
// cout << temp->v << "via" << temp->psf << "@" << temp->wsf;

// for (auto i : adj[temp->v])
// {
//   if (!vis[i->nbr])
//   {
//     pq.push(new GraphPair(i->nbr, temp->wsf + i->wt, temp->psf + to_string(i->wt)));
//     // add new num which is neighbour of i going in loop, change weight to
//     // edge weight plus weight till now and path so far + current node added
//   }
// }
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    // instead of visited vector we use dist for checking the value
  }
  dijkstra(0, n);
  for (int i = 0; i < n; i++)
  {
    cout << dist[i] << " ";
  }
  return 0;
}

/*
Here we have to find shortest path in terms of weight not edges. For finding shortest path
in terms of edges, do bfs as it moves in radius.
For weight, we use dijkstra algorithm inside which we use (min) priority queue which stores the min
weight at the top of the queue for element to be opped and to visit it's neighbours.
The reason for using it is that dijkstra is a greedy aglorithm where we find the smallest weight and
keep moving forward to non-visited nodes.
For the last node visited first, mark it and if other elements left in priority queue that have been visited from
other paths are left.

It is almost same as bfs except here we use priority queue instead of queue

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