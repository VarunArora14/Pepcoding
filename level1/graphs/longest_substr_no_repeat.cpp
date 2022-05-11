// https://www.youtube.com/watch?v=9Kc0eZBGL1U
#include <iostream>
#include "map"
using namespace std;

int sol(string str)
{
  int ans = 0;
  int i = -1, j = -1;
  map<char, int> m;

  while (true)
  {
    bool f1 = false;
    bool f2 = false;
    // acquire
    while (i < str.length())
    {
      f1 = true;
      char ch = str[i];
      m[ch]++;
      if (m[ch] == 2)
      {
        break;
      }
      else
      {
        int len = i - j;
        if (len > ans)
          ans = len;
      }
    }
    // release
    while (j < i)
    {
      f2 = true;
      j++;
      char ch = str[j];
      m[ch]--;
      if (m[ch] == 1)
      {
        break;
        // it is valid now
      }
    }

    // if both f1 and f2 false means going through none loop so exit
    if (f1 == false && f2 == false)
    {
      break;
    }
  }
  return ans;
}

int main()
{

  return 0;
}
/*
Here the idea is to keep adding the strings till we have invalid and then keep popping the invalid ele till it becomes valid again
Remove the ele from start like queue and not like stack from top
Remove ele from start which are inalid going forward in idx. If visited, then move next ele and add to hash map.
Keep adding till valid and if invalid, remove the first ele
*/