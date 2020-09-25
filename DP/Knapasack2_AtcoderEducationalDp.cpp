/*
Spoiler :
Since you can't maximize profit by using dp[n][weights], you can minimize total weight of items achieving a total value v. 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll wt[103];
ll p[103];
ll dp[101][100001];
const long long INF = 1e12;
int n,nn,w;
int fans=0 ;
ll rec(int n,int v)
{
    if(n==0 && v!=0)
    {
        return INF;
    }
    if(v==0) { return 0; }

    if(dp[n][v] != -1){ return dp[n][v]; }

    ll ans ;
    if(p[n] > v)
    {
        ans = rec(n-1,v);
    }
    else
    {
        ll c1 = wt[n] + rec(n-1, v-p[n]);
        ll c2 = rec(n-1,v);
        ans = min(c1,c2);
    }
    if(ans <= w) { fans = v; }
    return dp[n][v] = ans;
}

int main()
{
    cin>>n>>w;
    nn = n;
    memset(dp,-1,sizeof(dp));
    int i,j;
    for(i=1;i<=n;i++) { cin>>wt[i]; cin>>p[i]; }
    for(i=1;i<=1e5;i++)
    {
        rec(n,i);
    }
    cout<<fans;
    return 0;
}
