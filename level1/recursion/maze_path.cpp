// https://www.youtube.com/watch?v=ox3TswFFKDI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=401
#include <iostream>
#include "vector"
#include "string"
using namespace std;

vector<string> maze(int sr, int sc, int dr, int dc)
{
  // base case when sr==dr and sc==dc. At that point we simply have to return something so that
  // it backtracks from the stack and stores and prints the path
  if (sr == dr && sc == dc)
  {
    vector<string> base;
    base.push_back("");
    return base;
  }

  vector<string> rpath, dpath, paths;
  // note - we need to move right only if sr<dr and sc<dc
  if (sc < dc)
    rpath = maze(sr, sc + 1, dr, dc); //  moves right
  if (sr < dr)
    dpath = maze(sr + 1, sc, dr, dc); //  moves down

  // now push their value "r" and "d" (for right and down) in the vector<string>
  for (auto i : rpath)
  {
    paths.push_back("r" + i);
  }
  for (auto i : dpath)
  {
    paths.push_back("d" + i);
  }
  return paths;
}
int main()
{
  int n = 3, m = 3;
  // n rows and m columns
  vector<string> ans = maze(0, 0, n - 1, m - 1);
  for (auto i : ans)
  {
    cout << i << "\n";
  }

  return 0;
}
/*
Maze where you can only go right or down, find number of ways to reach [n-1,m-1]
You can only go right or down

Base case when you are at that position, return 1
Since it can go right and down, the exceptions would arise when either i==m or j==n
*/