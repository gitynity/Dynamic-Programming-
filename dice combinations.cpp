//https://cses.fi/problemset/task/1633/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<long long> dp(n+1,0);
    dp[0] = 1;
    
	for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=6;j++)
		{
			if(i-j>=0)
			dp[i] = (dp[i] + dp[i-j])%1000000007;
			else break;
		}
    }
    cout<<dp[n];
}
