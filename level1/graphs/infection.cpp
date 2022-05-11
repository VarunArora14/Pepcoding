// https://www.youtube.com/watch?v=3A1XJbRs_6A&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=14
#include <iostream>
#include "vector"
#include "queue"
using namespace std;

const int N = 1e3 + 4;
vector<int> adj[N];
bool vis[N] = {false};

// create GraphPair to associate vertex with the time
class GraphPair
{
public:
  int v;
  int t;
  GraphPair(int v, int t)
  {
    this->v = v;
    this->t = t;
  }
};

void infection(vector<int> adj[], int time, int src)
{
  int inf[N] = {0}; //  infection time
  queue<GraphPair *> q;
  int c = 0;
  // queue of pair as each item will have both vertex value and the time
  q.push(new GraphPair(src, 1));
  // while loop till either queue empty or the front node has time value as the max time passed
  while (!q.empty())
  {
    GraphPair *temp_pair = q.front();
    // earlier we printed here
    // The reason we have 2 vis[] checks is bcos we can have cycles that may ruin the code
    // if we go to same node without checking. Example, in inner loop is 4 and 5 are pushed then we first take 4 and
    // see it's neighbours. If 1 turns out to be 5, we push again with time+1. Now the queue has 2 "5" with t and t+1 time
    // inorder to remove the redundancy,we check everytime at start if visited or not.
    if (!vis[temp_pair->v])
    {
      vis[temp_pair->v] = true;
      inf[temp_pair->v] = temp_pair->t; //  note the time of infection and c++ for adding infected nums
      if (temp_pair->t > time)
      {
        break;
      }
      // don't increase count and simply break; At this point, you would have marked the next as infected after time
      // but not added their count
      c++;
    }

    q.pop();
    // go through the neighbours if not visited and infect them by marking true and change time
    for (auto i : adj[temp_pair->v])
    {
      if (!vis[i])
      {
        // vertex would be i as adj[] has list of neighbour vertices in int and time would be curr time+1
        q.push(new GraphPair(i, temp_pair->t + 1));
      }
    }
  }
  cout << "Infected people are " << c;
}
int main()
{
  int n, m, t; //  n=nodes, m=edges, t=time
  cin >> n >> m >> t;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int src;
  cin >> src;
  infection(adj, t, src);
  return 0;
}
/*
Given a time frame starting from t=1 to n, find how many get the infection
With every second, neighbour of the node gets the infection if not infected.

Check for all vertices as the graph may be broken and infection might not go with all
7 8 3
0 3
0 1
1 2
2 3
3 4
4 5
4 6
5 6
6
// 6 is starting point
*/