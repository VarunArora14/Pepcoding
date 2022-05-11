// https://www.youtube.com/watch?v=nUUc9DKTBdY&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=343
#include <iostream>
using namespace std;

int main()
{
  int a[10][10] = {0};
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  bool flag = true; //  true means down, flase means up
  for (int j = 0; j < m; j++)
  {
    for (int i = 0; i < n; i++)
    {
      // i and n of row and inner loop
      int val = flag == true ? a[i][j] : a[n - 1 - i][j];
      cout << val << "\n";
    }

    flag = !flag;
  }
  return 0;
}
/*
In this traversal we have inner loop as i which will print output based on flag
which will keep changing it's value when either j=0 or j=m-1 is met.
*/