// https://www.youtube.com/watch?v=mBUcaPvEawI&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=6
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

class node
{
public:
  int val;
  node *next;
};

node *create(int val)
{
  node *curr = new node; // no braces
  curr->val = val;
  curr->next = nullptr;
  return curr;
}

void insert_end(node **head, int x)
{
  node *last = *head;
  node *temp = create(x);
  if (*head == nullptr)
  {
    // first ele to be inserted
    (*head) = temp;
    return;
  }

  while (last->next != nullptr)
    last = last->next;
  last->next = temp;
  return;
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << "\n";
}


int main()
{

  return 0;
}
