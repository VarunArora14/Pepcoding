#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void sol(string str1, string str2)
{
  string ans = "";
  map<char, int> m2; // for str2
  for (auto i : str2)
    m2[i]++;

  int count = 0, desired = str2.length(), i = 0, j = 0, ans = INT_MAX; // i and j will form the substring
  map<char, int> m1;
  while (true)
  {
    // loop till either of the fns run
    bool f1 = false, f2 = false;

    // map for the first string. Traverse till either a substring has all of str2 j tll end of str1

    // acquire the elements
    while (j < str1.length() && count < desired)
    {
      char ch = str1[i];
      m1[ch]++;
      i++;

      if (m1[ch] <= m2[ch])
      {
        count++; // we have found a valid one
      }
      f1 = true;
    }

    // collect ans and release the elements
    while (i < j && count == desired)
    {
      // i for start and j for end of substring, idea is to keep removing till important ele gets removed and then we move forward in above while loop
      // before that we collect and store our string so that we have a value
      string temp = str1.substr(i, j);
      if (ans == "" || temp.length() < ans.length())
        ans = temp;

      // release the ith ele and check if m1[ch]<m2[ch]
      i++; // as i at prev ele
      char ch = str1[i];
      // release from m1
      if (m1[ch] == 1)
        m1.erase(ch);
      else
        m1[ch]--;

      // check if m1[ch]<m2[ch]
      if (m1[ch] < m2[ch])
        count--;

      i++;       // so that at start we remove 0th ele an not 1st
      f2 = true; // flag2 if we enter this loop
    }

    if (!f1 && !f2)
      break;
  }
  cout << "ans is " << ans;
}

int main()
{
  string str1, str2;
  cin >> str1 >> str2;
  sol(str1, str2);
  return 0;
}