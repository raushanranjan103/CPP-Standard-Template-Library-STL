Problem Name: Square Brackets
Problem Difficulty: 
Problem Constraints: 1 <= n <= 50.
0 <= k <= n.
Problem Description:
You are given:
<ul>
<li>a positive integer <b>n</b>.<br>
<li>an integer <b>k</b>, 1<=k<=n.<br>
<li>an increasing sequence of k integers 0 < s<sub>1</sub> < s<sub>2</sub> < ... < s<sub>k</sub> <= 2n.<br>
</ul>
You have to find out the number of proper brackets sequence of length 2n which contain an opening bracket at k positions s<sub>1</sub> < s<sub>2</sub> < ... < s<sub>k</sub>. These k positions will necessarily have an opening bracket while the other positions can be either an opening bracket or a closing bracket.<br> 
Several proper bracket expressions:<br>
[[]][[[]][]] <br>
[[[][]]][][[]]<br>
An improper bracket expression:<br>
[[[][]]][]][[]]<br>
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.

Input Format: The first line consists of number of test cases T.
Each test case consists of two space seperated integers n and k.
Next line consists of k space seperated integers denoting positions of open brackets.
Sample Input: 5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
Output Format: The number of ways modulo 10^9+7.
Sample Output: 1 
0 
2 
3 
2 



=====Solution=====
#include <bits/stdc++.h>
using namespace std;

bool openIndex[50];
int dp[50][50];

//n in function is actually equal to 2*n of input
//pos indicated index
//open indicates the no of open brackets in current string

int n;

int squareBrackets(int pos = 0, int open = 0)
{
    if (open < 0)
    {
        return 0;
    }
    if (pos == n)
    {
        return (open == 0);
    }
    if (dp[pos][open] != -1)
    {
        return dp[pos][open];
    }
    int ans = 0;
    if (openIndex[pos])
    {
        return squareBrackets(pos + 1, open + 1);
    }
    ans = squareBrackets(pos + 1, open + 1) + squareBrackets(pos + 1, open - 1);

    dp[pos][open] = ans;

    return ans;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        cin >> n;
        n = n << 1;

        int k;
        cin >> k;

        memset(openIndex, 0, sizeof(openIndex));

        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            openIndex[x - 1] = 1;
        }

        memset(dp, -1, sizeof(dp));

        cout << squareBrackets() << endl;
    }

    return 0;
}