// https://www.youtube.com/watch?v=Svex7W3CYpQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=179
#include <iostream>
#include "string"

using namespace std;
class linkedlist
{

public:
  class Node
  {
  public:
    int data = 0;
    Node *next = nullptr;

    Node(int data)
    {
      this->data = data;
    }
  };

  Node *head = nullptr;
  Node *tail = nullptr;
  int size = 0;

  // basic->============================================

  int size_()
  {
    return this->size;
  }

  bool isEmpty()
  {
    return this->size == 0;
  }

  string toString()
  {
    Node *curr = this->head;
    string sb = "";

    while (curr != nullptr)
    {
      sb += to_string(curr->data);
      if (curr->next != nullptr)
        sb += " ";
      curr = curr->next;
    }
    return sb;
  }

  // add->===============================================
private:
  void addFirstNode(Node *node)
  {
    if (this->head == nullptr)
    {
      this->head = node;
      this->tail = node;
    }
    else
    {
      node->next = this->head;
      this->head = node;
    }

    this->size++;
  }

public:
  void addFirst(int val)
  {
    Node *node = new Node(val);
    addFirstNode(node);
  }

public:
  void addLastNode(Node *node)
  {
    if (this->head == nullptr)
    {
      this->head = node;
      this->tail = node;
    }
    else
    {
      this->tail->next = node;
      this->tail = node;
    }

    this->size++;
  }

  void addLast(int val)
  {
    Node *node = new Node(val);
    addLastNode(node);
  }

  void addNodeAt(Node *node, int idx)
  {
    if (idx == 0)
      addFirstNode(node);
    else if (idx == this->size)
      addLastNode(node);
    else
    {
      Node *prev = getNodeAt(idx - 1);
      Node *curr = prev->next;

      prev->next = node;
      curr->next = node;

      this->size++;
    }
  }

  void addAt(int data, int idx)
  {
    if (idx < 0 || idx > this->size)
    {
      throw("invalidLocation: " + to_string(idx));
    }

    Node *node = new Node(data);
    addNodeAt(node, idx);
  }

  // remove->============================================
  Node *removeFirstNode()
  {
    Node *node = this->head;
    if (this->size == 1)
    {
      this->head = nullptr;
      this->tail = nullptr;
    }
    else
    {
      this->head = this->head->next;
      node->next = nullptr;
    }

    this->size--;
    return node;
  }

  int removeFirst(int val)
  {
    if (this->size == 0)
    {
      throw("nullptrPointerException: -1");
    }

    Node *node = removeFirstNode();
    int rv = node->data;
    delete node;
    return rv;
  }

  Node *removeLastNode()
  {
    Node *node = this->tail;
    if (this->size == 1)
    {
      this->head = nullptr;
      this->tail = nullptr;
    }
    else
    {
      Node *prev = getNodeAt(this->size - 2);
      this->tail = prev;
      prev->next = nullptr;
    }

    this->size--;
    return node;
  }

  int removeLast(int val)
  {
    if (this->size == 0)
    {
      throw("nullptrPointerException: -1");
    }

    Node *node = new Node(val);
    int rv = node->data;
    delete node;
    return rv;
  }

  Node *removeNodeAt(int idx)
  {
    if (idx == 0)
      return removeFirstNode();
    else if (idx == this->size - 1)
      return removeLastNode();
    else
    {

      Node *prev = getNodeAt(idx - 1);
      Node *curr = prev->next;

      prev->next = curr->next;
      curr->next = nullptr;

      this->size--;
      return curr;
    }
  }

  int removeAt(int idx)
  {
    if (idx < 0 || idx >= this->size)
    {
      throw("invalidLocation: " + idx);
    }

    Node *node = removeNodeAt(idx);
    int rv = node->data;
    delete node;
    return rv;
  }

  // get->================================================
  Node *getFirstNode()
  {
    return this->head;
  }

  int getFirst()
  {
    if (this->size == 0)
    {
      throw("nullptrPointerException: -1");
    }

    Node *node = getFirstNode();
    return node->data;
  }

  Node *getLastNode()
  {
    return this->tail;
  }

  int getLast()
  {
    if (this->size == 0)
    {
      throw("nullptrPointerException");
    }

    Node *node = getLastNode();
    return node->data;
  }

  Node *getNodeAt(int idx)
  {
    Node *curr = this->head;

    while (idx-- > 0)
    {
      curr = curr->next;
    }

    return curr;
  }

  int getAt(int idx)
  {
    if (idx < 0 || idx >= this->size)
    {
      throw("invalidLocation: " + idx);
    }

    Node *node = getNodeAt(idx);
    return node->data;
  }

  // merge two sorted linkedlist
  linkedlist mergeTwoSortedLists(linkedlist l1, linkedlist l2)
  {
    // write your code here
    cout << "hello";
    Node *n1 = l1.head;
    Node *n2 = l2.head;

    linkedlist res;
    while (n1 != nullptr || n2 != nullptr)
    {
      if (n1->data <= n2->data)
      {
        res.addLastNode(n1);
        n1 = n1->next;
      }
      else
      {
        res.addLastNode(n2);
        n2 = n2->next;
      }
    }

    while (n1 != nullptr)
    {
      res.addLastNode(n1);
      n1 = n1->next;
    }

    while (n2 != nullptr)
    {
      res.addLastNode(n2);
      n2 = n2->next;
    }
    return res;
  }
};

int main()
{
  linkedlist l1;
  linkedlist l2;

  int n1;
  cin >> n1;

  for (int i = 0; i < n1; i++)
  {
    int val;
    cin >> val;
    l1.addLast(val);
  }

  int n2;
  cin >> n2;
  for (int i = 0; i < n2; i++)
  {
    int val;
    cin >> val;
    l2.addLast(val);
  }

  linkedlist merged;
  merged.mergeTwoSortedLists(l1, l2);

  cout << merged.toString() << endl;
  cout << l1.toString() << endl;
  cout << l2.toString() << endl;

  return 0;
}