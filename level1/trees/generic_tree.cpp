// https://www.youtube.com/watch?v=9Oi3WamOCPo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=226
// vids 225 to 250 in this
#include <iostream>
#include "vector"
#include "stack"
#include "queue"
#include "algorithm"
// algo for find()

using namespace std;

class node
{
public:
  int val;
  vector<node *> children;
  // making them node* is better as we create a pointer to the node and not the node
};

// disp(10) will print itself and it's family
// disp(20), disp(30), disp(40) will print themselves and their families
// so, disp(10) = self(10) + disp(20) + disp(30) + disp(40)
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

// int size(node *roo)
// {
//   int c = 0;
//   for (auto i : roo->children)
//   {
//     c++;
//   }
//   for (auto child : roo->children)
//   {
//     // call size for each node
//     c += size(child);
//   }
//   return c;
// }
int size(node *roo)
{
  int s = 0;
  for (auto i : roo->children)
  {
    // for each child i, keep find the children and add them in s
    // It will go from left to right
    int cs = size(i);
    s += cs;
  }
  return s + 1;
  // +1 for root
}

/*
Working of size() -
On reaching 10, the root. Then the loop runs for it's children i.e. 20,30,40. It will go to 20 first
and call size(20) and so on. The s+1 helps as for each child we call size() but for a node with no
children at bottom, it should return 1 as itself as we are not counting the children of node first and then
it's successors, we are doing both steps together, so returning s+1 makes sense for all nodes
Function will call root, then for each children of root, call size(child), if it has no children then
returns 1(return s+1) or if it has x num of children then it recursively calls
int cs = size(child) and then stores the value in s later
for [10,20,30] tree has 10->20->30
It makes s=0 and then loop for each child. It calls cs = size(20)
In that, it has 1 child so loop runs again and int cs = size(30)
size(30) returns 1 as it has no children. So we have size(30) popped from function stack and called
size(20) in which int cs=1 as int cs=size(30), s=1 and then return s+1 which is 2
It pops size(20) from stack and then we have size(10) where we have int cs=size(20)
or int cs=2. Then, s+=cs => s+=2 => s=2. Then return s+1 which returns 3
*/

// finding the max, go to each node and have the max value
int max_node(node *roo)
{
  int max_val = roo->val;
  for (auto i : roo->children)
  {
    max_val = max(max_val, max_node(i));
  }
  return max_val;
}

int height(node *roo)
{
  int h = -1;
  for (auto i : roo->children)
  {
    // should not do h+1 inside the loop as height means how many max edges to deepest node
    // and not sum of edges with greater height(i) than before
    int ch = height(i);
    h = max(h, ch);
  }
  h += 1;
  // The h=-1 makes sense for base case and others too as for single node h=0
  return h;
}

// insertion using array a[] of size n
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

// https://www.youtube.com/watch?v=kL6tIGhVW1k&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=236
void generic_traversal(node *roo)
{
  cout << "Node Pre " << roo->val << "\n";
  for (auto i : roo->children)
  {
    cout << "Edge Pre " << roo->val << "--" << i->val << "\n";
    generic_traversal(i);
    cout << "Edge Post " << roo->val << "--" << i->val << "\n";
  }
  cout << "Node Post " << roo->val << "\n";
}

// level order traversal
void level_order(node *roo)
{
  // first print the ele, print value of children and push them in queue and for each
  queue<node *> q;
  q.push(roo);
  while (!q.empty())
  {
    node *curr = q.front();
    cout << curr->val << " ";
    for (auto i : curr->children)
    {
      q.push(i);
    }
    q.pop(); //  pop the node whose children we added to the queue
  }
}

void level_order_linewise(node *roo)
{
  queue<node *> fq;
  fq.push(roo);

  queue<node *> sq;
  while (!fq.empty())
  {
    // first remove the top
    node *curr = fq.front();
    fq.pop();
    cout << curr->val << " ";
    for (auto i : curr->children)
    {
      sq.push(i);
      // push the children in second queue and check outisde if first queue empty, if yes then print \n and then continue
    }
    if (fq.empty())
    {
      // one level has passed
      fq = sq;
      // make sq empty
      sq = {};
      cout << "\n";
    }
  }
  // Or simply make a counter for queue. int c=q.size(); and then for(i=0 to q.size())
  // take the front, pop it and then push the children in queue and at the end \n
}

// To Be Continued... 249
void level_order_zigzag(node *roo)
{
  // maintain a level counter and check level % 2==0  or not
  // If yes then left to right by using stack s.push(curr->children[i]) where i from
  // 0 to curr->children.size()-1 and for level % 2==0 loop from i=curr->children.size()-1 to 0
  // Use 2 stacks. First to print second to store the new elements and athe same position increase the levels
  queue<node *> q1, q2;
  q1.push(roo);
  bool flag = true; // for left to right and false for right to left
  while (!q1.empty())
  {
    node *curr = q1.front();
    q1.pop();
    cout << curr->val << " ";
    for (auto i : curr->children)
    {
      q2.push(i);
    }
    // check if empty, if yes then reverse print and \n
    if (q1.empty())
    {
      q1 = q2;
      q2 = {}; //  empty q2
      cout << "\n";
      flag = false; //  print in reverse order
    }
  }
}

// mirror of generic tree
void mirror(node *roo)
{
  stack<node *> s1, s2;
  // push the first node and then pushing all children in s2 like level order linewise and everything
  s1.push(roo);

  while (!s1.empty())
  {

    node *curr = s1.top();
    s1.pop();
    cout << curr->val << " ";
    for (auto i : curr->children)
    {
      s2.push(i);
    }
    if (s1.empty())
    {
      s1 = s2;
      s2 = {};
      cout << "\n";
      // when this reaches, one level is over
    }
    // stack makes it better as we pop the right most ele first like the mirror and not the leftmost
    // like the queue. Also, maintaining 2 stacks help us not ruining the output
  }
}

// Make sure to return roo and not void. Also return to temp and not curr roo
node *remove_leaves(node *roo)
{
  // find a node whose children vector has 0 length and then delete that element
  // don't simply traverse the children vector with iterator and delete ones with no children as
  // vector changes and moves closer to index 0 when u delete any ele in that vector changing indices
  // of all ele after the deleted ele bringing logical error as some elements move from x to x-1 but
  // iterator i goes i++ missing the new x-1 index value, so go from end to front

  // call the remove_leaves func for all children first and then check the curr node and not opposite
  // but here one more problem in post order logic that if a node in tree 10 has 2 children 20 and 30,
  // then in postorder logic where we recursively call the leaves, remove them and then go to their
  // parents is that it will consider 10 also as a leaf despite it had 20 and 30 as it's children and
  // remove that also https://www.youtube.com/watch?v=0PBC_EEBHGg&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=254
  // 8:10 explains better
  // So, better to remove the leaves and then call parent and not vice versa

  /*
  for (auto i = roo->children.end(); i != roo->children.begin(); i--)
    {
      node *curr = *i;
      if (curr->children.size() == 0)
      {
        // remove that ele using the remove() => https://www.geeksforgeeks.org/stdremove-stdremove_if-c/
        remove(roo->children.begin(), roo->children.end(), curr);
      }
    }

    for (auto i : roo->children)
    {
      remove_leaves(i);
    }
    */

  //  https://www.geeksforgeeks.org/remove-all-leaf-nodes-from-a-generic-tree-or-n-ary-tree/
  if (roo == nullptr)
    return nullptr;
  if (roo->children.size() == 0)
  {
    //  delete roo as it is a leaf
    delete roo;
    return nullptr;
  }

  //  for children of roo
  for (int i = 0; i < roo->children.size(); i++)
  {
    node *child = roo->children[i]; //  ith child node check it's children
    if (child->children.size() == 0)
    {
      delete child;
      for (int j = i; j < roo->children.size() - 1; j++)
      {
        // since ith ele is removed, push back the ele to 1 and pop the last child
        roo->children[j] = roo->children[j + 1];
      }
      roo->children.pop_back(); // pop the last as it is same as 2nd last
      i--;                      //  so that node i+1 which gets pushed to i does not get left to be checked
    }
  }

  // call the function recursively for all children
  for (int i = 0; i < roo->children.size(); i++)
  {
    roo->children[i] = remove_leaves(roo->children[i]);
  }
  return roo;
}

// Iterative method here -https://www.geeksforgeeks.org/iterative-preorder-traversal-of-a-n-ary-tree/
void preorder(node *roo)
{
  // Preorder traversal is going leftwards till null and then print. Use stack for iterative answer
  cout << roo->val << " ";
  for (auto i : roo->children)
  {
    preorder(i);
  }
}

node *getTail(node *n)
{
  while (n->children.size() == 1)
  {
    // if a node has 1 child, then go down to next node's first child
    n = n->children[0]; // store n as the 0th child of n if there is only 1 child of n
  }
  return n;
}
// https://www.youtube.com/watch?v=TKZEBXtzKSM&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=257
// DIFF
void linearize(node *roo)
{
  // linearize the tree in such a way that every node has only 1 child in the way preorder traversal works
  // note that you have to change the tree and not just print the traversal

  // assume that lower leaves will get linearized by itself as we use recursion, call the function for children of roo
  for (auto i : roo->children)
  {
    linearize(i);
  }
  // Now, for each subtree, remove the last node which roo is connected to(x) and make the last node of 2nd last tree(y) connect
  // to x such that initially roo had subtrees a,b,c...y Remove y from roo->y and make 2nd last subtree last node x connect to it
  // i.e. x->y so it linearizes

  // for children size more than 1, do the above as you need atleast 2 subtrees for this

  // The main logic inside the below where we recursively go to 2nd last node with n number of children
  // then for each, remove the last child, find the last child of 2nd last child of roo and connect
  // both to linearize it. The linearize() of upper nodes are stored in memory stack and goes bottom up
  // recursively
  while (roo->children.size() > 1)
  {
    node *lc = roo->children.back(); // assign the last child of roo and pop it
    roo->children.pop_back();
    node *sl = roo->children.back(); // since we removed the last child, the new last child is the second last prev child
    // now find the second last tail to connect tail to lc
    node *slt = getTail(sl);
    slt->children.push_back(lc);
  }
  // This code connects the tails of subtree nodes to head of next subtrees till we have only 1 subtree of root left
  // this code is O(n^2) as we call linearize n times and for each time, we call getTail() which
  // visits all nodes in worst case so O(n^2)
}
// https://www.youtube.com/watch?v=D5RYXVgJ5NM&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=259

// To convert the linearize(), we change our assumption. Earlier it was that it will linearize itself and then we had to
// find the tail and connect the last node of 2nd last child of roo to the head of last child of roo each taking O(n)
// where connecting tail was inside outer function so O(n^2)

// Now, the faith is that not only it linearizes itself but also tells us the tail of the current subtree
// i.e. for subtree 40, it will tell the tail is 100, similarly for 30 it's 90 and return the tail

// It's not void but returns the tail
// DIFF
node *linearize_eff(node *roo)
{
  // base case for children <=1
  if (roo->children.size() == 0)
  {
    return roo; //  it's a leaf, so can't be linearized
    // Also, we need base case as last = roo->children.back() returns nothing
  }

  // store the last tail by recursively calling linearize_eff()
  // the last tail would be the last node of last child of roo which is called recursively
  node *lt = linearize_eff(roo->children.back());
  // we have linearized the last subtree, would do with 2nd last
  while (roo->children.size() > 1)
  {
    // remove the last node as child of roo as we will connect the tail of 2nd last with it
    node *last = roo->children.back(); // store the last node of roo(not the tail of last node of roo)
    roo->children.pop_back();          //  pop the last child of roo which will be connected to the 2nd last one
    node *sl = roo->children.back();   //  getting the new last node or the prev 2nd last node of roo
    node *slt = linearize_eff(sl);     // 2nd last tail find
    slt->children.push_back(last);     //  push the last node of roo as child of slt
  }
  return lt; // return the first tail or overall tail
}

// find a node, given a val, find if in tree,traverse it
bool find_node(node *roo, int val)
{
  if (val == roo->val)
    return true;
  for (auto i : roo->children)
  {
    // make sure the func calls i and not roo else inf loop
    if (find_node(i, val))
    {
      return true;
    }
  }
  return false;
}

// https://www.youtube.com/watch?v=oEBwL5pHzTs&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=267
// faith in the below func is when we find the node like prev find_node()
// we will push the values in the stack/list the path to root and print it
vector<int> print_path(node *roo, int val)
{
  // if we find the curr node as the val, then simply return the node as the path from roo to roo
  // is just the value of roo

  // This is base case if we have ele fund at curr node, for others, go to child and if any vector has size more than 0, add the curr node
  // and return the vector. It recursively calls function in memory stack and makes the vector bigger if a child has the value
  if (roo->val == val)
  {
    vector<int> ans; //  create a vector and push the value
    ans.push_back(roo->val);
    return ans; //  return the vector as we have found the ans
  }
  // else call all it's children to find the node. Here we go from top to bottom of tree and
  // not the opposite where we find a node and then go to it's root
  // check for each child if any print_path() returns any vector, if yes, it means we have found the answer in a
  // child and the current node is it's parent, so push the current node value in the vector returned and return the ptc vector
  // which contains the path to node plus the parent node added to the vector
  for (auto i : roo->children)
  {
    vector<int> ptc = print_path(i, val); //  create a path till child vector to find if any path
    // to current val is found
    if (ptc.size() > 0)
    {
      // meaning we have found a path to child
      // add the curr node data and return the vector
      ptc.push_back(roo->val);
      return ptc;
    }
  }
  // if no node matched or any children has that node, then return empty vector or {}(list initialisation since C++11)
  // return vector<int>();
  // OR
  return {};
}

// Lowest common ancestor, for 2 nodes, check the common parent
int lca(node *roo, int f, int s)
{
  // Here roo is the root, f is the first ele and s is 2nd whose parents we have to see if they match or not
  // For the path, find the path for both and the last ele for which the vectors returned by print_path() for both ele
  // are same, that is the lowest common ancestor
  vector<int> f_ans, s_ans;
  int ans = -1;
  f_ans = print_path(roo, f);
  s_ans = print_path(roo, s);
  // for (auto i : f_ans)
  //   cout << i << " ";
  // cout << "\n";
  // for (auto i : s_ans)
  //   cout << i << " ";
  // cout << "\n";
  // the vector is in opposite order so go in reverse
  // Don't use the for loop as there are problems. If you have i=f_ans.size()-1, it will create a problem
  // as f_ans[2]=10 but s_ans[2] may not be 10 as it may have size 3, you will have to use while loop
  // with f_ans.back() and s_ans.back() if same then pop both till empty or ele found
  while (!f_ans.empty() || !s_ans.empty())
  {
    // check if last ele of vectors same or not
    if (f_ans.back() == s_ans.back())
    {
      ans = f_ans.back(); //  store the answer and pop the vector backs
      f_ans.pop_back();
      s_ans.pop_back();
    }
    else
      return ans;
  }
  return -1;
  // if not found ele
}

// Distance between nodes of tree. Here for a given tree, find the dist b/w nodes
// This can be done by finding the lcs and then fromt that lca, edges to go from node1 and node2
// The print_path() gives path to lcs for each node plus path from lcs to node1 and lcs to nde2
// which is the answer here(the edges)
// This will have a similar code to lca() except the place in else condition, rather than returning
// The ans, we calculate edges left
int dist_nodes(node *roo, int f, int s)
{
  // Since in lca(), we were popping the lca, here don't pop it or push it back and then return the edges
  vector<int> f_ans, s_ans;
  f_ans = print_path(roo, f);
  s_ans = print_path(roo, s);
  int ans = -1;
  // for (auto i : f_ans)
  //   cout << i << " ";
  // cout << "\n";
  // for (auto i : s_ans)
  //   cout << i << " ";
  // cout << "\n";
  // Here we have the distance vectors, print to see it now
  // Now, we have the vectors with paths, do the lca(), store the inp and till you don't reach
  // lca value, pop the vector backs and then return the edges as (f_ans.size()-1) + (s_ans.size()-1)
  while (!f_ans.empty() || !s_ans.empty())
  {
    if (f_ans.back() == s_ans.back())
    {
      ans = f_ans.back();
      f_ans.pop_back();
      s_ans.pop_back();
    }
    else
    {
      if (ans == -1)
      {
        // The last ele were never same so dist also cannot be calculated
        cout << "ans returned -1\n";
      }
      else
      {
        // ans is the lca and so either push it in both and return both size-1 or simply return
        // their curr length
        return f_ans.size() + s_ans.size();
      }
    }
  }
  return -1;
  // -1 meaning no path, only when ele not in the tree
}
// same as lca() but here don't return the lca but the remaining size

// similar shaped trees
bool sameShaped(node *roo1, node *roo2)
{
  // check for each node if the number of children are same
  // first check for children of curr node and then call the function for the curr node
  if (roo1->children.size() != roo2->children.size())
  {
    return false;
  }
  // Now, since the size is same else returned false
  for (int i = 0; i < roo1->children.size(); i++)
  {
    bool ans = sameShaped(roo1->children[i], roo2->children[i]); // call for each child of roo1 and roo2 if same size
    if (ans == false)
      return false;
  }
  return true;
}

// check if the two trees are mirror of each other. You can do it in 2 ways, make the 2nd tree mirror of it's own
// and then compare the 2 trees using sameShaped(), or create 1 function with both functionality

// Finding if 2 trees are mirror of each other
bool isMirror(node *roo1, node *roo2)
{
  // compare the children of both with a twist as you compare the mirror children of 2nd
  // first check the size
  if (roo1->children.size() != roo2->children.size())
    return false;
  // Now compare the ith ele and the size-i ele of roo1->children and roo2->children
  int n = roo1->children.size();
  for (int i = 0; i < n; i++)
  {
    bool ans = isMirror(roo1->children[i], roo2->children[n - 1 - i]);
    if (ans == false)
      return false; //  if any children size does not matches, return false
  }
  return true;
}

// isSymmetric - check if two trees are symmetric. It also means it's mirror is same as the tree. Use the isMirror() to see if the same
// tree is mirror of itself, if yes, then it is symmetric else not

bool isSymmetric(node *roo)
{
  bool ans = isMirror(roo, roo);
  // checking if tree with root roo is mirror of itself or not, if yes then symmetric
  return ans;
}

int main()
{

  // int a[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
  int a[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40};

  stack<node *> s;
  node *roo = nullptr;
  int n = sizeof(a) / sizeof(a[0]);
  for (int i : a)
  {
    if (i == -1)
      s.pop();
    else
    {
      // create a new node for the tree and add ele to it
      node *temp = new node();
      temp->val = i;
      if (!s.empty())
      {
        s.top()->children.push_back(temp);
        // Here we add temp node to the children of s.top(). Use (->) and not dot operator after s.top() as it gives error
      }
      else
      {
        // empty stack
        roo = temp;
      }
      // push node in stack for all conditions except for when it is -1
      s.push(temp);
      // delete temp;
    }
  }
  disp(roo);
  //  add 1 for root
  cout << "\n";
  level_order_linewise(roo);
}

/*
Here we will create a generic tree in such a way that if we have input [10,20,-1]
then we keep pushing in the stack till -1 comes and then pop at -1. The next element i.e. 20 after 10 is the child of 10

*/