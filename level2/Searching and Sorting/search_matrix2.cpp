#include <iostream>
#include "vector"
using namespace std;

bool optimal_try(vector<vector<int>> vec, int n, int m, int target)
{
  // find the mid point of the matrix and compare
  int i, j;
  i = n / 2;
  j = m / 2;
  int start_i = 0, start_j = 0, end_i = n - 1, end_j = m - 1;
  // change condition
  while (start_i < end_i && start_j < end_j)
  {
    int i = (start_i + end_i) / 2;
    int j = (start_j + end_j) / 2;
    if (vec[i][j] == target)
      return true;
    else if (vec[i][j] >= target)
    {
      end_i = i - 1;
      end_j = j - 1;
    }
    else
    {
      start_i = i;
      start_j = j;
    }
  }
  return false;
}

bool optimal(vector<vector<int>> vec, int n, int m, int target)
{
  int i = 0, j = m - 1;
  while (i <= n - 1 && j >= 0)
  {
    if (vec[i][j] == target)
      return true;

    else if (vec[i][j] > target)
      j--;
    else
      i++;
  }
}

int main()
{

  int n, m, target;
  cin >> n >> m >> target;

  vector<vector<int>> vec(n, vector<int>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> vec[i][j];
    }
  }
  cout << optimal(vec, n, m, target);
  return 0;
}
