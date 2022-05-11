// https://www.youtube.com/watch?v=VT4bZV24QNo&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=22
#include <iostream>
using namespace std;

int main()
{
  int len;
  cin >> len;
  int a[10];
  for (int i = 0; i < len; i++)
  {
    cin >> a[i];
  }
  // int dp[10] = {};
  int inc, exc;
  // base case for first ele as prev sum does  not exist
  inc = a[0];
  exc = 0;
  for (int i = 1; i < len; i++)
  {
    int new_inc, new_exc;
    new_inc = exc + a[i];
    new_exc = max(exc, inc); //  max of prev inc and exc

    // make them the curr inc and exc
    inc = new_inc;
    exc = new_exc;
  }
  cout << max(inc, exc);
  return 0;
}
/*
Given a sequence of numbers, analyse all the subsequences using only those which dont have adjacent element
and out of those print the max sum of the subsets
Since you can't take adjacent elements, you have to say no to the next element if you choose one
Brute force way is to go through all the subsets considering you cannot choose the next ele if you have chosen current
and generate 2^n subsets and find the max. There is smarter way -

Given array => 5 10 10 100 5 6
We create 2 variables include and exclude as we can either include or exclude the elements
    5 10 10 100 5 6
inc
exc

inc contains the subsets which follow the condition that no adjacent together including the curr ele
exc same as above except not including the curr element.
For first element 5, inc will have value 5 as you have to include 5 and for exc you have 0 as u don't include 5

    5 10 10 100 5 6
inc 5 10
exc 0 5

Here for 10 as you have to include 10 then you can't use prev inc values but exc ones. For inc=10, exc=max(0,5)
or max of prev include and exclude
For next 10, "include" the current 10 and add prev exclude value so 10+5=15
for "exc", make it max of inc and exc of prev value=10

For 100, "inc" is 100 + prev exclude(10)=110
"exc" is max of prev values = max(15,10)=15

For 5, "inc" is 5+prev exclude = 5+15=20
"exc" is max(110,15)=110

For 6, "inc" is 6 + prev exclude or 6+110=116
"exc" is max(110,20)=110

FINAL

    5 10 10 100  5   6
inc 5 10 15 110 20  116
exc 0 5  10 15  110 110

*/