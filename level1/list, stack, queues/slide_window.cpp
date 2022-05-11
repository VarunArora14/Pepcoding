// https://www.youtube.com/watch?v=nKXUyUC3BNA&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=115
#include <iostream>
#include "vector"
#include "stack"
using namespace std;

// The below code does not pass test case 3 because of TLE(Time Limit Exceeded) as time is O(n^2)
// The stack answer is O(n) with O(n) space
void vec_slide(vector<int> a, int n, int k)
{
  int big;
  vector<int> ans;
  for (int i = 0; i <= n - k; i++)
  {
    // on this condition i+k=n, end
    big = a[i];
    for (int j = 1; j < k; j++)
    {
      big = max(big, a[j + i]);
    }
    ans.push_back(big);
  }
  for (int i : ans)
  {
    cout << i << " ";
  }
}

// stack solution is similar to nge with above 2 loops
// This function stores the nge from right to left
void stack_slide(int a[], int n, int k)
{
  stack<int> s;
  vector<int> ans(n);
  ans[n - 1] = n;
  // The reason for any large value with no next greater element we keep the value as n is because for the next
  // ele we want a very large value to represent the next greater ele and not -1 as for the next ele we also want it's next
  // greater, it will be considered outside window only if very large value

  for (int i = n - 1; i >= 0; i--)
  {
    // -a+
    while (!s.empty() && a[i] > a[s.top()])
    {
      // NOTE- we are storing only the top() fo stack and not their value
      s.pop();
    }
    if (s.empty())
    {
      // if empty stack then no next greater
      ans[i] = n;
    }
    else
    {
      ans[i] = s.top();
      // finding the larger ele as a[i]<s.top() for the loop break condition
    }
    s.push(i);
  }
  while (!s.empty())
  {
    cout << s.top() << " "; //  prints all the nge from right to left
    s.pop();
  }
  cout << "\n";
  int j = 0;
  for (int i = 0; i <= n - k; i++)
  {
    // enter loop to find the max of window starting at i
    if (j < i)
      j = i;
    while (ans[j] < i + k) //  checking if nge inside the window
    {
      j = ans[j]; //  go to the nge
    }
    cout << a[j] << " ";
  }
}

int main()
{
  int a[] = {2, 9, 3, 8, 1, 7, 12}, k = 3;
  int n = sizeof(a) / sizeof(a[0]);
  stack_slide(a, n, k);
  // int n1, k1;
  // cin >> n1 >> k1;
  // vector<int> a1(n1, 0);
  // for (int i = 0; i < n1; i++)
  // {
  //   cin >> a1[i];
  // }
  // vec_slide(a1, n1, k1);
  return 0;
}
/*
Given a long array, find the largest ele for any set k such that print the max val for every k intervals
ex: {2,9,3,8,1,7,12} -> {9,9,8,12}
Approach is finding the curr max ele till now and storing in the array and then max ele after kth interval
*/