// https://www.youtube.com/watch?v=GjhGhEoZ1Vk&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=5
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

void unfold(node *head)
{
  stack<node *> st;
  node *ptr = head;
  while (ptr && ptr->next)
  {
    st.push(ptr->next);
    ptr->next = ptr->next->next; // make ptr->next point to 3rd node
    ptr = ptr->next;             // important
  }
  // at this point we have ptr either at nullptr or ptr->nullptr

  if (ptr == nullptr)
  {
    cout << "hello";
    node *curr = st.top();
    ptr = curr;
    st.pop();
  }
  while (!st.empty())
  {
    node *nex = st.top();
    ptr->next = nex;
    ptr = ptr->next;
    st.pop();
  }
  ptr->next = nullptr;
}

int main()
{
  node *head = nullptr;
  insert_end(&head, 1);
  insert_end(&head, 6);
  insert_end(&head, 2);
  insert_end(&head, 5);
  insert_end(&head, 3);
  insert_end(&head, 4);

  unfold(head);
  print(head);
  return 0;
}
/*
idea is to travel ll and for alternate elements, push them into stack and curr->next = curr->next->next till size/2
we will make 2 pointers h1 and h2 pointing to the head of alternate elements, we make h1->next = h1->next->next
*/