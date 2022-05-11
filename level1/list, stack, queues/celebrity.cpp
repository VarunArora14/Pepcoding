// https://www.youtube.com/watch?v=iHM1FPLGcsU&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=125
#include <iostream>
#include "vector"
#include "stack"
using namespace std;

void stack_sol(vector<vector<int>> a, int n)
{
  stack<int> s;
  // Our approach would be to go through each row and find if it contains all zeroes,
  // then for those rows that contain 0's only, we check if all columns except i==j hace 1 and if yes, return index
  // of celebrity. So here we use eliminiation approach. pop 2 elements from the stack where we push
  // all indexes and see if a[i] and [j] know each other or not, and one will be eliminated.
  // if i does not know j, then j is not a celebrity so pop j, push i. Then pop i and k from stack
  // if i knows k then i is not a celebrity by any chance and keep doing this
  // The last element in stack cannot confirm if it is a celebrity or not, we need to check that at the end

  for (int i = 0; i < n; i++)
  {
    s.push(i);
  }
  // push all the ele index in the stack
  while (s.size() >= 2)
  {
    int i = s.top();
    s.pop();
    int j = s.top();
    s.pop();

    // check if i knows j
    if (a[i][j] == 1)
    {
      // i->j
      // if i knows j, then i is not a celebrity as j must be 0 for celebrity probability
      s.push(j);
    }
    else
    { // j->i
      // if i does not know j then j is not a celebrity i.e. if a[i][j]=0 means i does not know j
      // which also means j cannot be a celebrity
      s.push(i);
    }
  }
  // when the last 2 ele will be left, we will pop again the non-celebrity and at the end we will have 1 ele left
  // which is the potential ele. Pop it and check if it's row and column satisfy the condition
  int pos = s.top();
  int flag = 0;

  // check if pos knows anyone or not
  for (int i = 0; i < n; i++)
  {
    // every i must know pos except pos
    // check if every i knows pos and every pos does not know i except when i==pos
    if (i != pos)
    {
      if (a[i][pos] == 0 || a[pos][i] == 1)
      {
        // if any ele does not know pos or pos knows any ele then print no celebrity found
        cout << "no celebrity";
        return;
      }
    }
    // the cell i==pos is not much relevant so we can ignore that
  }
  cout << "celebrity found at " << pos;
}

int main()
{
  vector<vector<int>> a = {{0, 1, 0},
                           {0, 0, 0},
                           {0, 1, 0}};
  int n = a.size();
  // for the columns we have n = a[i].size() but here all are the same
  stack_sol(a, n);
  return 0;
}