//https://practice.geeksforgeeks.org/problems/number-of-coins/0

#include<bits/stdc++.h>
#define large_value 10000000;
using namespace std;

bool possibledp(int sum, int *denominations, int n)
{

  bool dp[sum + 1] = {false};
  dp[0] = true;

  for (int i = 1; i <= sum; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (denominations[j] > i)
      {
        dp[i] = false;
      }
      else
      {
        dp[i] = dp[i] or dp[i - denominations[j]];
        if (dp[i] == true)
          break;
      }
    }
  }

  return dp[sum];
}

//**********************************************************************

long long minimumwaystochangecoins(int sum, int *denominations, int n)
{

  long long dp[sum + 1];
  
  for (int i = 0; i <= sum; i++)
    dp[i] = large_value;
  
  dp[0] = 1;
  
  for (int i = 0; i < n; i++)
    if (denominations[i] <= sum)
      dp[denominations[i]] = 1;

  for (int i = 0; i <= sum; i++)
  {
    if (dp[i] == 1)
      continue;
  
    for (int j = 0; j < n; j++)
    {
      if (denominations[j] < i)
        dp[i] = min(dp[i], dp[i - denominations[j]]);
  
      else
        break;
    }
  
    dp[i]++;
  }
  
  return dp[sum];
}

//***************************************************************8

int main()
{
    int t , v , n;
    cin>>t;
    int coins[1000000];
    while(t--)
    {
        cin>>v>>n;
        for(int i=0;i<n;i++)
        cin>>coins[i];
        
        sort(coins , coins+n);
        
        bool res = possibledp(v,coins,n);
        if(res)
        {
            cout << minimumwaystochangecoins(v, coins, n)<<"\n";
        }
        else
            cout<<-1<<"\n";
    }
    return 0;
}
