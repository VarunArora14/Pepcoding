// https://www.youtube.com/watch?v=W6cT68K7Hls&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=400
#include <iostream>
#include "vector"
#include "string"
using namespace std;

vector<string> stair_path(int n)
{
  // base cases for n=0 and n<0, will come later
  if (n == 0)
  {
    // base case when we are at the position, return vector<string> with "" and if n<0, return vector<string>
    // without anything in it as then the loop will not run for that pathx(x is num)
    vector<string> base;
    base.push_back("");
    return base;
  }
  else if (n < 0)
  {
    return {}; //  return empty vector as list initalization from C++ 11
  }
  vector<string> path1, path2, path3, paths;
  path1 = stair_path(n - 1);
  path2 = stair_path(n - 2);
  path3 = stair_path(n - 3);

  // for each path - path1, path2, path3, create a new vector<string> path and push path.push_back("1"+path[i])
  //  we can do vec.push_back("value"+vec2[i]) without any problem but remember to create new
  // vector<string> for each as we don't have to print substrings but total paths to n
  for (auto i : path1)
  {
    paths.push_back("1" + i);
  }
  for (auto i : path2)
  {
    paths.push_back("2" + i);
  }
  for (auto i : path3)
  {
    paths.push_back("3" + i);
  }
  return paths;
}
int main()
{
  int n = 5;
  vector<string> ans = stair_path(n);
  for (auto i : ans)
  {
    cout << i << "\n";
  }
  return 0;
}
/*
Find stairs path using recursion where u can go 1 or 2 or 3 stairs down from nth stair, print all the ways

The main problem we had was to figure out -
1. How to print the paths
2. how to calc for 3 at same time

For 2nd, we maintained 3 vector<string> each having a recursive call
*/