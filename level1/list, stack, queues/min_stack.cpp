// https://www.youtube.com/watch?v=NslJ5PXAM4Q&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=141
#include <iostream>
#include "stack"
using namespace std;

void solve()
{
  stack<int> s, min_s;
}
/*
if(min_s.empty())
{
  min_s.push(val);
}
else{
  if(val <min_s.top())
  {
    min_s.pop();
    min_s.push(val);
  }
}

Note - this func is along push(). Also, if there happends to be case if we are popping ele, then we must make sure
that ele in our min stack is also getting popped
Another way we can do it is that keep pushing ele in min_s stack if we find any ele smaller while we are pushing
for stack(bottom->top) => {10,20,30,5,8,12,3,16,2,14}
we have min_s stack as => {10,5,3,2} as we push in min_s onlyif any value < min_s.top(). In last case we were popping.
We can avoid that and only pop if that min_s.top() ele is popped from main stack while comparing.

Another variation of this question is min stack 2 where we don't have a min stack but a constant space and have constant time
unlike here where we had linear space. In that case store the min variable as min till found and in the normal stack if any value
is pushed less than min value, then store the value in stack as values + (value-min) meaning that in a stack if we have min as
8 and if we push 7, then store it as 7+(7-8)=6 and store 7 in min such that the value on top of stack is less than min value
Now if we push 2, then store as 2+(2-7)=-3 and store min as 2

For the places where min has greater value than top() those are important as only then it's value is changing.
min > s.top()
Implication is we stored a fake value in the stack when value to be pushed < min.
Since at a point if min > s.top(), we know that the minimum of stack has changed here.

Now we have the pop() and top() as main func left
push(){
  if(s.empty())
  {
    s.push(val);
    min=val;
  }
  else if(val>=min)
  {
    s.push(val);
  }
  else{
    s.push(val + (val-min));
  }
}
Implications of push() - 1. we pushed a fake value in stack
2. Not only fake but smaller than original value we passed
3. Original value stored in min
4. Can be used for detection of new min value

top(){
  if(s.empty())
  {
    cout<<"overflow";
  }
  else{
    if(s.top() >= min)
    {
      cout<<s.top()<<"\n";
    }
    else{
  // the top() is not real value as the real in min
  cout<<min;
    }
  }
}

Now the main is pop() where we don't have to just remove the top() but change min value also

pop(){
  if(s.empty())
  {
    cout<<"underflow";
  }
  else{
    int val = s.top();
    if(val >= min)
    {
      s.pop();
      return val;
    }
    else{
// value smaller than min. Now remember we stored new_val = (value + value - min). In order to get back to the old min
// we have to do current min(which is value) and store new_min as mew_min = min + min - s.top() which here is val
// If we had case 2 coming after 7 then current min =2 and then top of stack = 2+2-7=-3
// Here we have min=2 and s.top()=-3. If we have to pop() then we check (min<s.top()) i.e. 2< -3
// and so revert to the old min we remember formula => new_val = value + value - min where in this case min is our old min
// so min = value + value - new_val
// Here value is the value of the new smaller ele which had to be inserted first which after inserting -3 is now stored as the new min
// after min was 7 as 2<7, so we do new_min = min + min -val; min = new_min;

int new_min = min + min - s.top();  // or 2*min - val
min=new_min;

    }
  }
}
*/

int main()
{

  return 0;
}

/*
Find the minimum of stack in O(1) time meaning it must be on top of stack but remember all the other func
work same as before. ex: if we have pushed - {10,20,2,8,5} then min() must return 2 but s.top() must give 5
and pop() must pop 5 from the stack
*/