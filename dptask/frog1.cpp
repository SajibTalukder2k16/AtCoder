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
int n;
int foo(int pos,int ara[])
{
    if(pos==n-1)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    int ans1=INT_MAX,ans2=INT_MAX;
    if(pos+1<n)
        ans1=abs(ara[pos]-ara[pos+1])+foo(pos+1,ara);
    if(pos+2<n)
        ans2=abs(ara[pos]-ara[pos+2])+foo(pos+2,ara);
    dp[pos]=min(ans1,ans2);
    return dp[pos];
}
int main()
{
    cin>>n;
    int height[n];
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
        cin>>height[i];
    cout<<foo(0,height)<<endl;;
    //cout<<
}
