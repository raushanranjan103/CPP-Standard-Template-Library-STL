Problem Name: 0-1 Knapsack
Problem Difficulty: None
Problem Constraints: 1 <= S,N <= 1000
Problem Description:
You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S (1 <= S <= 1000).
You also have N (1<= N <= 1000) items that you might want to take with you to the sea side.
Unfortunately you can not fit all of them in the knapsack so you will have to choose.
For each item you are given its size and its value.
You want to maximize the total value of all the items you are going to bring.
What is this maximum total value?

Input Format: On the first line you are given N and S. <br>Second line contains N space separated integer where ith integer denotes the size of ith item. Third line contains N space seperated integers where ith integer denotes the value of ith item.
Sample Input: 5 4
1 2 3 2 2 
8 4 0 5 3
Output Format: Output a single integer showing the maximum value that can be obtained by optimally choosing the items.
Sample Output: 13



=====Solution=====
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll dp[1005][1005];

//Recursive Approach
ll knapsack(ll n, ll w, ll *weights, ll *prices)
{
    //Base case
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }

    ll include = 0;
    ll exclude = 0;

    if (weights[n - 1] <= w)
    {
        //Include the current index element
        include = prices[n - 1] + knapsack(n - 1, w - weights[n - 1], weights, prices);
    }

    //Exclude the current element
    exclude = knapsack(n - 1, w, weights, prices);

    dp[n][w] = max(include, exclude);

    return dp[n][w];
}

int main()
{
    ll n, w;
    cin >> n >> w;
    ll weights[1005] = {0};
    ll prices[1005] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << knapsack(n, w, weights, prices);

    return 0;
}
