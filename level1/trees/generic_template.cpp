#include <iostream>
#include "vector"
#include "stack"
#include "queue"
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

int size(node *roo)
{
  int s = 0;
  for (auto i : roo->children)
  {
    int cs = size(i);
    s += cs;
  }
  return s + 1;
}

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
    int ch = height(i);
    h = max(h, ch);
  }
  h += 1;
  return h;
}

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

void level_order(node *roo)
{
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
    q.pop();
  }
}

void level_order_linewise(node *roo)
{
  queue<node *> fq;
  fq.push(roo);

  queue<node *> sq;
  while (!fq.empty())
  {
    node *curr = fq.front();
    fq.pop();
    cout << curr->val << " ";
    for (auto i : curr->children)
    {
      sq.push(i);
    }
    if (fq.empty())
    {
      fq = sq;
      sq = {};
      cout << "\n";
    }
  }
}

void mirror(node *roo)
{
  stack<node *> s1, s2;
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
    }
  }
}

// MED
node *remove_leaves(node *roo)
{
  if (roo == nullptr)
    return nullptr;
  if (roo->children.size() == 0)
  {
    delete roo;
    return nullptr;
  }

  for (int i = 0; i < roo->children.size(); i++)
  {
    node *curr = roo->children[i];
    if (curr->children.size() == 0)
    {
      delete curr;
      for (int j = i; j < roo->children.size() - 1; j++)
      {
        roo->children[j] = roo->children[j + 1];
      }
      roo->children.pop_back();
      i--;
    }
  }

  for (int i = 0; i < roo->children.size(); i++)
  {
    roo->children[i] = remove_leaves(roo->children[i]);
  }
  return roo;
}

void preorder(node *roo)
{
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
    n = n->children[0];
  }
  return n;
}

// DIFF => O(n^2)
void linearize(node *roo)
{
  for (auto i : roo->children)
  {
    linearize(i);
  }

  while (roo->children.size() > 1)
  {
    node *lc = roo->children.back();
    roo->children.pop_back();
    node *sl = roo->children.back();
    node *slt = getTail(sl);
    slt->children.push_back(lc);
  }
}

// DIFF => O(n)
node *linearize_eff(node *roo)
{
  if (roo->children.size() == 0)
  {
    return roo;
  }

  node *lt = linearize_eff(roo->children.back());
  while (roo->children.size() > 1)
  {
    node *last = roo->children.back();
    roo->children.pop_back();
    node *sl = roo->children.back();
    node *slt = linearize_eff(sl);
    slt->children.push_back(last);
  }
  return lt;
}

bool find_node(node *roo, int val)
{
  if (val == roo->val)
    return true;
  for (auto i : roo->children)
  {
    if (find_node(i, val))
    {
      return true;
    }
  }
  return false;
}

vector<int> print_path(node *roo, int val)
{
  if (roo->val == val)
  {
    vector<int> ans;
    ans.push_back(val);
    return ans;
  }
  for (auto i : roo->children)
  {
    vector<int> ptc = print_path(i, val);
    if (ptc.size() > 0)
    {
      ptc.push_back(roo->val);
      return ptc;
    }
  }
}

int lca(node *roo, int f, int s)
{
  vector<int> f_ans, s_ans;
  int ans = -1;
  f_ans = print_path(roo, f);
  s_ans = print_path(roo, s);
  while (!f_ans.empty() || !s_ans.empty())
  {
    if (f_ans.back() == s_ans.back())
    {
      ans = f_ans.back();
      f_ans.pop_back();
      s_ans.pop_back();
    }
    else
      return ans;
  }
  return -1;
}

int dist_nodes(node *roo, int f, int s)
{
  vector<int> f_ans, s_ans;
  int ans = -1;
  f_ans = print_path(roo, f);
  s_ans = print_path(roo, s);
  while (!f_ans.empty() || !s_ans.empty())
  {
    if (f_ans.back() == s_ans.back())
    {
      ans = f_ans.back();
      f_ans.pop_back();
      s_ans.pop_back();
    }
  }
  return f_ans.size() + s_ans.size();
}
// Here the lca removed from f_ans and s_ans but as we needed to print edges, their curr size does it

bool isSameShape(node *roo1, node *roo2)
{
  if (roo1->children.size() != roo2->children.size())
  {
    return false;
  }
  for (int i = 0; i < roo1->children.size(); i++)
  {
    bool ans = isSameShape(roo1->children[i], roo2->children[i]);
    if (ans == false)
      return false;
  }
  return true;
}

bool isMirror(node *roo1, node *roo2)
{
  if (roo1->children.size() != roo2->children.size())
    return false;
  int n = roo1->children.size();
  for (int i = 0; i < n; i++)
  {
    bool ans = isMirror(roo1->children[i], roo2->children[n - i - 1]);
    if (ans == false)
      return false;
  }
  return true;
}

bool isSymmetric(node *roo)
{
  return isMirror(roo, roo);
}

int main()
{

  return 0;
}