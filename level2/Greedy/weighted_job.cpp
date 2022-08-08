// https://www.geeksforgeeks.org/weighted-job-scheduling/
// https://www.youtube.com/watch?v=cr6Ip0J9izc
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

bool compare(vi &f, vi &s)
{
  // sort based on their ending time
  return f[1] < s[1];
}

// find next job in sorted array that doesn't conflict with jobs[i]

void sol(vvi &jobs, int n)
{
  sort(jobs.begin(), jobs.end(), compare);
  vi dp(n); // dp[i] stores the max profit till jobs[i]

  dp[0] = jobs[0][2]; // base case for first job

  // then for each job, look from j=0 if they have any non overlapping next job then store the sum else continue till i

  for (int i = 1; i < n; i++)
  {
    dp[i] = max(jobs[i][2], dp[i - 1]); // take max of prev profit and curr profit
    for (int j = i - 1; j >= 0; j--)
    {
      // from i-1 ele to 0, check if not overlap then we see the max of current job + that dp[j], dp[i]
      if (jobs[i][1] >= jobs[j][1])
      {
        // ith job has >= ending time than jth job, we take max of curr dp[i] and sum of curr job profit and that job
        dp[i] = max(dp[i], dp[j] + jobs[i][2]); // max of curr job profit and profit of jth and curr dp[i]
        break;                                  // as the first j we find from i-1 must have the max value till now
      }
    }
  }
  int maxval = INT_MIN;
  cout << "the profit is " << dp[n - 1];
}

int main()
{
  int n;
  cin >> n;
  vvi jobs(n, vi(3)); // 3 means 0 for starting time, 1 for ending time, 2 for profit
  for (int i = 0; i < n; i++)
  {
    cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
  }
  return 0;
}

/*
Since here jobs have their weights we have to maximise the weight such that no jobs overlap too. For this in a recursive manner we can either include a job or exclude and calculate the profit with the recursive function. Problem is there are overlapping subproblems.
The idea is to find the latest job before the current job (in sorted array) that doesn't conflict with current job 'arr[n-1]'.
Once we find such a job, we recur for all jobs till that job and add profit of current job to result.
This will take O(n2^n) as for each job we will search n times max for next non overlapping job and call the function for it max 2^n times by including and excluding the new job found which does not overlap making it 2^n times.

To avoid overlapping subproblems, we use DP where dp[i] stores the max profit till jobs[i]. First we store in dp[i] all their real profits and then we have
2 iterators i and j(inner) where from j to i we see if they don't overlap then store it's value
*/