// https://www.youtube.com/watch?v=JCT04Z94Nyo&list=PL-Jc9J83PIiHhXKonZxk7gbEWsmSYP5kq&index=2
#include <iostream>
#include "vector"
using namespace std;

int main()
{

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++)
  {
    cin >> b[j];
  }
  vector<int> ans;

  // since the lists are sorted, the largest value will be at the end of the ans
  int i = 0, j = 0;
  while (i < n && j < m)
  {
    if (a[i] == b[j])
    {
      // check add ele to the list and remove all the next ele in both lists having same values
      if (ans.size() == 0 || ans[ans.size() - 1] != a[i])
      {
        // cout << "a[i] and b[i] is " << a[i] << " and i is " << i << "\n";
        ans.push_back(a[i]);
      }
      i++;
      j++;
      // inc both anyways
    }
    else if (a[i] < b[j])
    {
      if (ans.size() == 0 || ans[ans.size() - 1] != a[i])
      {
        // cout << "a[i] is " << a[i] << " and i is " << i << "\n";
        ans.push_back(a[i]);
      }

      i++;
    }
    else
    {

      if (ans.size() == 0 || ans[ans.size() - 1] != b[j])
      {
        // cout << "b[j] is " << b[j] << " and j is " << j << "a[i] is " << a[i] << " and i is " << i << "\n";
        ans.push_back(b[j]);
      }

      j++;
    }
  }

  // check if any array has ele left
  while (i < n)
  {
    // assuming till here list not empty, check if last ele entered not the same and then enter ele
    if (ans[ans.size() - 1] != a[i])
    {
      // cout << "a[i] is " << a[i] << " and i is " << i << "\n";
      ans.push_back(a[i]);
    }

    i++;
  }

  while (j < m)
  {
    if (ans[ans.size() - 1] != b[j])
    {
      // cout << "b[j] is " << b[j] << " and j is " << j << "\n";
      ans.push_back(b[j]);
    }

    j++;
  }

  for (auto i : ans)
  {
    cout << i << " ";
  }
  return 0;
}
/*
better use a vector instead of unordered_set as we don't want to use STL but normal functions
a1 => [1,2,2,3,4]
a2 => [1,1,3,5]

ans => [1,2,3,4,5]

5 4
1 2 2 3 4
1 1 3 5
*/