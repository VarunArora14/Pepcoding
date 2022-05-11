// https://www.youtube.com/watch?v=K5xJXbnYMBc&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=413
#include <iostream>
#include "vector"
#include "string"
using namespace std;

// number of permutations of string of length n=n! which means for each character find all possible ways
// to rearrange but with all characters in string and not substring
// Note that you have to chose the first character of your permutation which can be any
// and then choose another character recursively till base case and form permutations and return vector
void perms(string str, string asf) //  asf=> answer so far
{
  // base case
  if (str.length() == 0)
  {
    cout << asf << "\n";
    return;
    // exit fn after base case
  }
  // choose the first character
  vector<string> res;
  for (int i = 0; i < str.length(); i++)
  {
    char f = str[i];
    // do substr(0,i) + substr(i+1,str.length()) for remaining string to be called
    // recursively for finding the fiirst character
    string remain = str.substr(0, i) + str.substr(i + 1, str.length());
    perms(remain, asf + f);
    // we start from str.length and then go to 0 by choosing a character in for loop and for each character
    // running the recursive function till length is 0, we add the character to asf and when str.length=0
    // we print the answer
  }
}
// The reason we need to maintain asf(answer so far) here is bcos for each character, we need to further
// find the next possible character. In prev cases, on finding the position or answer we backtracked but here
// we would have to return the str[i] and push in vector tree so inorder to make it easier we pass the string as of now
//  as argument as we have to find ways and not reach to a certain position or answer only

int main()
{
  string str = "abc";
  int c = 2;
  // string final = str.substr(0, 2) + str.substr(3, str.length());
  perms(str, "");
  return 0;
}

/*
Another way using vector<string> would be that we have outer loop for choosing the first character like before
but rather than passing ans as argument to func, we use vector<string>

if(str.length()==0)
{
  vector<string> base;
  base.push_back("");
  return base;
}

vector<string> res;
for(int i=0;i<str.length();i++)
{
  // for each character, make it as the first character and call the function recursively
  // as we need permutations where last character can be "a" or "b" or "c"

char f = str[i];
string temp = str.substr(0,i) + str.substr(i+1,str.length());
vector<string> tempres = perms(temp);
// substring named temp is called recursively till we have last str.length=0 and then we
// push back all characters f from loop in res as res.push_back(f+tempres[i]) or
for(auto j:tempres)
{
  res.push_back(f+j);
}
// here we push all the characters in loop one by one to tempres which contains the recurive result
// first it stores "" and then after j loop, res has ["a","b","c"]
// Then it is returned and the function pops from memory stack and calls prev function
// where tempres now has ["a","b", "c"]. Now we have to make it's permutations using res we do
// call the j loop and do res.push_back(f+j) and now res which has to be returned stores
// ["ab","bc","ca","cb","ba","ac"]

// Unsure if gives unique answers and no repetitions
}
*/