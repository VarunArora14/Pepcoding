// https://www.youtube.com/watch?v=m01ubOp-FMg&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=113
#include <iostream>
#include "vector"
#include "stack"
using namespace std;

// The below is n^2 time
void arr_hist(int a[], int n)
{
  // start from the first ele from 2nd to end find the smallest val with max area
  int i, j, max_area = 0, h = a[0];
  for (i = 0; i < n; i++)
  {
    h = a[i];
    for (j = i + 1; j < n; j++)
    {
      h = min(h, a[j]);
      // find min height and calc the area for each
      // cout << "curr area is " << h * (j - i) << "\n";
      max_area = max(max_area, h * (j - i + 1));
      // the +1 for difference 3 for 1 2 3 as j-i here would be 2-0=2
    }
  }
  cout << max_area;
}

void stack_hist(int a[], int n)
{
  // we create 2 array lb and rb storing the index of next smallest element to left and right
  // as index subtraction will give me width of rectangle
  // In case {6, 2, 5, 4, 5, 1, 6}, the next smallest ele on right of 4 is 5, smallest on left is 1
  // so 5-1=4
  vector<int> rb(n), lb(n);
  // rb is right boundary or next smallest ele index on right
  // lb is left boundary or next smallest ele index on left

  stack<int> s;
  s.push(a[n - 1]); // the last ele

  // right boundary code

  rb[n - 1] = n; // next smaller ele on right index is the next index
                 // we do in such a way that for first and last ele rb[n-1]=7 and lb[0]=-1 i.e. the smaller ele on the left
                 // such that 7 - (-1) -1 = 7 which is the length of the array

  // first the right boundary
  for (int i = n - 2; i >= 0; i--)
  {
    // push first ele and for others, if a[i]<s.top() keep popping as we need the smaller ele
    while (!s.empty() && a[i] < a[s.top()])
    {
      // pop the larger ele index on the right till smaller on right
      s.pop();
    }
    if (s.empty())
    {
      rb[i] = n;
      // if empty stack then consider the array length ans the index on next smallest ele to the right
    }
    else
    {
      rb[i] = s.top();
    }
    // don't forget to push the curr ele so other ele can also check for next smallest ele to their right
    s.push(i);
  }

  // empty the stack for left boundary
  while (!s.empty())
  {
    s.pop();
  }

  // left boundary code
  lb[0] = -1; // the next smallest ele to the left is -1

  for (int i = 1; i < n; i++)
  {
    while (!s.empty() && a[i] < a[s.top()])
    {
      s.pop();
    }
    if (s.empty())
    {
      lb[i] = -1;
      // if empty stack meaning the smallest ele then set the next smallest ele index as -1
    }
    else
    {
      lb[i] = s.top();
    }
    s.push(i);
  }
  // area code
  int max_area = 0;
  for (int i = 0; i < n; i++)
  {
    int width = rb[i] - lb[i] - 1;
    int area = a[i] * width;
    max_area = max(max_area, area);
  }
  cout << max_area;
  // finding the right and left boundary is a small problem i.e. problem on left and right
  // do a left to right loop for lb and opposite for rb like NGER we had right to left loop
}

/*
Working of stack_hist
{6, 2, 5, 4, 5, 1, 6}
First we make the right boundary for smallest ele on right
first rb[6] becomes 7 as a base case and push 6 in stack s
Them for ele 1, since a[i]<a[s.top()], pop 7 from s, make rb[5] as 7 as stack empty and push 5 in s at end
For ele 5, 5<1 so no popping, rb[4]=s.top() i.e., rb[4]=5 which is index of 1 and then push index of 5(4) on the stack
for now, 1 is the next smallest ele on right of 5
Then for 4, index of 5 is popped but not 1 and index of 1 is the next smallest ele
Then for 5, 4 is next smallest ele so store rb[2]=3 and so on..

The same applies for lb in opposite order

rb -> 1 5 3 5 5 7 7
lb -> -1 -1 1 1 3 -1 5

*/

int main()
{
  int a[] = {6, 2, 5, 4, 5, 1, 6};
  int n = sizeof(a) / sizeof(a[0]);
  stack_hist(a, n);
  return 0;
}

/*
Given a histogram bar chart, find the maximum area it enclosed in the rectangle
for values {6,2,5,4,5,1,6} -> here height 1 is the limiting factor for the area unlike largest area in a tank
move forward in such as way considering the smallest height as the limiting factor and width too

Here the largest histogram is the middle one 5,4,5 with area 4*3=12 as 4 is the smallest and we have 3 ele

Note - the largest area can be at start, end or middle meaning we have to move the starting and ending index both
Also know that for a rectangle, at least 2 elements are needed
Also the area depends on the smallest element found till now
*/