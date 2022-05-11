// https://www.youtube.com/watch?v=NdaEQPlH1vE&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=146
#include <iostream>
#include "queue"
using namespace std;
#define MAX 100

class Q
{

public:
  int *a;
  int Maxval;
  int front;
  int qsize;

  Q(int size)
  {
    this->Maxval = size;
    this->a = new int[Maxval];
    front = qsize = 0;
  }

  // default contructor important
  // Q()
  // {
  //   Q(10);
  // }

  int size()
  {
    // print size of queue
    return qsize;
  }

  void add(int data)
  {
    // add new data to queue if space available

    if (qsize == Maxval)
    {
      cout << "overflow\n";
    }
    else
    {
      int rear = (front + qsize) % Maxval;
      // as for case when we move front foward, the initial position of array becomes empty
      a[rear] = data;
      qsize++;
    }
  }

  int head()
  {
    // print the head of queue
    if (qsize == 0)
    {
      cout << "empty queue. underflow\n";
      return -1;
    }
    else
      return a[front];
  }

  int remove()
  {
    // remove first ele from queue
    if (qsize == 0)
    {
      cout << "underflow";
      return -1;
    }
    else
    {
      int val = a[front];
      (front++) % Maxval;
      // to avoid case when size of queue smaller than maxval but front value high
      qsize--;
      return val;
    }
  }

  void display()
  {
    // print the queue
    for (int i = 0; i < qsize; i++)
    {
      int pos = (front + i) % Maxval;
      cout << a[pos] << " ";
    }
    cout << "\n";
  }
};

int main()
{
  int n;
  cin >> n;
  Q q(n);
  queue<int> x;
  string str;
  cin >> str;

  while (str != "quit")
  {
    if (str == "add")
    {
      int val;
      cin >> val;
      q.add(val);
    }
    else if (str == "remove")
    {
      int val = q.remove();
      if (val != -1)
      {
        cout << val << endl;
      }
    }
    else if (str == "head")
    {
      int val = q.head();
      if (val != -1)
      {
        cout << val << endl;
      }
    }
    else if (str == "size")
    {
      cout << q.size() << endl;
    }
    else if (str == "display")
    {
      q.display();
    }
    cin >> str;
  }
  return 0;
}
