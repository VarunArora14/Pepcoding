// https://www.youtube.com/watch?v=0qj4kRcuKqo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=349
#include <iostream>
using namespace std;

int main()
{
  int a[10][10], n, m;
  // Inorder to move 90 degree know that the first row becomes the last column, the 2nd row becomes the 2nd last
  // column and so on
  cin >> n >> m;
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  // do transpose of matrix using a virable and not a new array as space O(1) required

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < m; j++) //  start with i to traverse half times so replace does not revert
    {
      // int temp = a[i][j];
      // a[i][j] == a[j][i];
      // a[j][i] = temp;
      int temp = a[n - j - 1][i];
      a[n - j - 1][i] = a[i][j];
      a[i][j] = temp;
    }
  }
  // Now after the transpose, the first row has the first column but we have to make it as the last
  // column and so we reverse the matrix

  for (int i = 0; i < n; i++)
  {
    int l = 0, r = m - 1;
    while (l < r)
    {
      int temp = a[i][l];
      a[i][l] = a[i][r];
      a[i][r] = temp;
      l++;
      r--;
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      cout << a[i][j] << "\n";
    }
  }
  return 0;
}

/*
It can be easily solved using transpose of a matrix where change the rows of a mtrix with columns.
There is one problem that we may reverse 2 elements twice so traverse either the left triangle
or right triangl of the array

Find the transpose of the matrix by swapping nums[i][j] with nums[j][i] such that -
1 2 3      1 4 7
4 5 6  =>  2 5 8
7 8 9      3 6 9

Now for each row, reverse it such that the answer is the 90 degree rotated matrix

3 6 9
2 5 8
1 4 7
*/