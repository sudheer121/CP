//0-1 Knapsack -> maximize total cost of items in knapsack
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int cost[maxn];
int weight[maxn];
int wt,n;

ll dp[2002][2002];
int knapsack(int n,int wt)
{
    if(n==0 || wt==0) { return 0; }
    if(dp[n][wt]!=-1) { return dp[n][wt]; }
    if(weight[n] > wt) {
        return dp[n][wt] = knapsack(n-1,wt);
    }

    ll c1 = cost[n] + knapsack(n-1,wt-weight[n]); //choice 1: put it in bag
    ll c2 = knapsack(n-1,wt); // choice2 : don't put it
    return  dp[n][wt] = max(c1,c2);
}

int main()
{
    int i,j;
    memset(dp,-1,sizeof(dp));
    cin>>n>>wt;
    for(i=1;i<=n;i++) { cin>>cost[i]; }
    for(i=1;i<=n;i++) { cin>>weight[i]; }
    cout<<knapsack(n,wt);
    return 0;
}
