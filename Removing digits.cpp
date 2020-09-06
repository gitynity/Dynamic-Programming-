// https://cses.fi/problemset/task/1637/

#include <bits/stdc++.h>
using namespace std;

/*

int steps(int num)
{
    if (num <= 9)
        return 1;
    else
    {
        int number = num;
        int i = 1;
        int temp = INT_MAX;
        while (number)
        {
            if (i == 1 and num % 10 == 0)
            {
                i++;
                number = number / 10;
                continue;
            }
            int mod = pow(10, i);
            int divisor = pow(10, i - 1);
            temp = min(temp, steps(num - (num % mod) / divisor));
            number = number / 10;
            i++;
        }

        return 1 + temp;
    }
}

*/

int dp[1000001];

void dpsteps(int num)
{

    for (int i = 0; i <= 9; i++)
        dp[i] = 1;

    for (int i = 10; i <= num; i++)
        dp[i] = INT_MAX - 1;

    for (int i = 10; i <= num; i++)
    {
        int number = i;
        int temp = INT_MAX - 1;
        int j = 1;

        while (number)
        {
            if (j == 1 and i % 10 == 0)
            {
                j++;
                number = number / 10;
                continue;
            }
            int mod = pow(10, j);
            int divisor = pow(10, j - 1);

            temp = min(temp, dp[i - ((i % mod) / divisor)]);

            number = number / 10;

            j++;
        }
        dp[i] = 1 + temp;
    }
}

int main()
{
    int n;
    cin >> n;

    if (n <= 9)
        cout << 1 << endl;
    else
    {
        dpsteps(n);
        cout << dp[n] << endl;
    }

    return 0;
}
