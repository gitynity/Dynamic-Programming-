// https://cses.fi/problemset/task/1636/

#include<bits/stdc++.h>
using namespace std;

/*

RECURSIVE SOLUTION

int ways(int* coins , int n , int sum)
{
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    if(coins[n-1]<=sum)
    {
       return ways(coins , n-1 , sum) + ways(coins , n , sum - coins[n-1]); //if you remove the keyword remove from this statement , the program does not give the expected output.
    }                                                                       //return keyword is important here
    else
    {
       return ways(coins , n-1 , sum);                                      //and here
    }
    
}

*/

//DP SOLUTION

int dpways(int *coins, int n, int sum)
{
    int dp[n + 1][sum + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = (dp[i][j - coins[i - 1]] + dp[i - 1][j]) % 1000000007;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum;
    cin >> n >> sum;

    int coins[n];

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << dpways(coins, n, sum);
    return 0;
}
