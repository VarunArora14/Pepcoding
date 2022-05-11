// https://www.youtube.com/watch?v=Zy9XnXw8E7U&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=108

// Given an array, create a new array printing the next greatest element to the right
#include <iostream>
#include "vector"
#include "stack"
using namespace std;

// Next Greatest Element Right
void nger_arr(int a[], int n)
{
  vector<int> ans;
  ans.assign(n, -1);
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] > a[i])
      {
        ans[i] = a[j];
        break;
      }
    }
  }
  for (int i : ans)
  {
    cout << i << " ";
  }
}
// The above has n^2 time complexity

// The way the stack one works is that we start from last element as we know that nge of last ele is -1
// push that last ele into stack and move backwards to first ele of array
// check if an ele is greater than s.top(), if yes - then push the new on the stack and pop the previous as we don't need them
// as we go backwards to the first ele
// if no - then push that into stack

// The below code fails to handle the case when stack becomes empty and program just stops
void nger_stack(int a[], int n)
{
  stack<int> s, ans;
  // now check if greater or not
  for (int i = n - 1; i >= 0; i--)
  {
    if (s.empty())
    {
      // cout << -1 << " ";
      ans.push(-1);
    }
    if (s.top() < a[i])
    {
      while (!s.empty() && s.top() < a[i])
      {
        s.pop();
        // ans.push(a[i]);
        // The above is wrong as we are pushing into the ans stack in the while loop whereas we had to push in the s stack only
        // cout << a[i] << " ";
      }
      // first push the ans of largest ele and then push a[i] in s for next query
      ans.push(s.top());
    }
    else if (a[i] < s.top())
    {
      ans.push(s.top());
      // cout << s.top() << " ";
    }
    s.push(a[i]);
  }
  while (!ans.empty())
  {
    cout << ans.top() << "\n";
    ans.pop();
  }
}

// final code nger
void nger_final(int a[], int n)
{
  stack<int> s, ans;
  // push the last ele in s and -1 in ans as it is always true
  s.push(a[n - 1]);
  ans.push(-1);
  // starting from 2nd last ele
  for (int i = n - 2; i >= 0; i--)
  {
    // -a+
    // - means pop till stack empty or top is largest ele
    // a means print the largest ele
    // + means push new ele into the stack
    while (!s.empty() && a[i] > s.top())
    {
      s.pop();
    }
    if (s.empty())
    {
      // meaning the a[i] is the largest ele till now and since we start from end, -1 is it's answer
      ans.push(-1);
    }
    else
    {
      // loop closes when a[i]<s.top(), in that case that is the answer
      ans.push(s.top());
    }
    // push the curr ele in any case as
    s.push(a[i]);
  }

  while (!ans.empty())
  {
    cout << ans.top() << " ";
    ans.pop();
  }
}
int main()
{
  int a[] = {5, 5, 3, 8, -2, 7};
  int n = sizeof(a) / sizeof(a[0]);
  nger_final(a, n);
  return 0;
}
/*
In the stack way, starting from the last ele we push the last ele in the stack
The operation we will do is  (- ele +) meaning pop the prev element, print the answer ele and then push the element
For each element check if stack has an ele smaller than the curr ele and keep popping from stack till the top has a larger ele
than current one
Consider case - {4,8,1,2,5,9,5,6,2,3,7 }
Base Case - If stack empty return -1
First we print -1 as we have nothing to pop and then push 7 in stack
Then for 3, 3<7 so can't remove 7(7 is the only ele) so push 3 into the stack
Then goto 2, no ele in stack is smaller than 2 so print 3, push 2 onto the stack
Then comes 6, now in the stack 2 and 3 are smaller than 6 so pop them and print the top of stack i.e. 7 and push 6
on the stack.
*/

/*
#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a){
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
vector<int> solve(vector<int>arr)
{
  //write your code here
}
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>nge(n,0);
    nge=solve(arr);
    display(nge);
   return 0;
}
*/