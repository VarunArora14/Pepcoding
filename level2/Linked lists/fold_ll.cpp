// https://www.youtube.com/watch?v=fNhdeMLah0I&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=4
#include <iostream>
#include "stack"
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

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << "\n";
}

void fold_ll(node *head)
{
  stack<node *> st;
  node *temp = head;
  int qsize = 0;
  while (temp)
  {
    st.push(temp);
    temp = temp->next;
    qsize++;
  }
  // push ele in stack such that last ele at top and stack in last to first manner so we can fold ll
  node *ptr = head;
  for (int i = 0; i < qsize / 2; i++)
  {
    // <qsize/2 will work as last ele we insert from top of stack will be mid ele at qsize/2 index
    node *top_ele = st.top();
    st.pop();

    top_ele->next = ptr->next;
    ptr->next = top_ele;
    // go to 3rd ele now which was ptr->next before to do the same
    ptr = ptr->next->next;
  }
  ptr->next = nullptr; // so that the last ele which would be the mid ele does not point to other ele and we go in loop forever as we changed the pointers
}
/*
for curr ele at ptr, find the top_ele which is last ele located at st.top(), make top_ele->next as ptr->next so that 4->2 of initial 1->2->3->4
*/

int main()
{
  node *head = nullptr;

  insert_end(&head, 1);
  insert_end(&head, 2);
  insert_end(&head, 3);
  insert_end(&head, 4);
  insert_end(&head, 5);
  insert_end(&head, 6);
  fold_ll(head);
  print(head);
  return 0;
}

/*
Consider 1->2->3->4->5->6 changes to
1->6->2->5->3->4

For 1->2->3->4->5 ans is 1->5->2->4->3

We have to use extra space here and we can do so by using stack. We traverse the LL and push the elements onto the stack such that at the end, the
last element on top of stack and while entering we note the number of elements in LL too

For folding the LL, we first make a stack and store all the ele in reverse order in it so that top ele is the last and count size of LL.
Then we go till size/2 and for each ele, find
topele = s.top();
s.pop();
topele->next = curr->next;
curr->next=topele;

curr=curr->next->next; // for 3rd ele as first 2 done

at the end of loop, make curr->next=nullptr so no repetition
*/