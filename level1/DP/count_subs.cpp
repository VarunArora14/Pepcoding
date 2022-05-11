// https://www.youtube.com/watch?v=IV9pbZsi5cc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=21
#include <iostream>
using namespace std;

int main()
{
  string str;
  cin >> str;
  int a = 0, ab = 0, abc = 0; //  for a+, a+b+ and a+b+c+ count

  for (int i = 0; i < str.length(); i++)
  {
    // check if the character a or b or c
    if (str[i] == 'a')
    {
      // if we encounter just a then we have to add 1 also kindof like the base case
      // as other cases depend on result of a
      a = 2 * a + 1;
    }
    else if (str[i] == 'b')
    {
      ab = 2 * ab + a;
    }
    else
    {
      abc = 2 * abc + ab;
    }
  }
  cout << abc;
  return 0;
}
/*
Given a sequence find number of a+b+c+ subsequences which means all a's together, then all b's then c's
Let's have a sequence
        a b c a' b' c'
a+     0
a+b+   0
a+b+c+ 0

initally all 0, going from left to right we have a coming first so a+ has 1 subsequence had there only been "a"
, others not affected. When you go to "b" a+b+ has 1 subsequence while a+b+c+ has 0. The one a+ subsequence remains
as we care about is a+ sequence
          a b c a' b' c'
a+     0  1 1
a+b+   0  0 1
a+b+c+ 0

Formulas are =>
2a+1 for a
2b+a for b
2c+b for c

Now coming at a', till now all have 1 subsequence but now things change here.
At a', the formula is (2*a+1) meaning with a, the new a' can come in 2 ways, either be a part of subsequence
or not be a part of it. The +1 is for a' which itself is a subsequence.
The total subsequences are "a", "aa'" and "a'". So at a', number of subsequence of a+ are 3 and others remain 1.

          a b c a' b' c'
a+     0  1 1 1 3
a+b+   0  0 1 1 1
a+b+c+ 0  0 0 1 1

Now impact will be on a+b+ and (a+ and a+b+c+) will remain having 3 subsequences.
The formula here is (2b+a) where 2 means it has 2 choices either to be with a+b+ old subsequence or not be
with them and +a means that b' will have to be added to all subsequences of a till now.

2*ab => "abb'", "ab" (one is being part of the old subsequence and other not be so 2 choices)
+a => " ab' ", " aa''b' ", " a'b' " (these 3 from above will be added as new subsequences)

Totall = 2*1 + 3=5 (where 1 is number of times prev a+b+ was there)

For c', a+ and a+b+ remain same
Here the formula would be (2c+b) meaning for prev "abc" subsequence, the new one has 2 choices, to be or not
be a part of it so 2*abc till now and +b for all the subsequences of b(or a+b+) till now

2abc => "abc", " abcc' " (c' has choice to be or not be a part of subsequence)
+b => " abc' ", " abb'c' ", " ab'c' ", " aa'b'c' ", " a'b'c' "
Total = 2*1 + 5=7

*/