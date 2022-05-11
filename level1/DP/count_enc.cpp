// https://www.youtube.com/watch?v=jFZmBQ569So&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=20
#include <iostream>
#include "string"
using namespace std;

char a[] = {'a',
            'b',
            'c',
            'd',
            'e',
            'f',
            'g',
            'h',
            'i',
            'j',
            'k',
            'l',
            'm',
            'n',
            'o',
            'p',
            'q',
            'r',
            's',
            't',
            'u',
            'v',
            'x',
            'y',
            'z'};

int dp[20] = {};
void count_enc(string str)
{
  int len = str.length();
  dp[0] = 1; //  base case as any number 1-9 will be valid and will have single substr valid
  // as it will never start from "0" given in ques
  for (int i = 1; i < len; i++)
  {
    // four cases
    // 1. when i and i-1th substr are both "00"
    if (str[i - 1] == '0' && str[i] == '0')
    {
      dp[i] = 0; //  now way if both 0 as you can't check for both i-1 and i,i-1 as "00" and "0" cant be a number
    }
    else if (str[i - 1] == '0' && str[i] != '0')
    {
      // have to be combined noting the case they are less than 26
      dp[i] = dp[i - 1];
      // If string is "12305" then you can call "1230" +"5" separately but not "123"+"05" meaning you can call
      // dp[i-1] for "1230"+"5" but not "123"+"05" for dp[i-2].
    }
    else if (str[i - 1] != '0' && str[i] == '0')
    {
      char first_char = str[i - 1]; //  can be either 1 or 2
      if (first_char == '1' || first_char == '2')
      {
        // for case when i==1
        dp[i] = (i >= 2 ? dp[i - 2] : 1); //  1 when i=1 or max size = 2 so since dp[i-1] already 1 or 2
        // and dp[i]=0 then it is either "10" or "20" meaning 1 total ways of substring
      }
      else
      {
        dp[i] = 0; //  if not "10" or "20" but let's say "30" then we can't call any so 0
        // as you can't call i alone and if str[i-1] not 1 or 2 as str[i]=0, then you can't call prev before i-2 so make it 0
      }
    }
    else
    {
      char fc = str[i - 1];
      char sc = str[i];
      int sumc = (fc - '0') * 10 + (sc - '0');
      // cout << "sum is " << sumc << "\n";
      // string temp_str = str.substr(i - 1, i);
      // "21123" making substr of i-1 to i of size 3 which is "123"
      // some problem in substr() as temp_str=str.substr(i,i-1) gave string of len=3 "123"
      // cout << stoi(temp_str) << "\n";
      if (sumc <= 26)
      {
        dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
      }
      else
      {
        // dp[i-1] always as single character always taken, problem with dual as it must be <=26
        dp[i] = dp[i - 1];
      }
    }
  }
  cout << dp[len - 1];
}
int main()
{

  string num;
  cin >> num;
  count_enc(num);
  return 0;
}
/*
Given 1->a, 2->b, 30->c and so on.. find the unique encodings
example - 123 can be given as "abc", "aw" and "lc"
013 is invalid as should not start with 0
103 has one encoding "jc"
303 has no encodings but can be passed so print 0

first start with "1", there is only 1 way that is to include it
then add "2", now you can make ["1","2"] or ["12"] as long as
the number lies in the 1 to 16 range and does not start with 0.

In case of "231", it will find "23" encodings which are "bc" and "w", on adding "1" we have ["bc","w","a"]
Also it can be defined as "2" + "31" but no code for 31.
Think whether you can change the last character or last 2 characters as at max value can be 26.
For "2310" we wouldn't be able to do "231" + "0" but can do "23"+"10" so dp[i] would be sum of possible dp[i-1] and dp[i-2]
where the ith number and i + i- 1th number.
Note - "0n" where n is any number is not valid as 0 can't be prefix to any number in this case and 2nd "str[i] str[i-1]" must be
btw a-z or 1-26.

Assume we have the sum for i-2, we have i-1 and i whose combination cases we have to figure out
either they can be -
0 0
0 non-0
non-0 0
non-0 non-0

1. They can neither call for just i-1, nor for both i and i-1 both
2. It can call for i but not both i-1 and i as 0 cannot prefix i
3. It can call i-1 and i but not just i as 0 not valid
4. It can call for both i and i-1 and just i considering i and i-1 are less than 26 together.
*/