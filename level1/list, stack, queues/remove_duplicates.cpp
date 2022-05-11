#include "iostream"
using namespace std;

// node definition which can be initialized through objects
class node
{
public:
  int inf;
  node *nex;
};

void push_start(node **head, int data) // insert at head
{
  node *temp = new node;
  temp->inf = data;
  temp->nex = *head;
  *head = temp;
}

void push_end(node **head_node, int data) // insert at end
{
  node *temp = new node;
  node *last = *head_node;
  temp->inf = data;
  temp->nex = nullptr;
  if (*head_node == nullptr)
  {
    *head_node = temp;
    return;
  }
  while (last->nex != nullptr)
  {
    last = last->nex;
  }

  last->nex = temp;
  return;
}

void show(node *h) // print the list
{
  if (h == nullptr)
  {
    cout << "the list is empty";
  }
  else
  {
    while (h != nullptr)
    {
      cout << h->inf << " ";
      h = h->nex;
    }
  }
}

// We can create another reverse func which swaps the value of start and end of ll till left<right

node *reverse(node *head) // reverse a list
{
  struct node *curr, *next, *prev;
  curr = head;
  prev = nullptr;
  while (curr != nullptr)
  {
    next = curr->nex;
    curr->nex = prev;

    prev = curr;
    curr = next;
  }
  head = prev;
  return head;

  // head = reverse(head); as the function in main()
}

// inorder to print or find the kth element acknowledge that we don't have size value and can only move forward
// so make 2 pointers, f and s. Considering k<size of list, move s variable k times forward
// then move f and s till s meets null. At that point, f is kth ele from end
int k_ele(int k, node *start)
{
  node *f, *s;
  f = s = start;
  for (int i = 0; i < k; i++)
  {
    s = s->nex;
  }
  while (s != nullptr)
  {
    f = f->nex;
    s = s->nex;
  }
  return f->inf;
}

node *del(node *start) // delete node at head
{
  if (start == nullptr)
  {
    cout << "Empty linked list so nothing can be deleted";
    exit(0);
  }
  else if (start->nex == nullptr)
  {
    cout << "element deleted. Now the list is empty";
    start = nullptr;
  }
  else
  {
    node *temp = new node;
    temp = start;
    start = start->nex;
    delete temp;
  }
  return start;
}

void remove_duplicates(node **head)
{
  node *f, *s;
  // Here we move in forward from 1st ele till end and if we find s->val == f->val, pass delete func and move f to s
  f = s = *head;
  while (s != nullptr)
  {
    s = s->nex;
    if (s->inf == f->inf)
    {
      node *temp = f;
      // change f
      f = s; // list is sorted
      delete temp;
    }
  }
}

void del_any(node **head, int pos)
{
  // make sure that pos less than size
  if (*head == nullptr)
    return;
  node *temp;
  if (pos == 0)
  {
    // del at start
    temp = *head;
    *head = temp->nex;
    delete temp;
  }

  // reach the node just before pos one
  for (int i = 0; temp != nullptr && i < pos - 1; i++)
  {
    temp = temp->nex;
  }
  // check if pos > num of nodes
  if (temp == nullptr || temp->nex == nullptr)
    return;
  node *next = temp->nex->nex;
  delete temp->nex;
  temp->nex = next;
}

int main()
{
  node *head = nullptr;
  push_start(&head, 2);
  push_start(&head, 3);
  push_start(&head, 4);
  push_end(&head, 1);
  cout << "\n";
  show(head);
  head = reverse(head);
  cout << "\n";
  show(head);
  return 0;
}