#include <bits/stdc++.h>
using namespace std;

    //recursive approach

    int knapsack(int weight[] , int value[] , int c , int n)
    {
        if(n==0||c==0)  //base case
        return 0;
        
        if(weight[n-1]<=c)
        {
            return max( value[n-1] + knapsack(weight , value , c-weight[n-1] , n-1) , knapsack(weight , value , c , n-1) ); 
        }

        else
        {
            return knapsack(weight , value , c , n-1);
        }
        
    }
int main()
{ 
    int wt[]={10,20,30};
    int val[]={60,100,120};
    int C = 50;
    int size = sizeof(wt)/sizeof(int);
    
    int answer = 0;
    answer = knapsack(wt,val,C,size);
    cout<<answer;
    return 0;
}