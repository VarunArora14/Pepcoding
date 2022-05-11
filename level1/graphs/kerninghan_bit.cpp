// https://www.youtube.com/watch?v=I475waWiTK4&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=42
#include <iostream>
using namespace std;

int main()
{

  return 0;
}
/*
Bad way is to check for each bit and counter++
Good way is to like before, use rsbm (right set bit mask) The rsbm of a num will have all the bits 0 except the last set bit
Now, for x, find the rsbm and subtract it from x till x is 0 and do count++ for counting bits
*/