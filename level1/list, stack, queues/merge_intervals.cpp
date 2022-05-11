// youtube.com/watch?v=XsOI7fpx8IY&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=127
#include <iostream>
#include "stack"
#include "algorithm"
using namespace std;

struct Interval
{
  int st, en;
};

bool mycomp(Interval a, Interval b)
{
  return a.st < b.st;
}
void mergeIntervals(Interval a[], int n)
{
  // sort based on the starting time in increasing order
  sort(a, a + n, mycomp);
  // index for storing last ele index
  int index = 0;
  for (int i = 1; i < n; i++)
  {
    // if starting time of 1st ele greater than curr end ele, then merge
    if (a[i].st <= a[index].en)
    {
      // merge prev and curr intervals
      a[index].en = max(a[i].en, a[index].en);
    }
    else
    {
      // increase index as can't merge for that index and put the new i which couldn't be merged
      index++;
      a[index] = a[i];
      // since we can't change the value, for the next iteration, make index go to i which it couldn't merge in prev case
      // and try with next i coming in next iteration
    }
  }
  cout << "The merged intervals are - ";
  for (int i = 0; i <= index; i++)
  {
    cout << a[i].st << " " << a[i].en << "\n";
  }
}
int main()
{
  Interval a[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
  int n = sizeof(a) / sizeof(a[0]);
  mergeIntervals(a, n);

  // for (auto i : a1)
  // {
  //   cout << i.first << " " << i.second << "\n";
  // }
  // rows in the multimap are now in sorted order
  return 0;
}
/*
Given time intervals with starting and ending times spaced, print if they can be combined into 1
we use stack here as we can push pop to create a new set of intervals
6
22 28
1 8
25 27
14 19
27 30
5 12

sorted based on starting would be -
1 8
5 12
14 19
22 28
25 27
27 30

push onto stack in increasing or decreasing order, and do end.pop() to pop the end and check if start.top()
matches with end.top() that is starting time of top <= ending time of second last ele and if yes then they can overlap
where the new ending top if the popped one which we stored and start.top() is the value it matched. Do this in a while loop
till either any stack empty or start.top() has value less than end.top() of element before
like -
1 8
5 12
start.top() is 5, then we have done end.pop() and compare with current end.top() i.e. 8, since 5 is less than 8,
meetings 1-8 and 5-12 can overlap

We can take input using multimap in decreasing order
*/