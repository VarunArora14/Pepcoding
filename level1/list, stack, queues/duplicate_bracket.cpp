// https://youtu.be/aMPXhEdpXFA
#include <iostream>
#include "string"
#include "stack"
using namespace std;

// 1. Brackets of only type (
// balance all and make sure all brackets are opened and closed and no extra brackets too

// use push and pop property of stack to remove the pairs of brackets that have already been completed
// Inorder to avoid duplicate brackets on a variable, know that if we have a bracket '(' just before ')' then it means duplicacy
// as in case '((c+d))' we will pop '(c+d)' and will have '(' left before ')'.
// here we use the top() to see if the first ele of stack is a '(' so that if true, then duplicate bracket found, return true
// Remember - the top() of a stack gives the last ele and not the first in the stack

// in the case when we do
/*
if(i==')')
{
  if(s.top()=='())
  {
    ...
    // here we find a closing bracket and see if there a '(' on top of stack meaning the last ele entered. If yes, then duplicacy found
    // return true
  }
}
*/

bool bracket(string inp)
{
  char x;
  stack<char> s;
  for (char i : inp)
  {
    // s.push(i);
    if (i == ')')
    {
      // check for the top() or last ele of the stack
      if (s.top() == '(')
      {
        // duplicacy found
        return true;
      }
      else
      {
        while (s.top() != '(')
        {
          s.pop();
        }
        // pop the '(' as loop end before that
        s.pop();
      }
    }
    else
    {
      s.push(i);
    }
  }
  // base case
  return false;
}

int main()
{
  // (a+b) + ((c+d))
  string inp;
  // input string
  getline(cin, inp);
  cout << bracket(inp);
  return 0;
}

// Note - In a queue the front of queue is the first letter and in a stack the top() is the last element inserted
// if we input "abcd" in a stack and print the top() and popping it also, we get "dcba" and in queue "abcd"
