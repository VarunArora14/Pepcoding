// https://www.youtube.com/watch?v=bit4Jn-ZoyQ&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=1
#include <iostream>
#include "map"
#include "unordered_map"
using namespace std;

int main()
{
  int n;
  cin >> n;
  map<string, string> m;
  for (int i = 0; i, n; i++)
  {
    string u, v;
    cin >> u >> v;
    m[u] = v;
  }
  return 0;
}
/*
Here we use the change and return startegy, we change ourself and return then change+1 including the curr node
*/