#include <bits/stdc++.h>
using namespace std;

int t[100][500];     //suppose that the constratints say that the max elements < 100 and max capacity < 500

int knapsack(int weight[] , int value[] , int c , int n)
{

    //base case
    if(n==0||c==0)
    return 0;

    if(t[n][c]!=-1)     // if answer is in table , use this answer and return. So the code below this will not be executed
    return t[n][c];

    if(weight[n-1]<=c)  //if answer is not in the table lets fill the table
    {
        return t[n][c] = max(value[n-1] + knapsack(weight , value , c-weight[n-1] , n-1) , knapsack(weight,value,c,n-1));
    }
    else
    {
        return t[n][c] = knapsack(weight , value , c , n-1);
    }
}


int main()
{
    for(int i=0;i<100;i++)
    for(int j=0;j<500;j++)
        t[i][j] = -1;       //initialised the table with -1

	
    int wt[]={10,20,30};
    int val[]={60,100,120};
    int C = 50;
    int size = sizeof(wt)/sizeof(int);  //input
    
    knapsack(wt,val,C,size);    //function called
    int answer = t[size][C];    //the last cell of the table is the answer

    cout<<answer<<endl<<endl;

    for(auto i=0;i<=size;i++)
    {
        for(auto j=0;j<=C;j++)
            cout<<t[i][j]<<" ";
        
        cout<<endl;
    }
    return 0;
}
