//  https://youtu.be/iKSI_9NHR1M
#include <iostream>
#include "vector"
#include "string"
#include "cmath"
using namespace std;

vector<vector<int>> subsets(vector<int> nums)
{
  // subsets are 2^n where n is length of nums. if size=3, 8 subsets total unique
  vector<vector<int>> ans;
  int limit = pow(2, nums.size());
  for (int i = 0; i < limit; i++)
  {
    vector<int> temp_res;
    int temp = i;
    for (int j = 0; j < nums.size(); j++)
    {
      // convert to binary 0's and 1's and then push in vector
      // last bit first then to first
      int rem = temp % 2;
      temp = temp / 2;
      if (rem)
      {
        temp_res.push_back(nums[j]);
      }
      // else do nothing
    }
    ans.push_back(temp_res);
  }
  return ans;
}

// Another way is - https://www.geeksforgeeks.org/power-set/

// void subsets_pep(vector<int> nums)
// {
//   int limit = pow(2, nums.size());
//   for (int i = 0; i < limit; i++)
//   {
//     string set = "";
//     int temp = i;
//     // use temp not i as i working in outer loop

//     // since outer loop of size 2^n so f n=3, max divisions it will take for any num till 7 would be 3
//     // so inner loop till n as n divisions max by 2 for 2^n
//     for (int j = nums.size() - 1; j >= 0; j--)
//     {
//       // using calculation where you have a number and you find it's mode and divide by 2 to get binary equivalent
//       // in the binary equivalent if 0 then don't push in vector else do it
//       // The loop in opposite
//       int rem = temp % 2;
//       temp = temp / 2;
//       if (rem)
//       {
//         set = to_string(nums[j]) + "\t" + set;
//       }
//       else
//       {
//         // rem=0 means no remainder or don't include
//         set = "-\t" + set;
//       }
//     }
//     cout << set << "\n";
//   }
// }

int main()
{
  vector<int> nums;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }
  vector<vector<int>> ans = subsets(nums);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "[";
    for (auto j : ans[i])
    {
      cout << j << ",";
    }
    cout << "]\n";
  }

  return 0;
}