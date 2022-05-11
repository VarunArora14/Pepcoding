// https://www.youtube.com/watch?v=LliQjLnbhx8&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=1
#include <iostream>
#include "string"
#include "vector"
using namespace std;

bool digit_check(char s)
{
}

vector<string> abbrev(string str)
{
  if (str.length() == 0)
  {
    vector<string> base;
    base.push_back("");
    return base;
  }
  char c = str.front();
  string temp_str = str.substr(1);           //  from 2nd to last char
  vector<string> mid_ans = abbrev(temp_str); //  store the ans recursively
  vector<string> ans;
  for (string i : mid_ans)
  {
    if (i.length() >= 2)
    {
      // check for last 2 digits num
    }
    else if (digit_check(i.back()))
    {
      i.back()++;
    }
    string t1, t2;
    // not i+"1" as it will be opposite
    t1 = "1" + i;
    t2 = c + i;
    ans.push_back(t1);
    ans.push_back(t2);
  }
  return ans;
}
int main()
{
  string s;
  cin >> s;
  vector<string> ans = abbrev(s);
  for (string i : ans)
  {
    cout << i << "\n";
  }
  return 0;
}

/*
Print all the recursions using backtracking, might have to pass string psf
*/