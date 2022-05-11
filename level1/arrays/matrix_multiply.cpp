// https://www.youtube.com/watch?v=eLIT5fnKmMI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=341
#include <iostream>
#include "vector"
using namespace std;

int main()
{
  int n1, m1, n2, m2, temp;
  vector<vector<int>> a, b;
  cin >> n1 >> m1;
  // if (n2 != m1)
  // {
  //   cout << "Invalid Output";
  //   exit(0);
  // }

  // Few things to avoid -
  // 1. Don't input a[i][j] as it is not an array and program will just not run, do push_back
  // 2. Don't do a[i].push_back() unles a defined as a(n1) as that will also not work
  // 3. Don't do a[i].push_back(temp_vec) as you re pushing a vector at int place

  for (int i = 0; i < n1; i++)
  {
    // create a temporary vector here and push that vector after each j loop finishes
    vector<int> temp_vec;
    for (int j = 0; j < m1; j++)
    {
      // cin >> a[i][j];  can't just input a[i][j] as it is not an array, use push_back or declare vector as vector<int> a(vec_size)

      cin >> temp;
      temp_vec.push_back(temp); // temp vector for a row
    }
    a.push_back(temp_vec); //  push the temp vector in a for n1 columns
  }

  cin >> n2 >> m2;

  for (int i = 0; i < n2; i++)
  {
    // create a temporary vector here and push that vector after each j loop finishes
    vector<int> temp_vec;
    for (int j = 0; j < m2; j++)
    {
      // cin >> a[i][j];  can't just input a[i][j] as it is not an array, use push_back or declare vector as vector<int> a(vec_size)

      cin >> temp;
      temp_vec.push_back(temp); // temp vector for a row
    }
    b.push_back(temp_vec); //  push the temp vector in a for n1 columns
  }

  if (m1 != n2)
  {
    cout << "Invalid array";
    exit(0);
  }

  vector<vector<int>> ans(n1, vector<int>(m2));
  // matrix multply forms array of size n1*m2
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < m2; j++)
    {
      ans[i][j] = 0;
      for (int k = 0; k < m1; k++)
      {
        ans[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < m2; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
// input format is n1,m1 and the array, then n2,m2 and array
// https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/