#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "map"
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;
using namespace chrono;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void sol_map(string str)
{
  map<char, int> m1;

  int len = str.length();
  int maxlen = INT_MIN;
  int i = 0; // i is start, j is end
  for (int j = 0; j < len; j++)
  {
    // acquire till valid
    char ch = str[j];
    if (m1.find(ch) == m1.end())
    {
      maxlen = max(maxlen, j - i + 1);
      m1[ch]++;
    }
    else
    {
      m1[ch]++; // increase first so that we dont remove it at m1[ch]=1
      // keep removing ele from i index till m1[ch]==1
      while (m1[ch] > 1)
      {
        // reduce the map value for str[i] if more than 1 else erase
        if (m1[str[i]] > 1)
          m1[str[i]]--;
        else
          m1.erase(str[i]);

        i++; // increase i as we increase the starting idx
      }
    }
  }
}

int main()
{
  string str;
  cin >> str;
  return 0;
}

/*
Here the idea is to acquire the valid strings with no non-repeating till it becomes invalid and at that position, keep removing the ele
from the start till it becomes valid again and go forward. For each valid, note the i and j values.

Acquire till it becomes invalid
Release till it becomes valid again

aabcdb
*/