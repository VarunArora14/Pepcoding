// https://www.youtube.com/watch?v=aGMzcfWsdWE&list=PL-Jc9J83PIiHhXKonZxk7gbEWsmSYP5kq&index=1
#include <iostream>
#include "algorithm"
#include "vector"
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
  if (a[0] == b[0])
  {
    if (a[1] == b[1])
    {
      return a[2] < b[2]; // return ascending maths marks
    }
    else
    {
      // return descending chem marks
      return a[1] > b[1];
    }
  }
  return a[0] < b[0];
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> inp(n, vector<int>(3));
  // 2d vector of size nX3
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> inp[i][j];
    }
  }

  sort(inp.begin(), inp.end(), compare);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << inp[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}

/*
5
9 3 15
5 4 10
9 3 11
8 7 13
5 6 12

ans=>
5 6 12
5 4 10
8 7 13
9 3 11
9 3 15
*/