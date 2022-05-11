// https://www.youtube.com/watch?v=GIA2cZgOdwg&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=303
#include <iostream>
#include "stack"
#include "vector"
#include "climits"
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

int dia;

int calcDiaHeight(node *roo)
{
  //  -1 for base case
  int dc, sdc;
  dc = sdc = -1; //  declaring the deepest and second deepest child height as -1
  for (auto i : roo->children)
  {
    int ch = calcDiaHeight(i);
    if (ch > dc)
    {
      sdc = dc;
      dc = ch;
      // if ch > deepest, update deepest and 2nd deepest as prev dc value

      // this will give the height of the deepest child, but we need height of both deepest and 2nd deepest
    }
    else if (ch > sdc)
    {
      sdc = ch;
      // check if 2nd deepest has smaller value than ch
    }
    // else doesnt matter as if value less than deepest and 2nd deepest, it is useless

    // We do +2 bcos it is passing through the curr node so edge to that from both child nodes would also be considered
    // as part of the diameter
  }
  // dc+sdc+2 is a candidate for deepest child height
  // Calculate the candidate in postorder
  if (dc + sdc + 2 > dia)
  {
    dia = dc + sdc + 2;
  }
  // make sure to increase the dch+1 as the your height is 1 + deepest child height
  dc += 1;
  return dc;
}

int main()
{
  int a[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
  int n = sizeof(a) / sizeof(a[0]);

  node *roo = insert(a, n);
  disp(roo);
  cout << "\n";
  dia = 0;
  calcDiaHeight(roo);
  cout << dia << "\n";

  return 0;
}
/*
Here we find the diameter of a generic tree which is the longest distance between 2 nodes of the tree
For this, we know the longest distance path will not necessarily pass through the root of the tree, so find 2 nodes such that
they are deepest and 2nd most deepest from the root of the tree. Find the height of subtrees of root and then
the sum of largest and 2nd largest height of children of root will be the diameter of the tree.
Since there can be a case when two subtrees somewhere in the middle of the tree can have largest distance b/w each other
focus on finding the heights of subtrees and then adding the 2 longest heights.
There can be 2 cases - 1. The deepest and 2nd deepest child of a + 2 gives the diameter(passing through a)
2. Path without passing through root, in a subtree

So calculate for every node the deepest child and 2nd deepest child
*/