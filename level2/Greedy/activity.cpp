// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
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

bool compare(pair<int, int> &a, pair<int, int> &b)
{
  // return true when finishing time of first smaller than 2nd. If both same then reuturn the smaller starting time
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

void sol(vpii &time)
{
  // start from 2nd time and check if it's start smaller than prev end the continue, else add to count and change the end to new end
  for (auto &p : time)
  {
    cout << p.first << " " << p.second << "\n";
  }
  int n = time.size();
  vector<int> ans;
  ans.push_back(0);
  int start, end;
  tie(start, end) = time[0];

  int count = 1;
  for (int i = 1; i < n; i++)
  {
    if (end <= time[i].first)
    {
      // if prev end less than next start means we can add to the count and make new end as time[i].second
      count++;
      end = time[i].second;
      ans.push_back(i);
    }
  }

  for (int i : ans)
    cout << i << " ";
}

int main()
{
  int n;
  cin >> n; // activty size or len
  vpii time(n);
  for (int i = 0; i < n; i++)
  {
    cin >> time[i].first >> time[i].second;
  }

  sort(time.begin(), time.end(), compare);
  sol(time);
  return 0;
}
/*
here given the activities sorted by their finish time. Sorting by finishing time is good as starting time will always be less than finishing of the curr.Also, in the given
*/