// https://www.youtube.com/watch?v=97mF4juql6g&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=397
#include <iostream>
#include "vector"
#include "string"
using namespace std;

// from 0 to 9
string a[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
vector<string> keypad(string str)
{
  // base case for 0 length
  if (str.length() == 0)
  {
    vector<string> base;
    base.push_back("");
    // dont forget to return
    return base;
  }

  char f = str.front();
  string remain = str.substr(1);
  vector<string> rres = keypad(remain);
  // recursive call till last character where base case returns vector<string> with ""
  // and then push characters in res vector<string> and return it the vector<string>
  // the outer loop is for the str.front() whose combinatons will be added to the inner vector<string>
  // containing prev results. The ques is how will u know which character(number) has what value.

  // For that we have outer array or vector of string with values stored which we access by using arr[int(str.front())]
  vector<string> res;
  // get the string from the number we have at str.front()
  int idx = int(f) - '0'; //  convert char to num and then store the string using a[i]
  string curr_num = a[idx];

  // make the outer loop through the chars of a[idx] and inner loop as the rres
  for (char i : curr_num)
  {
    for (string j : rres)
    {
      string temp = i + j; //  string concatenation using '+'
      res.push_back(temp);
      // note - don't push back in rres but res as we don't have to print substrings
      // but combinations of all
    }
  }
  return res;
}
int main()
{
  string str = "123";
  char f = str.front();
  vector<string> ans = keypad(str);
  for (auto i : ans)
  {
    cout << i << "\n";
  }
  // works correctly for "123", total 27 combinations
  return 0;
}
/*
Here we do similr to get subsequences where for the base case we return a empty vector<string>
and for each character we print the combination of keypad by having an outer and inner loop
Outer loop for str.front() character and inner for the till now string
*/