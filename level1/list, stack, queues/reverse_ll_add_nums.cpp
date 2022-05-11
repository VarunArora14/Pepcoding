#include "iostream"
#include "stack"
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

// Add 2 lists
node *addList(node *l1, node *l2)
{
  // create stack for iterative solution, full here - https://www.geeksforgeeks.org/sum-of-two-linked-lists/
  stack<int> s1, s2;
  // push their value in stack s1 and s2 as the LSB on top of stack as there we have to calc
  while (l1 != nullptr)
  {
    s1.push(l1->inf);
    l1 = l1->nex;
  }
  while (l2 != nullptr)
  {
    s2.push(l2->inf);
    l2 = l2->nex;
  }
  int carry = 0;
  node *res = nullptr;
  while (!s1.empty() || !s2.empty())
  {
    int a = 0, b = 0;
    if (!s1.empty())
    {
      a = s1.top();
      s1.pop();
    }
    if (!s2.empty())
    {
      b = s2.top();
      s2.pop();
    }
    int total = a + b + carry;
    node *temp = new node();
    temp->inf = total % 10;
    carry = total / 10;
    if (res == nullptr)
      res = temp;
    else
    {
      // inesrtion at head and not tail as we are going from right to left
      temp->nex = res;
      res = temp;
    }
  }
  // if carry still has value even after the loop then we will have to create a new node and add to the head of list with that value
  if (carry != 0)
  {
    // when using new keyword, it does not return object but reference to the object. Without new keyword like obj(10,"val")
    // you are allocating it in stack whereas with new, data in heap with large space and it's pointer in stack which we use here
    node *temp = new node();
    temp->inf = carry;
    temp->nex = res;
    res = temp;
  }
  return res;
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