Problem Name: Optimal Game Strategy-II
Problem Difficulty: None
Problem Constraints: 1 < N <= 10000 , N is always even<br>
0 <= A<sub>i</sub> <= 1000000
Problem Description:
Piyush and Nimit are playing a coin game. They are given n coins with values x<sub>1</sub>, x<sub>2</sub> .... x<sub>n</sub> where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format: First line contains the number of coins 'n'. <br>Second line contains n space separated integers where ith index denotes the value of ith coin.
Sample Input: 4
1 2 3 4
Output Format: Print a single line with the maximum possible value that Piyush can win with.
Sample Output: 6



=====Solution=====
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll coins[10005];
ll dp[5000][5000];

ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }
    if(i<5000 && j<5000){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    }

    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    ll ans = max(pickFirst,pickLast);

    if(i<5000 && j<5000){
        dp[i][j] = ans ; 
    }

    return ans;
}


int main() {
    ll n;
    cin >> n;   
    
    for(ll i=0;i<n;i++){
        cin >> coins[i];
    }

    memset(dp,-1,sizeof(dp)) ;
    cout << optimalGame(0,n-1);

    return 0;
}
