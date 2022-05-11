#include <iostream>
#include "vector"
using namespace std;

int main()
{
  // initial array is all 0, just input length and then the update[]
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int len, q_len, a[100000] = {0};
  for (int i = 0; i < 100; i++)
  {
    a[i] = 0;
  }
  int query[100000][3];
  // len for empty array and q_len for query length
  cin >> len >> q_len;
  for (int i = 0; i < q_len; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> query[i][j];
    }
  }
  // query[i][0] is for start index, query[i][1] is for end, query[i][2] for num to be added

  for (int i = 0; i < q_len; i++)
  {
    for (int j = query[i][0]; j <= query[i][1]; j++)
    {
      a[j] += query[i][2];
    }
  }

  for (int i = 0; i < len; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}