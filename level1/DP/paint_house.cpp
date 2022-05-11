// https://www.youtube.com/watch?v=kh48JLieeW8&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=23
#include <iostream>
using namespace std;

void paint_house_2()
{
  // n for houses and m for colors
  int m, n;
  cin >> n >> m;
  int a[10][10] = {};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  // here we will use least and 2nd least as if we choose a color and it's val in prev case is stored in least
  // then we can use 2nd least. This would be better than

  int dp[10][10] = {};
  int least = 10000, sleast = 10000;
  // int lx = 0, ly = 0, slx = 0, sly = 0; //  least index x and y, second least x and y
  for (int i = 0; i < m; i++)
  {
    dp[0][i] = a[0][i]; // base case for first row

    if (a[0][i] < least)
    {
      least = a[0][i]; //  store the coordincates in temp
      // int temp_x = lx;
      // int temp_y = ly;

      // lx = 0; //  store the indices in lx and ly
      // ly = i;

      sleast = least;
      // slx = temp_x; //  assign old lx and ly
      // sly = temp_y;
    }
    else if (a[0][i] <= sleast)
    {
      sleast = a[0][i];
      // slx = 0;
      // sly = i;
    }
  }

  for (int i = 1; i < n; i++)
  {
    int new_least = 10000, new_sleast = 10000;
    for (int j = 0; j < m; j++)
    {
      // use the jth and not in prev column, find their least same as prev row with their indices to handle duplicates
      // if least same as dp[i-1][j] then it is from the same column
      if (least == dp[i - 1][j])
      {
        dp[i][j] = a[i][j] + sleast; //  use 2nd least if least in same column
      }
      else
      {
        dp[i][j] = least + a[i][j];
      }

      if (dp[i][j] < new_least)
      {
        new_sleast = new_least;
        new_least = dp[i][j];
      }
      else if (dp[i][j] <= new_sleast)
      {
        new_sleast = dp[i][j];
      }
    }
    least = new_least;
    sleast = new_sleast;
    // outside the first for loop as wee need the final value of new_least and new_sleast
  }

  cout << "answer is " << least;
  // This is n^3 but we can do in n^2 using least and 2nd least

  // for (int i = 1; i < n; i++)
  // {
  //   int min_val = 10000;
  //   for (int j = 0; j < m; j++)
  //   {
  //     int min_val = 10000;
  //     for (int k = 0; k < m; k++)
  //     {
  //       if (k != j)
  //       {
  //         min_val = min(min_val, dp[i - 1][k]); //  store the min color value of prev row except the current column
  //         // as no adjacent colors
  //       }
  //     }
  //     dp[i][j] = a[i][j] + min_val;
  //   }
  // }

  // The answer now is the min value in last row
  // int minval = 10000;
  // for (int i = 0; i < m; i++)
  // {
  //   minval = min(minval, dp[n - 1][i]);
  // }
  // cout << minval;
}

int main()
{
  int n; //  number of houses
  cin >> n;
  int a[20][3] = {};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> a[i][j];
    }
  }

  int incR = a[0][0], incB = a[0][1], incG = a[0][2]; //  the 2nd one is for columns
  // base case

  for (int i = 1; i < n; i++)
  {
    int new_incR, new_incB, new_incG;

    new_incR = a[i][0] + min(incB, incG);
    new_incB = a[i][1] + min(incR, incG);
    new_incG = a[i][2] + min(incR, incB);

    incR = new_incR;
    incB = new_incB;
    incG = new_incG;
  }
  cout << min(incR, min(incG, incB));

  return 0;
}
/*

You can create a 2D dp to see the answer like - dp[n][3]

// base case for first row as they will have the initial values only and can be painted by any color
// it is later we find the min val but the starting has default values
dp[0][0]=a[0][0];
dp[0][1]=a[0][1];
dp[0][2]=a[0][2];

for(int i=0;i<n;i++)
{
    dp[i][0] = a[i][0] + min(dp[i-1][2], dp[i-1][1]);
    dp[i][1] = a[i][1] + min(dp[i-1][0], dp[i-1][2]);
    dp[i][2] = a[i][2] + min(dp[i-1][0], dp[i-1][1]);
}

cout << min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));


*/

/*
Make incR, incB, incG for including red, blue and green and find min of prev remaining
if you incR then value = red_val + min(prev_blue, prev_green)

We have to find if we apply red color then what would be the minimum cost till now
1 5 7
5 8 4
3 2 9
1 2 4

Are the inputs for 4 houses, have 3 variables incR, incB, incG for including red, blue and green
        1 2 3 4

incR    1
incB    5
incG    7

The base case for first house is that you can have any color chosen
For house number 2, if we incR then choose the value of red here and the min of prev blue and green and store it
incR = 5 + min(5,7)=10
Similarly for incB, store the value of blue and prev min of red and green
incB= 8 + min(1,7) = 9
incG= 4 + min(1,5)=5

        1 2 3 4

incR    1 10
incB    5 9
incG    7 5

Keep going and then print the min of incR, incB and incG

*/