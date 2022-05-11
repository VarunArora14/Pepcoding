// https://www.youtube.com/watch?v=_q4hA01ZcVQ&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=8
#include <iostream>
#include "vector"
using namespace std;

const int N = 1e5 + 4;
vector<int> adj[N];
bool vis[N] = {false};

// pass by reference so change can be stored and then added to ans
// If not passed by reference then empty vector
void connected(int src, vector<int> adj[], vector<int> &temp_ans)
{
  vis[src] = true;
  temp_ans.push_back(src);
  for (auto i : adj[src])
  {
    if (!vis[i])
    {
      connected(i, adj, temp_ans);
    }
  }
}

int main()
{
  int n, m;
  // n for vertices and m for edges
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // going through each node and then checking if not visited, visit and find the connected components
  // for their num. We need vector<vector<int>> for connected nodes and have a function returning vector<int>
  // to store the nodes
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
  {

    if (!vis[i])
    {
      vector<int> temp_ans = {};
      connected(i, adj, temp_ans);
      ans.push_back(temp_ans);
    }
  }
  for (auto i : ans)
  {
    cout << "[";
    for (auto j : i)
    {
      // i is vector<int>
      cout << j << ",";
    }
    cout << "]\n";
  }

  // have 2 loops, outer from i to n-1 and inner i+1 to n-1
  // vector<int> num;
  // for (vector<int> i : ans)
  // {
  //   num.push_back(i.size());
  // }
  // cout << "\nThe total sum is ";
  // int sum = 0;
  // for (int i = 0; i < num.size() ; i++)
  // {
  //   for (int j = i + 1; j < num.size(); j++)
  //   {
  //     sum += num[i] * num[j];
  //   }
  // }
  // cout << sum;
  int sum = 0;
  // for i=2, j will be 3 so loop will not run
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = i + 1; j < ans.size(); j++)
    {
      int count = ans[i].size() * ans[j].size();
      sum += count;
    }
  }
  cout << sum;

  return 0;
}
/*
7 5
0 1
2 3
4 5
5 6
4 6

Here you have pairs like before [[0,1], [2,3], [4,5,6]]
From these groups namely c1, c2 and c3, create pairs such that those 2 ele do not belong to the same
group. The ways are - c1c2, c1c3, c2c3
And for c1c2, ways=4, for c2c3, ways=6, for c1c3, ways=6
So the sum is 6+6+4=16. You have to print the sum

Inorder to find the sum we need to find the num of nodes like c1, c2 and c3 length
and then in loop have sum variable adding c1c2 c1c3 and then c2c3.
*/