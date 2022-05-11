// https://www.youtube.com/watch?v=XtmW3a8Q9M4&list=PL-Jc9J83PIiE-181crLG1xSIWhTGKFiMY&index=3
#include <iostream>
#include "vector"
#include "map"
#include "string"
#include "cmath"
using namespace std;

// change void to int return type
void max_words(vector<string> words, vector<char> letters, vector<int> score)
{
  map<char, int> m2;
  for (char c : letters)
  {
    m2[c]++;
  }
  // map string to char:int map
  for (auto i : m2)
  {
    cout << i.first << " " << i.second << "\n";
  }

  // create subsets of words
  vector<vector<string>> word_combos;
}

int sol(vector<string> words, vector<int> &freq, vector<int> score, int idx)
{
  if (idx == words.size())
  {
    return 0;
  }

  // Another thing we could have done rather than maintaining not_score would be to run a loop
  // across all the words checking if current word is valid and if true then add recursive func for i+1
  // and if not then make freq back to normal

  // Don't include the word

  // we make the change in freq array if the word is used, otherwise idx changes only for the next word
  int not_score = 0 + sol(words, freq, score, idx + 1); //  score when not included
  // here 0 is the sum of words score when current word not icnluded

  // Include the word

  // if included the it will contri to score
  int score_word = 0; //  score for ith index
  // check for validity and if valid then use
  bool isValid = true;
  for (char c : words[idx])
  {
    if (freq[c - 'a'] == 0) //  can't use the character as it's frequence is 0
    {
      isValid = false;
    }
    freq[c - 'a']--;
    score_word += score[c - 'a']; //  increase the score
  }
  int yes_word = 0;
  if (isValid)
  {
    // means word is valid, so include it's score and check for remaining indexes with change in freq
    yes_word = score_word + sol(words, freq, score, idx + 1);
  }
  // Now,we have to change freq back to what it was if not valid. Having break statement
  // would make it wrong as we would have not known which freq were reduced

  for (char c : words[idx])
  {
    freq[c - 'a']++;
  }
  return max(not_score, yes_word); //  max of score not icnluding the current word and ans by including the word
}

int main()
{
  int word_len;
  cin >> word_len;
  vector<string> words;
  for (int i = 0; i < word_len; i++)
  {
    string temp_word;
    cin >> temp_word;
    words.push_back(temp_word);
  }
  vector<char> letters;
  int char_len;
  cin >> char_len;
  for (int i = 0; i < char_len; i++)
  {
    char temp_char;
    cin >> temp_char;
    letters.push_back(temp_char);
  }
  vector<int> score(27);
  for (int i = 0; i < 26; i++)
  {
    cin >> score[i];
  }
  // for freq we use map
  vector<int> freq(27);
  for (char ch : letters)
  {
    freq[ch - 'a']++;
  }
  // for (auto i : freq)
  // {
  //   cout << i << " ";
  // }
  // cout << "\n";
  // max_words(words, letters, score);
  sol(words, freq, score, 0);
  return 0;
}
/*
what mainly matters here is frequency of alphabets and not what alphabets are used.
Find all possible subsets of words that have same or less than freq of words with max value
Here we have 2^4 subsets, which means to include or not include a word. Make subsets and check if they are
valid with frequency of letters of words <= input frequency of letters.
If true then store the value nd compare the max values

We have to check that freq of letters don't exceed and for others we add 0. Find all ways of words 2^n
and check score and return maxval
*/