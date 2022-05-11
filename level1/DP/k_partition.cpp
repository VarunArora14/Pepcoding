// https://www.youtube.com/watch?v=TvvGj1FtHIk&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=11
#include <iostream>
#include "vector"
#include "string"
using namespace std;

int sol(int n, int k)
{
  if (n == 0 || k == 0 || k > n)
    return 0;

  if (n == k || k == 1)
    return 1;

  return sol(n - 1, k - 1) + k * sol(n - 1, k);
  // reason explained below in comments
}

int main()
{

  int n, k;
  cin >> n >> k;
  cout << sol(n, k);
}
/*
Here like friends pair ques, we have to make combine k elements together as one and print the various combinations. Note the element
can either be solo or part of k size pair
For [1,2,3,4] => { [1,23,4], [12,3,4], [13,2,4], [14,2,3], [1,24,3], [1,2,3,4] }

Note - We have to make k partitions not k groups like [1,234] where k=3

For (n,k) if there are (n-1,k) then nth ele can be put in any of the partitions and if we have (n-1,k-1) then k ways to form

If for 1234, 123 make 3 total partitions(k=3) then 4 can be put in any of the partitions
If 123 make 2 sets like [12|3, 13|2, 1|23] then 4 has to be part of the next set only making [ 12|3|4 , 13|2|4, 1|23|4 ]

So, if n-1 ele make k-1 sets then nth ele has to make another set and if n-1 ele make k sets then nth ele can be part of any set
so sol(n,k) = sol(n-1,k-1) + sol(n-1,k)*k
*/