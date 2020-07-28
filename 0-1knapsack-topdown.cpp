#include <bits/stdc++.h>
using namespace std;

int t[100][500];

void knapsack(int weight[] , int value[] , int c ,int n)
{

for(int i=1;i<=n;i++)
    for(int j=1;j<=c;j++)
        if(weight[i-1]<=j)
            t[i][j] = max(value[i-1] + t[i-1][j-weight[i-1]] , t[i-1][j]);  //from recursive code
        else
            t[i][j] = t[i-1][j];

}

int main()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<500;j++)
            if(i==0 || j==0)
                t[i][j] = 0;            //initialised tables first row and first coloumn to the base comdition

    int wt[]={10,20,30};
    int val[]={60,100,120};
    int C = 50;
    int size = sizeof(wt)/sizeof(int);  //input

    knapsack(wt,val,C,size);
    int answer = t[size][C];
    cout<<answer<<endl;
    
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<=C;j++)
            cout<<setw(3)<<t[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}