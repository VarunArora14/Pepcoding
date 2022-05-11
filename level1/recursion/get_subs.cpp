// https://www.youtube.com/watch?v=Sa5PmCFF_zI&list=PL-Jc9J83PIiFj7YSPl 2ulcpwy-mwj1SSk&index=396
// https://www.geeksforgeeks.org/print-subsequences-string/
#include <iostream>
#include "vector"
#include "string"
using namespace std;

vector<string> get_subs(string str)
{
  // base case when empty string, then push empty string in vector and return
  // as 2^0=1, don't return empty vector<string>

  // base case helps for case "---" and to make 2^n cases as after base case we have
  // for loop which then pushes 2 times the number of items in the rres vector<string>
  // which means

  if (str.length() == 0)
  {
    vector<string> bres;
    bres.push_back("");
    return bres;
  }
  // return type vector string to store the substrings
  char f = str.front();       //  a
  string ros = str.substr(1); //  from index 1 to end i.e. bc here
  // recursive call to store the vector strings
  vector<string> rres = get_subs(ros);

  vector<string> mres;
  for (auto i : rres)
  {
    string temp1, temp2;
    temp1 = "-" + i;
    temp2 = f + i;
    // doing to_string() prints the ascii and not the characters
    mres.push_back(temp1);
    mres.push_back(temp2);
  }
  return mres;
}

int main()
{
  string str = "abc";
  vector<string> ans = get_subs(str);
  for (string i : ans)
  {
    cout << i << "\n";
  }
  return 0;
}
/*
Get the subsequences of a given string and store, print them all
if string is abc then subs are -
---
-bc
abc
a-c
ab- and so on.. with 2^n total where n is length of string
For empty string ans is [-] as 2^0 is 1
and for a single character we have 2^1=2 combinations which are [-] and [a]

So what we do is we store the first character and remaining string in 2 variables and recursively call
the function till we have the base case
then we create a new vector<string> and in that

*/