// https://www.youtube.com/watch?v=gRo86WqFYSE&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=5
#include <iostream>
#include "string"
using namespace std;

void sol(string s, int num)
{
  // base case
  int s_num = stoi(s);
  if (s_num >= num)
    return;
  // cout << s_num << "\n";

  cout << s << "\n";

  for (int i = 0; i <= 9; i++)
  {
    sol(s + to_string(i), num);
  }
}

int main()
{

  int num;
  cin >> num;
  for (int i = 1; i <= 9; i++)
  {
    sol(to_string(i), num);
  }

  return 0;
}
/*
Keep adding 0's after 1 till (curr_val < num)  satisfy in recursive function where in the loop
you have from 0 to 9
*/