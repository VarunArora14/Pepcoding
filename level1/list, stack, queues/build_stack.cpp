#include <iostream>
#include "vector"
#include <exception>
using namespace std;
#define MAX 100

class Stack
{

public:
  vector<int> v;
  int tos;
  int MaxCapacity;

  Stack(int size)
  {
    // constructor makes the top as -1 and vector of size 'size' initalised at 0
    v.assign(size, 0);
    MaxCapacity = size;
    this->tos = -1;
  }

  // Stack()
  // {
  //   Stack(10);
  // }

  int size()
  {
    // write your code here
    return v.size();
  }

  void push(int data)
  {
    // write your code here
    if (tos < MaxCapacity - 1)
    {
      v.push_back(data);
    }
    else
    {
      cout << "Stack overflow";
    }
  }

  int top()
  {
    // write your code here
    cout << v.back() << "\n";
  }

  int pop()
  {
    // write your code here
    if (!v.empty())
    {
      v.pop_back();
    }
  }

  void display()
  {
    // write your code here
    while (!v.empty())
    {
      cout << v.back() << " ";
      v.pop_back();
    }
  }
};

int main()
{
  int n;
  cin >> n;
  Stack st(n);
  string str;
  cin >> str;

  while (str != "quit")
  {
    if (str == "push")
    {
      int val;
      cin >> val;
      st.push(val);
    }
    else if (str == "pop")
    {
      int val = st.pop();
      if (val != -1)
      {
        cout << val << endl;
      }
    }
    else if (str == "top")
    {
      int val = st.top();
      if (val != -1)
      {
        cout << val << endl;
      }
    }
    else if (str == "size")
    {
      cout << st.size() << endl;
    }
    else if (str == "display")
    {
      st.display();
    }
    cin >> str;
  }
}