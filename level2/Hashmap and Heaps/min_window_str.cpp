// https://www.youtube.com/watch?v=e1HlptlipB0&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=8
// https://leetcode.com/problems/minimum-window-substring/discuss/1735155/C%2B%2B-oror-EASY-TO-UNDERSTAND-oror-Sliding-Window-Appraoch
#include <iostream>
#include <vector>
#include "map"
#include <algorithm>
#include <chrono>
#include "climits"

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

// O(n^2) time and O(n) space
void sol_n2(string first, string second)
{
  pair<int, int> idx;
  // if second.length()==1 simply find the char
  if (second.length() == 1)
  {
    char x = second[0];
    for (auto i : first)
    {
      if (i == x)
      {
        cout << 1;
        return;
      }
    }
  }
  map<char, int> m1;
  for (auto i : second)
    m1[i]++;
  // maps the chars
  int minval = INT_MAX;
  // len -1 as j from i+1 so min len=2
  for (int i = 0; i < first.length(); i++)
  {
    map<char, int> temp = m1;
    for (int j = i; j < first.length(); j++)
    {
      if (temp.find(first[j]) != temp.end())
      {
        // check if temp[first[j]] is 1 or more than 1
        if (temp[first[j]] > 1)
          temp[first[j]]--;
        else
          temp.erase(first[j]);
        // remove from map if 1 occurence was there
      }

      // check if map empty
      if (temp.empty())
      {
        print2(i, j);
        if (minval > j - i + 1)
        {
          idx.first = i;
          idx.second = j;
          minval = j - i + 1;
        }
        break; // dont keep continuing as we have to find min substring
      }
    }
  }
  cout << "min window substr is " << first.substr(idx.first, idx.second) << " \n";
}

void hash_sol(string str1, string str2)
{
  // first we map the 2nd str ele to map
  map<char, int> m2; // for str2
  for (auto i : str2)
    m2[i]++;

  map<char, int> m1;
  string ans = "";                                                        // for str1
  int j = 0, i = 0, minval = INT_MAX, count = 0, desired = str2.length(); // count maintains the number of ele of substr
  // desired will be case when a substring contains exactly same chars as str2, we maintain a window of size

  while (true)
  {
    bool f1 = false, f2 = false;

    // acquire
    while (j < str1.length() && count < desired)
    {
      char ch = str1[j];
      // insert the j ele in the new map, j ele is str1[j]
      m1[ch]++;
      j++;

      // check if current freq of str1[j]<= freq in map2, if yes then it is useful
      if (m1[ch] <= m2[ch])
      {
        count++; // add to count the number of useful ele
      }
      f1 = true; // check if first loop visited nd same for f2
    }
    // after this you have found a substring that has the ans, now it's time to make it smaller byremoving ele from start

    // collect ans and release
    while (i < j && count == desired)
    {
      // checking if starting point i remaind smaller than j and or count of found substring does not change
      // here we increase value of i finding the smaller substring without changing count=desired

      // collect ans first which lead to break of the loop
      string temp_ans = str1.substr(i, j); // i at 0 and j at point where we did last count++ for desired

      if (ans == "" || temp_ans.length() > ans.length())
        ans = temp_ans;

      // now check if by removing the starting ele
      i++;
      char ch = str1[i]; // grabbing the starting chars and reducing freq from m1
      if (m1[ch] == 1)
        m1.erase(ch);
      else
        m1[ch]--;

      // check if freq of m1[ch] smaller than m2[ch], you removed imp element
      if (m1[ch] < m2[ch])
        count--;
      // this breaks out of loop too

      f2 = true;
    }

    if (!f1 && !f2)
      break; // break out of loop when neither visited
  }
  cout << ans;
}

int main()
{
  string first, second;
  cin >> first >> second;
  auto start1 = high_resolution_clock::now();

  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  sol_n2(first, second);
  cout << endl
       << duration.count() / 1000;

  return 0;
}
/*
first ="abc"
second="bc"

For n^2 sol it is simple that you check for substrings if they contain the chars and when map of string 2 empty then take min currval, j-i+1
and then the min substr

For O(m+n) solution where m is length of str1 and n is len of str2, we use map as well as subtring window.
We have a map here where you map char and num of occurences of str2

Now, you run through the first chars finding if you have found all occurences of str2 and once you have all, you store it's indices as potential
answer. This is acquiring.
Then start releasing the ele from the start while checking occurences of str2 are not getting removed from the map.
If we find this answer is valid and smaller, then discard prev and mark this as valid and keep going right till removing first ele changes
the count as removing ele makes some character missing from substring to match str2.

The algorithm is acquire till the substr till now has all the ele of str2, then start removing ele from the start of substr checking only
excessive ele are getting removed and update the ans len and substr
 Acquire
 Release till match count reduced
*/