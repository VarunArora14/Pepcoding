// https://www.geeksforgeeks.org/iterative-preorder-traversal/
// https://www.youtube.com/watch?v=5ry6gRrzPqc&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=306
// TODO:Unable to Solve in C++ as top_node variable copied the s.top() and any change in it didn't make it through
#include <iostream>
#include "stack"
#include "vector"
#include "climits"
#include "string"
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

class PairNode
{
public:
  node *curr;
  int state;
  PairNode(node *curr, int state)
  {
    // default constructor, make state as -1 and curr a node with value passed
    this->curr = curr;
    this->state = state;
  }
};

// The main problem lies in using PairNode as we need a pointer to stack.top() but we can't store
// the node, we have to store either the pointer to it or find ways to point to the memory and then change things
// Dont use PairNode but pointer like PairNode* n_node = new PairNode(roo,-1)

void traversal(node *roo)
{
  stack<PairNode *> s;
  PairNode *n_node = new PairNode(roo, -1);
  s.push(n_node);
  string preorder, postorder;
  preorder = postorder = "";
  while (!s.empty())
  {
    PairNode *top_node = s.top();

    if (top_node->state == -1)
    {
      string curr_str = to_string(top_node->curr->val);
      preorder += curr_str + " ";
      top_node->state++;
    }
    else if (top_node->state == top_node->curr->children.size())
    {
      string curr_str = to_string(top_node->curr->val);
      postorder += curr_str + " ";
      s.pop();
    }
    else
    {
      PairNode *cp = new PairNode(top_node->curr->children[top_node->state], -1);
      s.push(cp);
      top_node->state++;
    }
  }
  cout << preorder << "\n"
       << postorder;
}

int main()
{
  int a[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40};
  int n = sizeof(a) / sizeof(a[0]);

  node *roo = insert(a, n);
  disp(roo);

  traversal(roo);

  return 0;
}

// The below code is commented as it contains many comments and has lesser clarity
// void traversal(node *roo)
// {
//   // first go preorder, make state from -1 to 1 after storing in string
//   stack<PairNode *> s;
//   // first push the first ele as the base case
//   PairNode *n_node = new PairNode(roo, -1);
//   s.push(n_node);
//   string preorder, postorder;
//   preorder = postorder = "";
//   while (!s.empty())
//   {
//     // One big problem that top_node.state value goes back to -1
//     // The below line makes the top_node state value -1 again idk why, reason is we used node before
//     // and not pointer to the node. Rather than using and pushing PairNode, use PairNode* pointer to
//     // that memory location otherwise code will not work properly
//     PairNode *top_node = s.top();

//     // when no child has been seen as visited node first time
//     if (top_node->state == -1)
//     {
//       string curr_str = to_string(top_node->curr->val);
//       preorder += curr_str + " "; //  push the ele in preorder and chnge the state if -1
//       // change the state as preorder done
//       top_node->state++;
//       // cout << "now the topnode state is " << top_node.state << "\n";
//     }
//     // when all children visited
//     else if (top_node->state == top_node->curr->children.size()) // when state of top node is same as the children it has
//     {
//       // add to postorder string and then pop()
//       string curr_str = to_string(top_node->curr->val);
//       postorder += curr_str + " ";
//       s.pop(); //  pop the top as element and it's children all visited till now. no need to change any state as
//       // we did that when we are on that element
//     }
//     // when traverse the children of current node
//     else
//     {
//       // push the children of current node in stack through new child pair
//       PairNode *cp = new PairNode(top_node->curr->children[top_node->state], -1);
//       //  create a new pair node to be pushed in the stack
//       s.push(cp);
//       top_node->state++;
//     }
//   }
//   // now print the preorder and postorder
//   cout << preorder << "\n"
//        << postorder;
//   //  This prints the correct preorder and postorder traversal
// }

/*
Preorder => print the ele, state++
0 to child.size()-1 => push in stack, state++
Potorder - child.size() => pop from stack(as either no children or gone through all)


Here inorder to go iterative way where we simply have the root and we traverse to get the preorder in iterative way,
we push pair of elements in the stack where pair is node and it's state. If state is -1 then that node is visited first time
(preorder traversal) and now traverse all it's children from 0 to curr->children.size()-1, push in the stack
if state value children.size() then in postorder traversal.

For the a[]={10, 20, -1, 30, 50, -1, 60, -1, -1, 40}
First push 10 in stack, print 10 and change state from -1 to 0. Currently we are in preorder
Go to 20, print 20 as preorder, change it's state from -1 to 0 and make state of 10 as 1 as we have pushed the 0th child
and now on the 1st one. Now, childre.size() of 20 is 0so it comes in postorder(as we didn't go in the push child method of 20).
Print the postorder of 20(store in postorder string) and pop it from the stack.
You increase the state after preorder and po from the stack at postorder, now we come to 10 as the new top of the stack
It's state is 0 means not preorder, nor it's state is 3(it's children size), now as state of 10 is 1, push the 1st child i.e. 30
30 is on top of stack with state -1, print the preorder, make state 0, Then push the 0th child in stack and state++
and push 50,-1, print preorder, make state=0. Then since state not -1, and children.size()==0, this is postorder of 50
and pop it, top() is now 30 with state 1 so push it's another child 60 and so on.
*/