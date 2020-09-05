//https://cses.fi/problemset/task/1635/

#include <bits/stdc++.h>
using namespace std;

/*

int coins[] = {2, 3, 5};
int ways = 0;

void count(int sum)
{
	if (sum == 0)
	{
		ways++;
		return;
	}

	if (sum < 0)
		return;

	for (int i : coins)
		count(sum - i);
}

*/

void dpcount(int sum, int *coins, int n, int *dp)
{
	dp[0] = 1;

	for (int i = 1; i <= sum; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (coins[j] <= i)
			{
				dp[i] = (dp[i] + dp[i - coins[j]]) % (1000000007);
			}
		}
	}
}

int main()
{
	int n, x;
	cin >> n >> x;

	int coins[n];

	for (int i = 0; i < n; i++)
		cin >> coins[i];

	int dp[x + 1];
	memset(dp, 0, sizeof(dp));

	dpcount(x, coins, n, dp);

	cout << dp[x];
}
