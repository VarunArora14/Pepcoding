// https://www.youtube.com/watch?v=EFgLdaBSpSw&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=151
#include <iostream>
using namespace std;

class node
{
  // pointer to next node
public:
  node *nex;
  int data;
};

node *create(int val)
{
  node *temp = new node;
  temp->data = val;
  temp->nex = nullptr;
  return temp;
}
// Either make the return type node* and return head or pas node** in the function. Here we use node**
void push_end(int data, node **head)
{
  node *temp = create(data);
  if (*head == nullptr)
  {
    *head = temp;
  }
  else
  {
    while ((*head)->nex != nullptr)
    {
      (*head) = (*head)->nex;
    }
    (*head)->nex = temp;
  }
}

void show(node *head)
{
  if (head == nullptr)
  {
    cout << "the list it empty\n";
  }
  else
  {
    while (head != nullptr)
    {
      cout << head->data << " ";
      head = head->nex;
    }
  }
}

// here also we have **head as passed by reference, If you want to pas *head then make the return type of func as node*
void pop_first(int data, node **head)
{
  if (*head == nullptr)
  {
    cout << "empty list cannot have ele removed";
  }
  else
  {
    node *temp = *head;
    (*head) = (*head)->nex;
    delete temp;
  }
}

int main()
{

  return 0;
}