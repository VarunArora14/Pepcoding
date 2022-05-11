// https://www.youtube.com/watch?v=ju8vrEAsa3Q&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=25
#include <iostream>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int same = k, diff = k * (k - 1);
  int total = same + diff; //  ii for same ele, ij for diff, total is their sum
  // the first row does not have anything, it starts with 2nd row to compare the numbers
  // where base case ii=k and ij = k*(k-1)

  // start with 3 as 0 invalid, 1 can be anything and i=2 have same=k and diff=k*(k-1)
  for (int i = 3; i <= n; i++)
  {
    // the same is same as diff from prev as you have to add the same color as the last color diff arrangements
    // and choosing same color is 1 way
    same = diff * 1;
    diff = total * (k - 1); //  put any color except the last color so that no 2 same
    total = same + diff;
  }
  cout << "total sum is " << total;
  return 0;
  // make same, diff and total type "long"
}

/*
For 3rd fence we have to see whether the prev arrangement have same 2 colors at last
or different ones. This is what makes the solution for this problem.
For first fence nothing matters but for 2nd fence we have to see whether it will have
same colour or different so make 3 variables =>  same, total and diff.
same stores the ways in which last 2 colors are same as the last 2 colors will only determine what color we can
use. So when we want same color, for i=2, we have k*1 choices as k is times we can choose first color and we can choose the
same color 1 time.
For diff, i=2, we have k*(k-1) ways as first fence is k ways but k-1 for next

Now, for i=3, same will be made of diff as if we include same then it will be 3 same colors breaking the rule,
so you diff value from prev and multiply by 1 as you want the same color as the last of prev and 1 way to do that
so same=diff*1 (prev diff)
and diff is total multiplied by k-1 as we don't want the last and 2nd last to be same.
diff = total*(k-1)
Make the new total = same+diff
*/