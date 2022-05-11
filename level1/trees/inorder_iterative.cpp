#include <iostream>
#include "stack"
using namespace std;

class node
{
public:
  int val;
  node *left;
  node *right;

  node(int val)
  {
    this->val = val;
    right = left = nullptr;
  }
};

void inorder(node *roo)
{
  stack<node *> s;
  node *curr = roo;

  // push the left ele till left nullptr or stack empty as outer condition
  while (curr != nullptr || !s.empty())
  {
    while (curr != nullptr)
    {
      s.push(curr);
      curr = curr->left;
    }
    // till here we must be on leftmost node, now print val and go right. Also curr is null here
    curr = s.top();
    s.pop();
    cout << curr->val << " ";

    // Now we have to go right subtree
    curr = curr->right;

    // if right of curr is nullptr then inner while loop will simply not run and curr will become s.top() which would be 2nd last curr->left
    /// otherwise if right has a pointer then it will put on top of stack and move to left 
  }
}

int main()
{
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);

  inorder(root);
  return 0;
}

/*
In inorder traversal, we keep going left and then  we print the nodes and then we print the right nodes
Recursive code -
inorder(curr->left)
cout<<curr->val<<" ";
inorder(curr->right)

For the current iterative case, we use stack to first go all left till not null, then print and go right
*/