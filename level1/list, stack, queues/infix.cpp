// Here we get a set and we do infix and postfix operations on it
#include <iostream>
#include "stack"
#include "string"
using namespace std;

int precedence(char op)
{
  if (op == '+')
  {
    return 1;
  }
  else if (op == '-')
  {
    return 1;
  }
  else if (op == '*')
  {
    return 2;
  }
  else
  {
    return 2;
  }
}

int operation(int v1, int v2, char op)
{
  switch (op)
  {
  case '+':
    return v1 + v2;
  case '-':
    return v1 - v2;
  case '*':
    return v1 * v2;
  case '/':
    return v1 / v2;
  }
  return 0;
}

void eval(string exp)
{
  stack<int> val, op;
  for (char i : exp)
  {
    if (i == '(')
    {
      op.push(i);
    }
    else if (i == ')')
    {
      // pop the 2 values on the value stack and pop a operand from op stack
      while (op.top() == '(')
      {
        // out of 2 values, the top will be the 2nd value as we put 2nd value later on so it is on top of stack
        int v2 = val.top();
        val.pop();
        int v1 = val.top();
        val.pop();
        char optr = op.top();
        op.pop();
        int ans = operation(v1, v2, optr);
        val.push(ans);
      }
      op.pop();
      // pop the '('
    }

    // for digits or nums whichever we are using - assuming digits here
    /*
      int value=0;
      while(i<exp.length() && isdigit(exp[i]))
      {
        value = value*10 + (exp[i]-'0'));
        // i-the ascii value of 0
      i++;

      }
      val.push(value);
      i--;
      // do i-- as the outer loop also does i++
      */
    else if (isdigit(i))
    {
      val.push(i - '0');
      // as we are assuming only single digit nums only. For multiple we do
    }
    else if (i == '+' || i == '-' || i == '*' || i == '/')
    {
      // else we have to decide for the order of precedence of the operators
      // only pop when current operator smaller than op.top() so that we do the higher priority
      // operations before and stop when we have equal or lower priority operations
      while (!op.empty() && op.top() != '(' && precedence(i) <= precedence(op.top()))
      {
        // i wants higher priority elements to process first

        // till we reach empty stack or we reach the starting bracket or till we have a operator with lower
        // priority than op.top(), we pop and perform operation
        int v2 = val.top();
        val.pop();
        int v1 = val.top();
        val.pop();
        char optr = op.top();
        op.pop();
        int ans = operation(v1, v2, optr);
        val.push(ans);
      }
      // don't forget to push the current operator i and push the curr operator
      op.push(i);
    }
  }
  // now for the most outer part of expression, we don't have any '(' so we run the same expression again till
  // both the stacks are empty bcos in our last else case we only evaluate when we have lower precendence item coming
  // when we already have a higher precedence on the top. In case like 2+3*6 where stack of operator is [*,+] we have
  // to run an outer operation like before till empty stack
  while (!op.empty())
  {
    int v2 = val.top();
    val.pop();
    int v1 = val.top();
    val.pop();
    char optr = op.top();
    op.pop();
    int ans = operation(v1, v2, optr);
    val.push(ans);
  }
  // the answer is the remaining answer in the stack val
  cout << val.top();
}

int main()
{
  string exp = "2+3*6";
  eval(exp);
  return 0;
}