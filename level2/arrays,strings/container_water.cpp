#include <iostream>
#include "vector"
using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // int n, a[110]; // n is the height
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> a[i];
  // }
  int n;
  cin >> n;
  int a[100000];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int max_area = 0;
  int i = 0, j = n - 1;
  while (i < j)
  {
    int h = min(a[i], a[j]);

    max_area = max((j - i) * h, max_area);
    if (a[i] <= h && i < j)
      i++;
    else
      j--;
  }

  cout << max_area;

  return 0;
}