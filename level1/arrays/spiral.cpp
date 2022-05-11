// https://www.youtube.com/watch?v=UPEZBPh1UcU&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=345
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

  int i, j, i_start = 0, i_end = n - 1, j_start = 0, j_end = m - 1;
  i = i_start;
  j = j_start;
  int total = n * m;
  int c = 0;
  // make a counter and total_count as some ele do repeat let's say in 3*5 table, one ele came extra
  // put the check in loop also
  while (c < total)
  {
    for (i = i_start, j = j_start; i <= i_end && c < total; i++)
    {
      cout << a[i][j] << "\n"; //  print first column
      c++;
    }
    j_start++; //  because everytime we go top to down, for next time, the j_start cannot point to same place

    for (j = j_start, i = i_end; j <= j_end && c < total; j++)
    {
      cout << a[i][j] << "\n"; //  print the bottom row
      c++;
    }
    i_end--;                                                   //  because everytime we go right at bottom, we have to do it one layer up row end becomes less
    for (i = i_end, j = j_end; i >= i_start && c < total; i--) //  this was i++
    {
      // cout << "hello";
      cout << a[i][j] << "\n";
      c++;
    }
    j_end--;
    // for a 3*5 loop, the loop goes from below loop and print 1 extra ele as no check for count
    for (j = j_end, i = i_start; j >= j_start && c < total; j--)
    {
      // cout << "here j is " << j << " i is " << i << " j_end is " << j_end << " i_start is " << i_start << " j_start is " << j_start << "\n";
      cout << a[i][j] << "\n";
      c++;
    }
    i_start++;
  }

  return 0;
}
// If i_end comes close to i_star or j_end comes close to j_start such that their diff is 1, exit the while loop

/*
Here we have the array which we traverse in spiral, for that we have 4 positions, i_start, i_end
,j_start and j_end. Then start the 2 for loops with inner as j and then have if conditions within

make a while loop where beak condition is when i==j

1. if(i==i_start && j==j_start)
{
  go down meaning i++ in loop
  outside loop increase j_start as you won't have to go to it again
}
Similarly,

2.  make the next if condition as if i==i_end and j==j_start then
*/