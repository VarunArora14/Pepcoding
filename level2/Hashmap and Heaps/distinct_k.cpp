// https://www.youtube.com/watch?v=x8O9XocEioI&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=4
#include <iostream>
#include "map"
#include "vector"
using namespace std;

// acquire add remove
// acquire new ele,
int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> ans;
  map<int, int> m1;

  // first acquire the k ele as 0 to k-1 brings the kth ele as k-1
  for (int i = 0; i <= k - 2; i++)
    m1[a[i]]++;

  // now from k-1(kth ele) to i<n, insert the next ele,
  for (int i = k - 1, j = 0; i < n; i++, j++)
  {
    m1[a[i]]++;               // acquire new ele to the map
    ans.push_back(m1.size()); // add to vector the size of vector which is unique ele
    // erase the jth ele by checking if m1[a[j]]==1 then erase else m1[a[j]]--
    if (m1[a[j]] == 1)
      m1.erase(a[j]);
    else
      m1[a[j]]--;
    // above is release
  }

  for (auto i : ans)
    cout << i << " ";
  return 0;
}
/*
Here we have to find the distinct elements in k subarray size. For this we travel the array till k-1 elements pushing in a vector and from
the kth element we do acquire, push and release where we first acquire a new element, push in the map and later at next iteration release it.

5 3
1 3 7 2 9

Another wy using while loop is as follows -
int i=0, j=-1;
// push k-1 ele in map
while(i<=k-2)
{
  m1[a[i]]++;
}

while(i<n)
{
  // acquire the ele and increase i first
  i++;
  m1[a[i]]++;

  ans.push_back(m1.size()); // work

  // release
  j++; // increase the j before releasing as it points to prev num
  if(m1[a[j]]==1)
    m1.erase(a[j]);
  else m1[a[j]]--;
}
*/