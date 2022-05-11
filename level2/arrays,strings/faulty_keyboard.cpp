#include <iostream>
using namespace std;

bool faulty(string name, string typed)
{
  // here we start from typed comparing letters with string and if typed has typed[i]==typed[i+1], move forward
  if (name.length() == 0)
    return false;
  int c = typed.length();
  int i = 0, count = 0, b = 0;

  // compare the first ele first
  if (name[0] == typed[0])
  {
    b = 1;
    i = 1;
  }
  else
  {
    return false;
  }

  // not && as both must satisfy the condition
  while (i < c || b < name.length())
  {
    // comparing the current and last typed letter and if they have ocured before

    // if both are same, make count=0
    // cout << "here i is " << i << " b is " << b << " name[i] is " << name[b] << " typed[i] is " << typed[i] << "\n";
    if (name[b] == typed[i])
    {
      b++;
      i++;
    }
    else if (typed[i] == typed[i - 1])
    {
      i++;
    }

    // when both name[b] and typed[i] are not same
    else
    {
      return false;
    }
  }
  return true;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string name, typed;
  cin >> name >> typed;
  bool res = faulty(name, typed);
  if (res)
    cout << "true";
  else
    cout << "false";
  return 0;
}