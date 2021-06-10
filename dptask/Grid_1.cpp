#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mod 1000000007
#define pi 3.141593
#define m 1001
int row,col;
char grid[m][m];
ll dp[m][m];
ll foo(int i,int j)
{
    if(i==row && j==col)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int x=0,y=0;
    if(i+1<=row)
        if(grid[i+1][j]=='.')
            x=foo(i+1,j)%mod;
    if(j+1<=col)
        if(grid[i][j+1]=='.')
            y=foo(i,j+1)%mod;
    return dp[i][j]=(x+y)%mod;
}
int main()
{
    cin>>row>>col;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            cin>>grid[i][j];
            dp[i][j]=-1;
        }
    }
    cout<<foo(1,1)%mod<<endl;
}
