// https://www.youtube.com/watch?v=XcSr6TIMl7w&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=41
#include <iostream>
#include "bitset"
using namespace std;

int main()
{
  int num;
  cin >> num;

  int rsb_mask = (num & (-num));
  // or rsb_mask= num & (~num+1)
  return 0;
}
/*
Right most set bit mask is in a number when a set bit is the last set bit in the number or when turning off that bit makes it all 0
It can be done in O(1) using rsb = x & x''(2's complement of x)
Let x have A 1's and 0's, then 1 and then B number of 0's [A 1's and 0's] 1 [B 0's]
1's complement of x is A 0's and 1's where the 1's become 0's and 0's become 1's, the next 1 becomes 0 and B 0's become 1's
Adding 1 to 1's complement is 2's complement so x'=~x was [A 0's and 1's] 0 [B 1's]
x'' = x'+1 which makes turns all the 1's of B to 0 and carry bit makes the middle 0 as 1. The A 0's and 1's remain same
x'' = [A 0's and 1's] 1 [B 0's]. Comparing x and x'', The A 0's and 1's have been reversed, the last set bit of both are 1
and all the B's are 0. Taking it's and operation, rsb = x & x'' = [A 0's ] 1 [B 0's]  and now we have the rsb left only

example 72 - 100 1 000. 32 bit x=72 has 25 0's before and then 1001000
x'= ~x = [25 1's] 011 0 111
x'' = (x' + 1) = (~x + 1) = [25 1's] 011 1 000 (1 makes all last 0's 1 and carry makes the rsb as 1)

Another way of writing 2's complement of x is x''= -x

*/