// https://www.youtube.com/watch?v=EmpwQ4C6WJs&list=PL-Jc9J83PIiHhXKonZxk7gbEWsmSYP5kq&index=3
#include <iostream>
#include "vector"
using namespace std;

bool brute(vector<vector<int>> vec, int n, int m, int target)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vec[i][j] == target)
        return true;
    }
  }
  return false;
}

// time complexity: O(m+n)
bool optimal(vector<vector<int>> vec, int n, int m, int target)
{
  // start at i=0, j=m-1
  int i = 0, j = m - 1;
  while (j >= 0 && i <= n - 1)
  {
    if (vec[i][j] == target)
      return true;
    else if (vec[i][j] < target)
      i++;
    else
      j--;

    // if curr ele smaller than target then move down, if larger then move left bcos of the way matrix is
  }
  return false;
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

/*
3 3 9

1 3 5
7 8 13
16 20 21
*/