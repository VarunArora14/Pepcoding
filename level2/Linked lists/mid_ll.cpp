// https://www.youtube.com/watch?v=aiFAbMOHqIc&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=2
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
  // base case for null and single ele
  if (head == nullptr || head->next == nullptr)
    return head;

  node *fast, *slow;
  fast = slow = head;
  // fast will travel 2 nodes, slow will travel 1
  // fast->next->next important as without that code will stop once fast crosses the nullptr(after the last ele) without checking
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

int main()
{
  node *head = nullptr;
  insert_end(&head, 1);
  insert_end(&head, 2);
  insert_end(&head, 3);
  insert_end(&head, 4);
  insert_end(&head, 5);
  insert_end(&head, 6);
  print(head);
  node *mid = mid_ll(head);
  cout << mid->val;

  return 0;
}