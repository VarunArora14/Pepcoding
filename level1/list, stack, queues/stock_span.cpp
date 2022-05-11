// https://www.youtube.com/watch?v=kCAMWbTCO1c&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=111
#include <iostream>
#include "stack"
#include "vector"
using namespace std;

// start from the first ele as it has span value 1 always which is it's index
// The below has time complexity n^2
void vec_span(vector<int> a)
{
  int n = a.size();
  bool flag = false;
  vector<int> ans;
  if (a.empty())
  {
    cout << "vector is empty";
    exit(0);
  }
  else
  {
    ans.push_back(1);
  }
  for (int i = 1; i < n; i++)
  {
    // for each iteration initially flag is false
    flag = false;
    for (int j = i - 1; j >= 0; j--)
    {
      if (a[i] < a[j])
      {
        flag = true;
        // we found a larger ele
        ans.push_back(i - j);
        break;
      }
    }
    if (flag == false)
    {
      // if not found smaller then push back the curr index
      ans.push_back(i + 1);
    }
  }
  // print the ans
  for (int i : ans)
  {
    cout << i << "\n";
  }
}

// stack based with linear time complexity
// Note - In the stack don't push the value but the index of the larger ele as then we won't need to use
// any pos variable for position
void stack_span(vector<int> a)
{
  stack<int> s;
  int pos = 0;
  // first push the first ele in the stack and 1 in ans
  vector<int> ans;
  // note the first ans is always 1 as no day before that day
  // push index of ele and not it's value
  s.push(0); //  index of first ele
  ans.push_back(1);
  for (int i = 1; i < a.size(); i++)
  {
    // loop till stack either empty or top of stack is smaller as we have to find the s.top() to be larger than a[i]
    while (!s.empty() && a[i] > a[s.top()])
    {
      s.pop();
    }
    // now the loop stops at either of 2 conditions - empty stack and a[i]<s.top()
    if (s.empty())
    {
      // the curr ele is the largest so push the ans as it's index
      ans.push_back(i + 1);
      // don't forget pushing a[i] at end of s at the end
    }
    // else is when s.top() > a[i]
    else
    {
      ans.push_back(i - s.top());
      // push a[i] as it can be greater than next day stock
    }
    // pushes the larger ele or the new ele anyways for all
    s.push(i);
  }

  for (int i : ans)
  {
    cout << i << " \n";
  }
}

int main()
{
  vector<int> a;
  int n = 9;
  // cin >> n;
  for (int i = 0; i < n; i++)
  {
    int inp;
    cin >> inp;
    a.push_back(inp);
  }
  stack_span(a);
  return 0;
}

// Another variation of nger
// Given prices of shares for each day, find the span for each day, where span is the next greater element
// on the left i.e. the day on left the price was greater than curr day, the difference is the span
// If no day before curr has greater span then index+1 is the curr span
// if ele+1 has value less than ele, then span of ele+1 is 1 as the difference of gap btw ele and ele+1 is 1
/*
2
5
9
3
1
12
6
8
7
*/