// https://www.youtube.com/watch?v=Mud_QjUwbw8&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=69
#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

bool compare(pair<int, int> f, pair<int, int> s)
{
  // we compare on basis of height so return f.first<s.first and if height same then return f.secon<s.second
  if (f.first == s.first)
    return f.second < s.second;
  return f.first < s.first;
}

void lis_func(vector<pair<int, int>> vec, int n)
{
  vector<int> lis(n, 1); // all minimum 1
  int ans = 1;
  for (int i = 1; i < n; i++)
  {

    for (int j = 0; j < i; j++)
    {
      // check if both height and width smaller and then if lis[j]+1 > lis[i]
      if (vec[j].second < vec[i].second && (vec[j].first < vec[i].first))
      {
        if (lis[j] + 1 > lis[i])
        {
          lis[i] = lis[j] + 1;
          ans = max(ans, lis[i]);
        }
      }
    }
  }
  cout << "ans is " << ans;
}
int main()
{

  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  // vec.first() for height and vec.second() for width
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i].first >> vec[i].second;
  }
  sort(vec.begin(), vec.end(), compare);

  for (auto i : vec)
  {
    cout << i.first << " " << i.second << "\n";
  }

  return 0;
}

/*
class Solution {
public:
    bool compare(vector<int> f, vector<int> s)
    {
        // if the 2 widths are same, then return min of heights
        if(f[0]==s[0])
        {
            return f[1]<s[1];
        }
        return f[0]<s[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(),envelopes.end());

        vector<int> lis(n,1);
        int ans=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++){
                // check if both jth envelope width smaller than ith and jth height also smaller than ith
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1]<envelopes[i][1])
                {
                    if(lis[j]+1>lis[i])
                    {
                        lis[i]=lis[j]+1;
                        ans=max(ans,lis[i]);
                    }
                }
            }
        }
        return ans;
    }
};
*/