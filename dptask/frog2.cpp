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
int dp[m];
int n,k;
int foo(int pos,int ara[])
{
    if(pos==n-1)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    int ans=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(pos+i<n)
            ans=min(ans,abs(ara[pos]-ara[pos+i])+foo(pos+i,ara));
        else
            break;
    }
    dp[pos]=ans;
    return dp[pos];
}
int main()
{
    cin>>n>>k;
    int height[n];
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
        cin>>height[i];
    cout<<foo(0,height)<<endl;;
    //cout<<
}
