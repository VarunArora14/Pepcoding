// https://www.youtube.com/watch?v=vfNlLP-oOUg&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=288
#include <iostream>
#include "vector"
#include "stack"
#include "climits"
using namespace std;

class node
{
public:
  int val;
  vector<node *> children;
  // making them node* is better as we create a pointer to the node and not the node
};

void disp(node *n)
{
  // display the curr node roo and it's children
  cout << n->val << " ->";
  for (auto i : n->children)
  {
    cout << i->val << ", ";
  }
  cout << "\n";

  // now print it's children's successors recursively like a tree
  // It calls all it's children once only as it goes from root to leaves
  for (auto child : n->children)
  {
    disp(child); // calling the disp() to print all the successors of each child
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
      node *temp = new node; // using node* as * means reference and new operator gives reference to that value
      temp->val = a[i];
      // children are vectors so by default empty
      if (s.empty())
      {
        roo = temp;
      }
      else
      {
        // find the s.top() and push it as it's child
        s.top()->children.push_back(temp);
      }
      // push temp in s always as temp will be the new s.top() whose child would be next ele or would be popped
      s.push(temp);
    }
  }
  return roo;
  // decide if you want to display or not
  // disp(roo);
}

// create a function multisolver that returns the MAX, HEIGHT, MIN and SIZE of the tree
// create static initial values for all
int tree_size, tree_height, min_node, max_node;
// The above variables are in heap and do not have to be passed in recursion unlike for each function before we
// called recursively
void multisolver(node *roo, int depth)
{
  tree_size++;
  min_node = min(min_node, roo->val);
  max_node = max(max_node, roo->val);
  tree_height = max(tree_height, depth);
  // Know how depth and height works, height in heap, depth in stack bcos of local variable and recursion
  for (auto i : roo->children)
  {
    multisolver(i, depth + 1);
  }
}
/*
At start the values are set for size, min_node, max_node and tree_height. At start, depth is 0
Then going fown to 20, depth is 1, at 50 depth is 2. Going back, the depth will change as we go to 20 where it is 1
In stack, parameter passed gets removed once it gets popped after function call ends whereas value in heap always stays

Here we are working in preorder, changing the size and other values before the recursive call
*/

int main()
{
  int a[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
  int n = sizeof(a) / sizeof(a[0]);

  // set default value for multisolver
  node *roo = insert(a, n);
  tree_size = 0;
  tree_height = 0;
  min_node = INT_MAX;
  max_node = INT_MIN;
  multisolver(roo, 0);
  cout << "\nThe size is " << tree_size << "\n"
       << "The height is " << tree_height << "\n"
       << "The min node is " << min_node << "\n"
       << "The max node is " << max_node << "\n";
  return 0;
}