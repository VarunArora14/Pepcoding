// https://www.youtube.com/watch?v=p-RbQyQevTQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=106
#include <iostream>
#include "string"
#include "stack"
using namespace std;

stack<char> s;
bool call_pop(char a)
{
  // The commented code had a problem that for string "(a+b{)" it give balanced output whereas answer is false
  // as it was not checking the s.top() but only focussed on finding the '(' without caring if something comes in btw
  // while (s.top() != a)
  // {
  //   s.pop();
  // }
  // if (s.empty())
  // {
  //   return false;
  //   // meaning faulty expression
  // }
  // else
  // {
  //   s.pop();
  // }

  // return true;
  if (s.size() == 0)
    return false;
  else if (s.top() != a)
  {
    return false;
  }
  else
    s.pop();

  return true;
}

bool bracket(string inp)
{
  for (char i : inp)
  {
    if (i == '}' || i == ')' || i == ']')
    {
      // In my code this base condition was missing that if stack already empty and if closing braces found then return false
      // our code was earlier giving no output for "[(a + b) + {(c + d) * (e / f)}])" as stack already became empty
      // and program closed
      if (i == '}')
      {
        call_pop('{');
      }
      else if (i == ']')
      {
        call_pop('[');
      }
      else if (i == ')')
      {
        call_pop('(');
      }
    }
    else if (i == '(' || i == '{' || i == '[')
    {
      s.push(i);
    }
  }
  if (s.size() != 0)
    return false;
  return true;
}

int main()
{
  string inp = "[(a + b) + {(c + d) * (e / f)}(]";
  // getline(cin, inp);
  cout << bracket(inp);
  return 0;
}