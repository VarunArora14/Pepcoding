// https://www.youtube.com/watch?v=vfNlLP-oOUg&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=288
#include <iostream>
#include "stack"
#include "vector"
using namespace std;

class node
{
public:
  int val;
  vector<node *> children;
};

void disp(node *roo)
{
  cout << roo->val << " -> ";
  for (auto i : roo->children)
  {
    cout << i->val << ", ";
  }
  cout << "\n";
  for (auto child : roo->children)
  {
    disp(child);
  }
}

node *insert(int a[], int n)
{
  stack<node *> s;
  node *roo = nullptr;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == -1)
    {
      s.pop();
      // simply pop the value
    }
    else
    {
      node *temp = new node;
      temp->val = a[i];
      if (s.empty())
      {
        roo = temp;
      }
      else
      {
        s.top()->children.push_back(temp);
      }
      s.push(temp);
    }
  }
  return roo;
}

// find the predecessor and successor of nodes from the preorder traversal order
// for node 110, the predecessor is 80 and successor is 120
// easy way is to find the preorder list first and then return the prev and next nodes of node to be found
// Use travel and change strategy where you have 2 variables in heap declared them outisde
node *pred = new node;
node *succ = new node;
int state;
// Here you have to understand the way preorder works where you do something and then call the same
// function in recursive manner, we don't have to preorder the roo and then see if the vector<node> has the predecessor
// or not but rather, in single go through all the elements, we can see if there are pred and succ or not
void pred_node(node *roo, int data)
{
  // here keep finding the node and keep making the pred if curr ele not node as when it will be
  // the pred will store the valu of the predecessor
  if (state == 0)
  {
    if (roo->val == data)
    {
      state = 1;
    }
    else
    {
      pred = roo; //  keep changing the pred making it easier to find it rather than another traversal or maitaining
      // node* vector
    }
  }
  //  We have found the node, now store the successor as when state=1, we are on the next node of whose
  // pred and succ have to be found
  else if (state == 1)
  {
    succ = roo;
    state = 2;
  }
  for (auto i : roo->children)
  {
    pred_node(i, data);
  }
}

/*
The pred starts from 10 and keeps changing till the point we have not found the node. If node is 90 then it keeps changing
the value of pred till it is 90, state is 0 and first condition roo->val=90 is met, so change the state to 1. The pred value
has the previous node in preorder stored which is 80. Now, in next call

*/

int main()
{
  int a[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
  int n = sizeof(a) / sizeof(a[0]);

  node *roo = insert(a, n);
  disp(roo);
  cout << "\n";
  pred = nullptr;
  succ = nullptr;
  state = 0; //  0 means no pred found and base case for starting
  // pred_node(roo, 50);
  if (pred == nullptr)
    cout << "pred not found";
  else
    cout << pred->val << "\n";
  if (succ == nullptr)
    cout << "succ not found";
  else
    cout << succ->val;
  return 0;
}