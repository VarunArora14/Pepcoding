// https://www.youtube.com/watch?v=FnywCfCcMRk&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=346
#include <iostream>
using namespace std;

int main()
{
  int a[10][10];
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  int dir = 0;
  int i = 0, j = 0;
  // keep adding a[i][j] to dir as it only has 1 as it's value and it's value determines the direction
  // it moves to and based on the direction make if i or j change

  while (true)
  {
    dir = (dir + a[i][j]) % 4;
    if (dir == 0) //  east
    {
      // move right
      j++;
    }
    else if (dir == 1) //  south
    {
      i++;
    }
    else if (dir == 2) //  west
    {
      j--;
    }
    else //  north
    {
      i--;
    }
    // check if outside for either j=m or i=n or i<0 or j<0
    // and print the right i and j. If i<0 do i++ as we have to print the last position and not the breaking
    // point position
    if (i < 0)
    {
      i++;
      break;
    }
    else if (j < 0)
    {
      j++;
      break;
    }
    else if (i == n)
    {
      i--;
      break;
    }
    else if (j == m)
    {
      j--;
      break;
    }
  }
  cout << "i is " << i << " and j is " << j;
  return 0;
}
/*
keep going right till 1 comes, if it does, move 90 degrees clockwise and at the end print
the point where it can exit the matrix

Define conditions,
pos=1,2,3,4
if pos==1 then j++
if pos==2 then i++
if pos==3 then j--
if pos==4 then i--
*/