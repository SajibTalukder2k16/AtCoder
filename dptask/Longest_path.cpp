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
#define m 100001
vector<int>adj[m];
vector<int>fronts;
int dp[m];
int foo(int node)
{
    if(dp[node]!=-1)
        return dp[node];
    int sz=adj[node].size();
    if(sz==0)
        return 0;
    int ans=0;
    for(int i=0;i<sz;i++)
    {
        ans=max(ans,1+foo(adj[node][i]));
    }
    return dp[node]=ans;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int nodes,edges;
    cin>>nodes>>edges;
    int n1,n2;
    map<int,bool>mp_lb;
    for(int i=0;i<edges;i++)
    {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        if(mp_lb[n1]==false)
        {
            fronts.push_back(n1);
            mp_lb[n1]=true;
        }
    }
    int sz=fronts.size();
    int ans=0;
    for(int i=0;i<sz;i++)
    {
        ans=max(ans,foo(fronts[i]));
    }
    cout<<ans<<endl;
}
