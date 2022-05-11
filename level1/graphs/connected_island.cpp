// https://www.youtube.com/watch?v=ErPZFxugYkI&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=7
#include <iostream>
#include "vector"
using namespace std;

const int N = 1e5 + 4;
class Edge
{
public:
  pair<int, int> src, nbr;
  // pair as we need indices to be connected to where first is row and 2 columns

  Edge(pair<int, int> src, pair<int, int> nbr)
  {
    this->src = src;
    this->nbr = nbr;
  }
};

bool vis[20][20] = {false};
// First we have to make a way to store data in graph or adjacency list where we have vector of edges pointers
vector<vector<Edge *>> adj;
// rather than vector of vertices of max size create vector of vector<Edge*>

void island(int a[][20], int i, int j, int n, int m)
{
  // smart base case to check if water is there, we go out of board or if visited then simply return
  if (a[i][j] == 1 || i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == true)
    return;

  // here first make the vis[i][j] as true and then check its neighbours which are left, right up and down
  vis[i][j] = true;
  // call the neighbours recursively
  island(a, i - 1, j, n, m); //  up
  island(a, i, j - 1, n, m); //  left
  island(a, i + 1, j, n, m); //  down
  island(a, i, j + 1, n, m); //  right
  // since function calls not smart make base case
}

int main()
{
  int a[20][20] = {0};
  int n, m;
  cin >> n >> m;
  // here n and m are the rows and columns of array
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    // create a count variables which has the sum of times the island function which is similar to connected_graph function is called
    // as we care about the number of times for islands and not their island elements
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 0 && vis[i][j] == false)
      {
        island(a, i, j, n, m);
        count++;
      }
    }
  }
  cout << "\n"
       << count;
  return 0;
}
/*
In order to find the islands, we make a connected graph implementation where for each index we find if it has 0 on it's
left, right top or bottom and if found then add to the vector<int> list and return
The number of vector<int> would be the total islands in the vector<vector<int>> ans,  list.

ex:
8 8
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 0 0 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
*/
