// https://www.youtube.com/watch?v=XZueXHOhO5E
#include <iostream>
using namespace std;

int main()
{

  return 0;
}
/*
Given array, find the max partitions such as those partitions are sorted.

Here we use the chaining technqiue -
Consider indices and numbers like
0 1 2 3 4 5
1 0 2 4 3 5

The impact of 1 will be max till index 1(0 and 1), 0 till index 1 as that is it's position, 2 till 2(0,1,2) and 4 till index 4(0 to 4)
So we make 4 chunks like - 0 1 | 2 | 4 3 | 5
and if we sort these chunks our array would be sorted. Here we are finding the max participation a number can give which is max till it's
index. If a number x is at index i where x<i then max pariticipation of x till index i only.
Consider another -
idx: 0 1 2 3 4 5
num: 2 0 1 4 3 5

max 2 can go is idx=2, 0 can go till 1, 1 can go till idx=2
4 can go till idx=4, 3 till idx=4, 5 till idx=5

So, we keep a max variable. For first number it stores the max index it can make impact to. At i=0, max=2(for 2)
at i=1, max remains same as 2>1, at i=2, max remains 2 as 1 can impact till idx=2. Now, we are at i=2 and max is 2. Now, we cannot go further
with as max and index are both same, no chunk can be bigger than the current idx which is constantly increasing.


*/