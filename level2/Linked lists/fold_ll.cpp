// https://www.youtube.com/watch?v=fNhdeMLah0I&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=4
#include <iostream>
using namespace std;

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

node *mid_ll(node *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  node *fast, *slow;
  fast = slow = head;
  while (fast->next != nullptr && fast->next->next != nullptr)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
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

node* fold_ll(node* head)
{

}

int main()
{
  node *head = nullptr;
  insert_end(&head, 1);
  insert_end(&head, 2);
  insert_end(&head, 3);
  insert_end(&head, 4);
  insert_end(&head, 5);
  insert_end(&head, 6);

  return 0;
}

/*
Consider 1->2->3->4->5->6 changes to
1->6->2->5->3->4

For 1->2->3->4->5 ans is 1->5->2->4->3

We have to use extra space here and we can do so by using stack. We traverse the LL and push the elements onto the stack such that at the end, the
last element on top of stack and while entering we note the number of elements in LL too
*/