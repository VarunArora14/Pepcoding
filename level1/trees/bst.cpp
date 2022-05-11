// https://www.youtube.com/watch?v=XV1ADVV6FbQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=312
// and 315

#include <iostream>
#include "vector"
#include "stack"
#include "string"
#include "queue"
#include "climits"
using namespace std;

class node
{
public:
  int val;
  node *left;
  node *right;
  node(int data, node *left, node *right)
  {
    this->val = data;
    this->left = left;
    this->right = right;
  }
  // this way we can create a node with simple call to class and not a function
};

// node *create(int data)
// {
//   node *curr = new node;
//   curr->val = data;
//   curr->left = nullptr;
//   curr->right = nullptr;
//   return curr;
// }

class PairNode
{
public:
  node *curr;
  int state;

  PairNode(node *n, int state)
  {
    this->curr = n;
    this->state = state;
  }
};

void display(node *roo)
{
  // the roo==nullptr condition very important as base case else the program will end early
  if (roo == nullptr)
    return;
  string str = "";
  str += roo->left == nullptr ? "." : to_string(roo->left->val) + " ";
  str += "<-" + to_string(roo->val) + "->";
  str += roo->right == nullptr ? "." : to_string(roo->right->val) + " ";
  cout << str << "\n";
  // prints the roo node
  display(roo->left);
  display(roo->right);
}

int ht = 0, mx = 0, sz = 0;
// initalise their values
int sum_tree(node *roo)
{
  // preorder traversal and the sum
  if (roo == nullptr)
    return 0;
  int lef_sum = sum_tree(roo->left);
  int right_sum = sum_tree(roo->right);
  int total_sum = lef_sum + right_sum + roo->val;
  return total_sum;
}

int height_tree(node *roo)
{
  if (roo == nullptr)
    return -1; //  return -1 for edges and 0 for nodes

  // for single node, edges=0 and node=1, so if for height we had to return the total nodes
  // for this case max(l_ht,r_ht) for single node returns -1 and max(-1,-1) is -1. total_ht=(-1)+1=0
  // since 2 nodes have 1 edge, height would be 1 considering edges as you reduce by 1 for total edges
  // as 2 nodes have 1 edge so n nodes have n-1 edges and so comes the base case which returns -1 for the leaf node

  int l_ht = height_tree(roo->left);
  int r_ht = height_tree(roo->right);
  int total_ht = max(l_ht, r_ht) + 1;
  return total_ht;
}

int max_tree(node *roo)
{
  if (roo == nullptr)
    return INT_MIN;
  // since first it will start roo->val, make mx as max of roo->val and left, right subtrees
  int lef_max = max_tree(roo->left);
  int right_max = max_tree(roo->right);
  int tm = max(roo->val, max(lef_max, right_max));
  return tm;
}

int size_tree(node *roo)
{
  if (roo == nullptr)
    return 0;
  return 1 + size_tree(roo->left) + size_tree(roo->right);
}

string pre, in, post;
void traversal(node *roo)
{
  if (roo == nullptr)
    return;
  pre += to_string(roo->val) + " "; // preorder when we visit and node first time
  traversal(roo->left);             //  inorder when we have gone through the node and move to it's right
  in += to_string(roo->val) + " ";
  traversal(roo->right);
  post += to_string(roo->val) + " "; //  post when seen left and right of node and now going back
}

void level_order(node *roo)
{
  // push the first value in queue and then go left and right
  if (roo == nullptr)
    return;
  queue<node *> q;
  q.push(roo);
  // The below coe prints the level order in same line
  // while (!q.empty())
  // {
  //   node *curr = q.front();
  //   q.pop();
  //   cout << curr->val << " ";
  //   // enqueue left if not null
  //   if (curr->left != nullptr)
  //     q.push(curr->left);
  //   if (curr->right != nullptr)
  //     q.push(curr->right);
  // }

  // for line by line print
  while (!q.empty())
  {
    int count = q.size();
    // The reason we have till count is that in a queue, we print a level which gets pushed by going through
    // the children of each node and after the loop it contains only the children of parent nodes as if we
    // don't have count variable then it goes on to print all the element in level order but without endl
    // after every for loop, children of nodes remain in queue as all parents are processed bcos it goes
    // through q.size() which is num of parents' elements
    for (int i = 0; i < count; i++)
    {
      node *curr = q.front();
      cout << curr->val << " ";
      q.pop(); // get front ele and pop
      if (curr->left != nullptr)
        q.push(curr->left);
      if (curr->right != nullptr)
        q.push(curr->right);
    }
    cout << "\n";
  }
}
// for iterative traversal, we will have to push ele in stack and then process using states
// Here we use again the pair for states
void iterative_traversal(node *roo)
{
  stack<PairNode *> s;
  PairNode *first_pair = new PairNode(roo, 1); //  initial state 1 for preorder
  s.push(first_pair);
  pre = "";
  in = "";
  post = "";
  while (!s.empty())
  {
    PairNode *top_node = s.top(); //  top node point to top of stack
    // do not pop
    // print the value as preorder
    // don't make the top_node->curr==nullptr condition outside the if condition but only when you have to make
    // a new PairNode(), use it

    // do only if not null
    if (top_node->state == 1) //  pre, state++, left
    {
      // preorder when state 1, print and increase state, go to left
      top_node->state++;
      pre += to_string(top_node->curr->val) + " ";
      if (top_node->curr->left != nullptr) //  make pairnode if left not null
      {
        PairNode *left_pair = new PairNode(top_node->curr->left, 1); //  default 1 state for all
        s.push(left_pair);
      }
    }
    else if (top_node->state == 2) //  in, state++, right
    {
      // inorder when node visited and we have to now go the right
      top_node->state++;
      in += to_string(top_node->curr->val) + " ";
      if (top_node->curr->right != nullptr)
      {
        PairNode *right_pair = new PairNode(top_node->curr->right, 1);
        s.push(right_pair);
      }
    }
    else //  post, pop
    {
      // when state is 3, no need to increase state, save in postorder and pop
      post += to_string(top_node->curr->val) + " ";
      s.pop();
    }
  }
  // print the pre, post and inorder traversal
  cout << "\nPreorder is " << pre << "\nInorder is "
       << in << "\nPostorder is "
       << post;
}

// print node to root path, we follow like before where we check if roo->val matches any and if yes, return vector of path
// There can only be 1 path to the node in binary tree
// https://www.youtube.com/watch?v=1Kyc-zQS7eQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=323
vector<int> path;
bool find(node *roo, int data)
{
  if (roo == nullptr)
    return false;
  if (roo->val == data)
  {
    path.push_back(roo->val); //  add to vector if curr value same as data
    return true;
  }

  bool left_find = find(roo->left, data); //  check for whole left subtree
  if (left_find)
  {
    path.push_back(roo->val); //  if left subtree returns true then it means the current node also in path
    // as there can only be 1 path and if a left child of node has the data, the parent node also comes in the path
    return true;
  }
  // the reason we used bool as this is a binary tree so only left and right 2 nodes, we can use this
  // also for a generic tree
  bool right_find = find(roo->right, data);
  if (right_find)
  {
    path.push_back(roo->val);
    return true;
  }
  return false; //  if neither the roo, nor on it's left nor right
}

// print k levels down
// https://www.youtube.com/watch?v=KvcfuGcdDMg&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=325
// You can think of going through level order and then print but easier way is go preorder and recursively call for k-1
// function with base case

void k_levels_down(node *roo, int k)
{
  if (roo == nullptr || k < 0)
  {
    return; //  no point going on as we can't print for roo==nullptr and k<0 means we have printed all k ele so exit
  }
  // base case when k=0
  if (k == 0)
  {
    cout << roo->val << "\n";
  }
  k_levels_down(roo->left, k - 1); //  do for left and right subtree
  k_levels_down(roo->right, k - 1);
}

// tilt of binary tree, we define as abs diff of left and right subtree
// we will do sum of all nodes in postorder and then use tilt variable that will give the abs diff
// return sum for left and right but change tree_tilt which stores abs diff
int tree_tilt = 0;
int tilt_bst(node *roo)
{
  if (roo == nullptr)
    return 0;
  // int node_tilt = abs(tilt_bst(roo->left) - tilt_bst(roo->right));
  int lef_sum, right_sum, node_sum;
  lef_sum = tilt_bst(roo->left);                    //  return left sum
  right_sum = tilt_bst(roo->right);                 //  return right sum
  tree_tilt = tree_tilt + abs(lef_sum - right_sum); //  change the tree tilt by adding local tilt for left
                                                    // and right subtrees
  node_sum = lef_sum + right_sum + roo->val;
  return node_sum;
}

int main()
{
  // You are given an array which is the preorder traversal of the tree we want to achieve
  // at any place we don't have a child, we store it as null. For this we call the insertion function for the left
  // and then right when null
  int a[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
  // int a[] = {50, 10, 30, -1, -1, 20, -1, -1, 40, -1, -1};
  // here we use -1 as NULL
  stack<PairNode *> s;
  // create a new pairnode but remember again, use pointer
  node *roo = new node(a[0], nullptr, nullptr);
  // initalise root as null with first value and then the pair nodes
  PairNode *new_pair = new PairNode(roo, 1);
  // here 1 means push to left, 2 means right, 3 means pop
  s.push(new_pair);

  // maintain an index for array traversal
  int idx = 0;
  while (!s.empty())
  {
    PairNode *top_node = s.top();
    // for state 1, push left, and then increase state
    if (top_node->state == 1)
    {
      idx++;
      // if NULL then just increase the state
      if (a[idx] != -1)
      {
        node *temp_node = new node(a[idx], nullptr, nullptr); // push in the left a new node created of current s.top() node
        top_node->curr->left = temp_node;
        // top_node->curr->left=new node(a[idx],NULL,NULL); //  You can do this also
        PairNode *temp_pair = new PairNode(temp_node, 1); //  pointer to PairNode made of temp_node

        s.push(temp_pair);
      }
      else
      {
        top_node->curr->left = nullptr;
        // if NULL value then make the left pointer nulll
      }
      top_node->state++; // make state 2
    }
    else if (top_node->state == 2)
    {
      // make the ele right
      idx++;
      if (a[idx] != -1)
      {
        node *temp_node = new node(a[idx], nullptr, nullptr);
        top_node->curr->right = temp_node;
        PairNode *temp_pair = new PairNode(temp_node, 1);
        s.push(temp_pair);
      }
      else
      {
        top_node->curr->right = nullptr;
      }
      top_node->state++; //  increase state always
    }
    else
    {
      // simply pop as when state=3, exit
      s.pop();
    }
  }
  display(roo);
  pre = in = post = "";
  traversal(roo);
  // iterative_traversal(roo);
  cout << "pre is " << pre << "\nin is " << in << "\npost is " << post;
  tilt_bst(roo);
  cout << "\ntree tilt is " << tree_tilt;
  // cout << "\nsum of tree is " << sum_tree(roo);
  return 0;
}

/*
Given array, create a tree in preorder way. The way it works is keep pushing in stack and keep going left till a[i] is null
and then you keep popping up. We use stack as for pushing, since we need to keep going left, stack will help maintaining that order
and state variable maintains which of left, right or both have been visited for each val. Keep going left till state becomes 3
at state=1, go left and make state=2 as we need to decide for the right of curr node when we come back to that node, push the value and the node
at state=1 till null the left and right values of the leaf and then u come back
*/

// Do 326 to 339 and others in yt liked videos