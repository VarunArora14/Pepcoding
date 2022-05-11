// https://www.youtube.com/watch?v=F6T3tD8Pw20&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=403
#include <iostream>
#include "vector"
#include "string"
using namespace std;

vector<string> maze(int sr, int sc, int dr, int dc)
{
  // base case
  if (sc == dc && sr == dr)
  {
    vector<string> base;
    base.push_back("");
    return base;
  }

  // now we can move r1,r2,r3(right), d1,d2,d3(diagonal) and b1,b2,b3(bottom)
  vector<string> r1, r2, r3, d1, d2, d3, b1, b2, b3, paths;
  // RIGHT
  if (sc <= dc + 1)
  {
    r1 = maze(sr, sc + 1, dr, dc); //  move right once if sc smaller than dc by at least 1
  }
  if (sc <= dc + 2)
  {
    r2 = maze(sr, sc + 2, dr, dc); //  move right once if sc smaller than dc by at least 2
  }
  if (sc <= dc + 3)
  {
    r3 = maze(sr, sc + 3, dr, dc); //  move right once if sc smaller than dc by at least 3
  }

  // BOTTOM
  if (sr <= dr + 1)
  {
    b1 = maze(sr + 1, sc, dr, dc); //  move bottom by 1 if sc smaller than dr byt at least 1
  }
  if (sr <= dr + 2)
  {
    b2 = maze(sr + 2, sc, dr, dc); //  move bottom by 1 if sc smaller than dr byt at least 2
  }
  if (sr <= dr + 3)
  {
    b3 = maze(sr + 3, sc, dr, dc); //  move bottom by 1 if sc smaller than dr byt at least 3
  }

  // DIAGONAL
  if (sr <= dr + 1 && sc <= dc + 1)
  {
    d1 = maze(sr + 1, sc + 1, dr, dc); //  move diagonal if sc and sr are smaller than sr and dc by at least 1
  }
  if (sr <= dr + 2 && sc <= dc + 2)
  {
    d2 = maze(sr + 2, sc + 2, dr, dc); //  move diagonal if sc and sr are smaller than sr and dc by at least 3
  }
  if (sr <= dr + 3 && sc <= dc + 3)
  {
    d3 = maze(sr + 3, sc + 3, dr, dc); //  move diagonal if sc and sr are smaller than sr and dc by at least 3
  }

  // now for paths
  // right
  for (auto i : r1)
  {
    paths.push_back("r1" + i);
  }
  for (auto i : r2)
  {
    paths.push_back("r2" + i);
  }
  for (auto i : r3)
  {
    paths.push_back("r3" + i);
  }

  // bottom
  for (auto i : b1)
  {
    paths.push_back("b1" + i);
  }
  for (auto i : b2)
  {
    paths.push_back("b2" + i);
  }
  for (auto i : b3)
  {
    paths.push_back("b3" + i);
  }

  // diagonal
  for (auto i : d1)
  {
    paths.push_back("d1" + i);
  }
  for (auto i : d2)
  {
    paths.push_back("d2" + i);
  }
  for (auto i : d3)
  {
    paths.push_back("d3" + i);
  }

  return paths;
}
// if you were not just constrained to r1,r2 and r3 and can go till rn where n can be any number
// it is better to use loop
/*
// loop for moving from 1 to max dc-sc+1 moves for right, left and diagonal
// rather than using if condition to check if sc<dc, we use the loop moving condition with same
for(int i=1;i<=dc-sc+1;i++)
{
  vector<string> rpath = maze(sr,sc+i,dr,dc);
  for(auto path:rpath)
  {
    paths.push_back("r"+char(i)+path);
  }
}

// make same loop for diagonal and bottom too. For diagonal path,
for(int i=1;i<=dr-sr+1 && i<=dc-sc+1;i++)
{
  vector<string> dpath = maze(sr+i,sc+i,dr,dc);
  for(auto path:dpath)
  {
    paths.push_back("d"+char(i)+path);
  }
}
*/

int main()
{
  int n = 3, m = 3;
  vector<string> ans = maze(0, 0, n - 1, m - 1);
  for (auto i : ans)
  {
    cout << i << "\n";
  }
  return 0;
}
/*
Now you can jump too and move diagonal too
*/