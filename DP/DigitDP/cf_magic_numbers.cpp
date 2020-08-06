#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll dp[2020][2020][2];
vector<int> num;
string l,r;
int m,d;
int sz;
ll rec(int pos,int mul, bool f)
{
    if(dp[pos][mul][f] != -1) { return dp[pos][mul][f]%=mod; }
    if(pos == num.size())
    {
        if(mul == 0) { return 1; }
        return 0;
    }
    ll ans = 0;
    int lim = 9;
    if(f==0) {
    lim = num[pos];
    }

    if(pos%2)
    {
        if(d < lim){ ans += rec(pos+1,(mul*10+d)%m,1); }
        else if(lim == d) { ans += rec(pos+1,(mul*10+d)%m,f); }
        else return 0;
    }
    else
    {
        int i;
        for(i=0;i<=lim;i++)
        {
            if(i==d){ continue; }
            if(i<lim) ans += rec(pos+1,(mul*10+i)%m,1);
            else ans += rec(pos+1,(mul*10+i)%m,f);
            if(ans > mod) { ans %= mod; }
        }
    }
    if(ans > mod) { ans %= mod; }
    return dp[pos][mul][f] = ans%mod;
}

ll solve(string x)
{
    num.clear();
    int i;
    memset(dp,-1,sizeof(dp));

    for(i=0;i<x.size();i++) { num.push_back(x[i]-'0'); }
    sz = num.size();
    ll ans = rec(0,0,0);
    //cout<<ans<<endl;
    return ans;
}
int isit(string l)
{   int n = l.size();
    int i;
    for(i=0;i<n;i++)
    {
        if(i%2 && l[i]-'0' != d){ return 0; }
        else if(i%2==0 && l[i]-'0' == d){ return 0; }
    }
    int mul = 0;
    for(int i=0;i<l.size();i++)
    {
        mul = (mul*10 + l[i] - '0')%m;
    }
    if(mul != 0) { return 0; }
    return 1;
}
int main()
{   // m = 19, d = 7, l = "1000" , r = "9999";
    cin>>m>>d;
    cin>>l>>r;
    cout<<(solve(r) - solve(l) + isit(l) + mod)%mod;
    return 0;
}
