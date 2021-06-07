#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define pi 3.141593
#define m 100001
int dp[m][4];
int n;
int foo(int pos,int a[],int b[],int c[],int x)
{
    int val[3];
    val[0]=a[pos];
    val[1]=b[pos];
    val[2]=c[pos];
    if(pos==n)
        return 0;
    if(dp[pos][x]!=-1)
        return dp[pos][x];
    int ans=INT_MIN;
    for(int i=0;i<3;i++)
    {
        if(x-1!=i)
        {
            ans=max(ans,val[i]+foo(pos+1,a,b,c,i+1));
        }
    }
    dp[pos][x]=ans;
    return dp[pos][x];
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<foo(0,a,b,c,0)<<endl;;
}
