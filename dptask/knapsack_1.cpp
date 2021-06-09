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
ll dp[m][101];
int cap,items;
ll foo(int pos,ll now_weight,ll weight[],ll prices[])
{
    //vector<int>temp;
    if(pos==items)
        return 0;
    if(dp[now_weight][pos]!=-1)
    {
        //cout<<now_weight<<" Hello "<<pos<<" "<<dp[now_weight][pos]<<" "<<prices[pos]<<endl;
        return dp[now_weight][pos];
    }
    ll ans=0;
    if(now_weight+weight[pos]<=cap)
    {
        ans=prices[pos]+foo(pos+1,now_weight+weight[pos],weight,prices);
    }
    ans=max(ans,foo(pos+1,now_weight,weight,prices));
    dp[now_weight][pos]=ans;
    return dp[now_weight][pos];

}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>items>>cap;
    ll weight[items],prices[items];
    for(int i=0;i<items;i++)
    {
        cin>>weight[i]>>prices[i];
    }
    cout<<foo(0,0,weight,prices)<<endl;

}
