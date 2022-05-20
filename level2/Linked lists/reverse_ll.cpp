// https://www.youtube.com/watch?v=aiFAbMOHqIc&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=1
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

node *reverse(node *head)
{
  node *prev = nullptr, *curr = head, *nex;
  while (curr != nullptr)
  {
    nex = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nex;
  }
  return prev;
}

void insert_end(node **head, int x)
{
  node *last = *head;
  node *temp = create(x);
  if (*head == nullptr)
  {
    // first ele to be inserted
    (*head)->next = temp;
    return;
  }

  while (last->next != nullptr)
    last = last->next;
  last->next = temp;
  return;
}
int main()
{

  return 0;
}

/*
Understand thing about passing by reference and valur first. If you have to do something like sort where ll does not change then pass by value the head
meaning func(head,x);
If things have to be changed then you have 2 options - 1. Pass by value and make the function return the new head such that head = reverse(head);
where we reverse the LL and return the new head.
2. Pass the reference to the head while making changes and return nothing. reverse(&head);
void reverse(node **head){

}
*/