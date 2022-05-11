// https://www.youtube.com/watch?v=LliQjLnbhx8&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=1
#include <iostream>
#include "vector"
#include "string"
using namespace std;

vector<string> abbrev(string str)
{
  // base case for 0 length, return vector<string> with ""
  if (str.length() == 0)
  {
    vector<string> base;
    base.push_back("");
    return base;
  }
  // recursively store the first character
  char f = str.front();
  string remain = str.substr(1);
  vector<string> tempres = abbrev(remain);
}

int main()
{
  string s = "pep";
  return 0;
}
/*
Here we have to find all the combinations recursively using backtracking which we previously did
by choosing first character and recursively calling for remaining string where we used "-" for 0 but here
we print character or 1 and if more than 1 noted then add the numbers and store in string
*/