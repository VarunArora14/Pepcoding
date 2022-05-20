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