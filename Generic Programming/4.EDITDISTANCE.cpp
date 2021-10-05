Problem Name: EDIT DISTANCE
Problem Difficulty: None
Problem Constraints: 1<=|s1|,|s2|<=2000
s1 and s2 contains only lowercase English letters.
Problem Description:
You are given 2 strings *s1* and *s2*. You can perform the following operations on them:<ol>
<li>Insert a character at any position.
<li>Remove a character from any position.
<li>Replace a character with any other character.
</ol>
Find the minimum number of these operations required to convert *s1* to *s2*.

Input Format: First line contains string *s1*. Second line contains string *s2*.
Sample Input: abcde
bcdae
Output Format: Print a single integer denoting the minimum number of operations required.
Sample Output: 2




=====Solution=====

#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 2001
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define mod 341550071728321ll
#define mod1 mod
#define mod2 3825123056546413051ll
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-11
#define pll pair<ll,ll>
#define pbc pop_back
 
using namespace std;
const ldb pi=3.141592653589793238462643383;

int dp[nn][nn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int i=0;i<=m;i++)
        dp[0][i]=i;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i+1][j+1]=dp[i][j];
            }
            else
                dp[i+1][j+1]=min(dp[i+1][j],min(dp[i][j+1],dp[i][j]))+1;
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}