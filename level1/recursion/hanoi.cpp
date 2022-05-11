// https://www.youtube.com/watch?v=QDBrZFROuA0&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=383
#include <iostream>
using namespace std;

// t1 is from, t2 is dest and t3 is aux
void hanoi(int n, int t1id, int t2id, int t3id)
{
  // first call makes n-1 disks go to c
  if (n == 0)
    return;
  hanoi(n - 1, t1id, t3id, t2id);
  // will print the instructions to move n-1 disks from t1 to t3 using t2(follow rules of hanoi)
  // Now we have nth disk so move that to destination and print the instruction
  cout << n << "+[" << t1id << " -> " << t2id << "]";
  // Then we print the instructions to mmove the nth disk to B
  // now move the n-1 disks in C to B
  hanoi(n - 1, t3id, t2id, t1id);
}
int main()
{

  return 0;
}
/*
Expectation: if we pass func(3,a,b,c) then somehow all discs will come on b using c
to move discs and instructions would be followed.

Faith: func(2,a,b,c) knows to print the correct instructions


Now meet faith with expectations, for pillars a,b and c, we know that for putting
the tower on b we need to call the func(2,a,b,c). Sor 3 pillars,
1. we need to call func(2,a,b,c) which puts the 1 and 2 blocks on c and now,
2. we move 3rd block on b and
3. move the 1 and 2 blocks from c to b using func(2,c,b,a). Note - first variable
is for starting point, second for destination and 3rd the aux as a medium to achieve that.
Since we need to move 2 pillars from c to b using a we do func(2,c,b,a)

If tower of hanoi knows how to print instructions to move 2 discs then can we make hanoi
to print the instructions to move 3 discs?
*/