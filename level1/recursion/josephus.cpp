// https://www.youtube.com/watch?v=dzYq5VEMZIg&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=4
#include <iostream>
#include "vector"
using namespace std;

// https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
int sol(int n, int k)
{
}

int pep_rec(int n, int k)
{
  if (n == 1)
    return 0;
  // if 1 ele left, then it's idx is 0
  int x = pep_rec(n - 1, k); //  survivor of n-1 is x
  // The formula is y = (x+k)%n where the xth element is what we have to find for that xth ele
  // which will survive in n-1 would be what in the nth case

  // We reduce the problem to n-1 each time and using the solution of that we solve the bigger one from n-1 to n
  int y = (x + k) % n;
  return y;
}
/*
Here we have faith that x will find the correct answer for n-1 with base case n=1 retuens 0
meaning if one ele left, return it's idx which is 0
then main problem is (x+k)%n where x is solution of prev problem or starting from that idx, finding the next idx
remember for the case when ele 3 removed from 0 1 2 3 4 we have -
3 4 0 1           => y
0 1 2 3 (indices) => x
and the way to convert them to their real idx is y = (x+k)%n where here k is 3, n=5 (note we use prev n)
0+3=3, 1+3=4, 2+3=5 but 5%5=0 or (2+3) % 5 = 0
x is the solution from the n-1 answer used for current n by formula y = (x+k) % n
*/

int main()
{
  int n = 8, k = 3;
  return 0;
}
/*
Given n people and k intervals, kill them such that find the last person left alive
have array and vis[] for marking and go forward in cicular array till k and mark visited

If already visited, then keep moving forward 1 step till you get the element. Also have a count variable
If count==1 then go through array and print the only non-visited num which is your answer

here the recursive way is to make problem smaller by killing 1 and making problem smaller
to n-1. after removing element at k, assume from k+1 to k-1 in circular manner, you have to solve the subproblem
where new array idx start from k+1
n=7, k=4
0 1 2 3 4 5 6 7 => remove 3(3 is 4th ele)

0 1 2 4 5 6 (assume it is like) =>        4 5 6 0 1 2 (as we start after ele 3 which is 4)
in this, we will assume their indices are 0 1 2 3 4 5 and find a way to make change in the above new array
recursively by adding k to their value. Example: since it is starting from 4, 0+4=4, 1+4=5, 2+4=6, 3+4=7 but 7%7=0
(4+4) % 7=1 (which is the 4th ele) and so on

Everytime we remove ele, we recursively call the new subproblem for n-1 starting from k+1. k remains constant, n changes
We recursively call for the index and after we get it, we go back to that index to see what it's inital value using first recursion
was.
*/
