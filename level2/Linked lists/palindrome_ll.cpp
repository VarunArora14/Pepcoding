// https://www.youtube.com/watch?v=rP4zdxydE_0&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=3
#include <iostream>
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

// try on case 1->2->3 if u don't understand in 1 go. At end curr and nex is at nullptr and prev at 3
node *reverse(node *head)
{
  node *prev = nullptr, *curr = head, *nex;
  while (curr != nullptr)
  {
    nex = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nex;
  }
  return prev;
}

node *mid_ll(node *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  node *fast, *slow;
  fast = slow = head;
  while (fast->next != nullptr && fast->next->next != nullptr)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

// https://leetcode.com/problems/palindrome-linked-list/discuss/1137696/Short-and-Easy-w-Explanation-or-T-%3A-O(N)-S-%3A-O(1)-Solution-using-Fast-and-Slow
bool isPalin(node *head)
{
  node *slow = head, *fast = head, *prev = nullptr, *temp;
  // here in the same iteration we find the middle ele as well as reverse the first half
  while (fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  // The below line can be avoided
  // if (fast)
  // {
  //   // odd length. Reason is for odd length, we ignore the middle ele as it would be same and check for remaining
  //   slow = slow->next;
  // }
  fast = head;          // move fast at head and slow at tail for iteration
  slow = reverse(slow); // currently slow at mid->next for odd length and mid for even, and after the reverse(), moves at tail

  // slow important as for even length, same size but for odd length, slow is smaller so use it. fast will not end before slow anytime
  while (slow != nullptr)
  {
    if (fast->val != slow->val)
      return false;

    slow = slow->next;
    fast = fast->next;
  }
  /*
  We can make the LL same as before by reversing the LL by doing slow=reverse(slow) again and mid->next=slow
  where u store the value of mid before. Note that for odd length like 1->2->3->2->1 you make 3->next=2 and not 3->next=3
  meaning that if length is odd and u have to later make the LL same then u have to change slow=slow->next for odd length(commented above)
  otherwise the code works fine as for 1->2->3<-2<-1, at slow=3, fast is also at 3 but slow->next is nullptr so code works fine and returns
  true.
  */
  return true;
}

int main()
{
  node *head = nullptr;
  insert_end(&head, 1);
  insert_end(&head, 2);
  insert_end(&head, 3);
  // insert_end(&head, 3);
  // insert_end(&head, 2);
  insert_end(&head, 1);
  cout << isPalin(head);
  return 0;
}

/*
For finding palindrome in LL, we can't move backwards by going to the end of the LL, nor we can use another data structure like stack storing
values from mid to end and the checking the top values and pop them. We can modify the LL though by reversing the later mid of the LL.
If LL is 1 2 3 4 5, mid is 3, reverse(mid) such that it is 1->2->3<-4<-5
Then from the end of the LL of both side keep moving and comparing.

Find the mid of LL, make a new pointer as newhead = slow->next
Then write a reverse function which will change the direction of pointers

There is diff between odd and even lengths, at even length fast=nullptr will be the ending condition using
while(fast && fast->next) We don't use while(fast->next && fast->next->next) as both same almost.

For odd length fast will not be nullptr but fast->next would be, so we check
if(fast)
{
  slow = slow->next
}
fast=head;

after finding the mid ele, we move first at head and reverse the slow which makes it point at tail of the LL

1->2->3->2->1 has slow at 3, but changes to slow at 4 as length is odd, then reverse such that

1->2->3->2<-1 here 3 points to 2 but 2 points to nullptr as we reversed it

So we run while(slow!=nullptr) compare slow->val and fast->val

For even length 1->2->3->4->4->3->2->1
slow at first 4, then we reverse the latter part and make it
1->2->3->4->4<-3<-2<-1
and again while slow!=nullptr, check them. Make sure slow at end and first at start.
slow comes at tail when we reverse it and
*/