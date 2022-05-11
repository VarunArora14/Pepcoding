// https://www.youtube.com/watch?v=jUo0Qis4FKU&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=415
#include <iostream>
#include "vector"
#include "string"
using namespace std;

vector<string> print_enc(string str, string asf)
{
  // base case
  if (str.length() == 0)
  {
    cout << asf << "\n";
  }
  else if (str.length() == 1)
  {
    char ch = str[0];
    if (ch == '0')
    {
      return; //  0th character is not there as a is 1st
    }
    else
    {
      int chv = ch - '0';
      char code = char('a' + chv - 1); //  typast to char
      asf = asf + code;
      cout << asf << "\n";
    }
  }
  // for first character
  else
  {
    char f = str[0];
    string roq = str.substr(1);
    if (f == '0')
    {
      return;
    }
    else
    {
      int chv = f - '0';
      char code = char('a' + chv - 1);
      print_enc(roq, asf + code);
    }
  }
  // for first 2
  string ch12 = str.substr(0, 2);
  string roq = str.substr(2); //  remaining string
  // parse to int
}

int main()
{
  string str = "abc";
  return 0;
}

/*
Here we have to print the ways a string can be written as it's alphabet order
let's say "123" can be written as "abc" and "aw" also where a is 1 and w is 23
Use vector<string> here where move over num string checking if it's value <26 as
26th ele is last which is 'z'

for "123", ways to divide are - "1,23", "1,2,3", "12,3"
In short we have to find ways to divide the string as main ques and side task is to print the
alphabet they have
*/