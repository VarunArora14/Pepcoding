// https://www.youtube.com/watch?v=4_0l-QydwzI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=129
#include <iostream>
#include "stack"
using namespace std;

void solve(string str)
{
  stack<int> s;
  int num = 1;
  // starting min at 1
  for (char c : str)
  {
    if (c == 'd')
    {
      s.push(num);
      num++;
      // increase num everytime u push anything
    }
    else
    {
      // for i
      s.push(num);
      num++;

      while (!s.empty())
      {
        cout << s.top() << " ";
        s.pop();
      }
    }
  }
  s.push(num);
  // push num outside once as 1 extra ele and then till the stack is not empty, keep printing the num
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
}
int main()
{
  string s = "ddiddd";
  solve(s);
  return 0;
}
/*
For a given set of d's and i's do such that arrangement is as follows -
for i, increasing order = 12
for d - decreasing order =21
for a combination ddidd = 321654

The way to do it is keep pushing d till no i comes keeping a counter of d's and if no i, then counter-- and print val
if i comes then keep popping
*/
