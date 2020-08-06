//https://www.hackerearth.com/problem/algorithm/playing-with-digits-4e25844f/description/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> num;
vector<int> prm;
ll l,r,k;
ll dp[20][2][1001][100];

ll rec(int pos,int f,int mul,int sum)
{
    if( dp[pos][f][mul][sum]!= -1 ){ return dp[pos][f][mul][sum]; }
    if(pos == num.size())
    {
        if(binary_search(prm.begin(),prm.end(),sum) && mul==0){ return 1; }
        return 0;
    }
    ll ans = 0;
    int lim = 9 ;
    if(f == 0) lim = num[pos];

    int i;
    for(i=0;i<=lim;i++)
    {
        if(i<lim) ans += rec(pos+1,1,(mul*10 + i)%k,sum+i);
        else ans += rec(pos+1,f,(mul*10 + i)%k,sum+i);
    }

    return dp[pos][f][mul][sum] = ans;
}

ll solve(ll l)
{
    memset(dp,-1,sizeof(dp));
    string str = to_string(l);
    num.clear();
    for(char x:str){ num.push_back(x-'0'); }
    ll ans = rec(0,0,0,0);
    return ans;
}
int sod(ll x)
{
    int sum = 0;
    while(x!=0) { sum+=x%10; x/=10; }
    if(binary_search(prm.begin(),prm.end(),sum)){ return 1;}
    else return 0;
}
int main()
{
    int i,j;
    for(i=2;i<100;i++)
    {
        for(j = 2; j<i; j++){ if(i%j==0){ break;} }
        if(j==i || i==2) { prm.push_back(i); }
    }
    cin>>l>>r>>k;
    if( l > r ){ swap(l,r); }
    if(k < 1000)
    { cout<<solve(r) - solve(l-1); }
    else
    {
        int cnt = 0;
        if(l%k != 0) { l = l-l%k + k; }
        while(l<=r)
        {
            cnt += sod(l);
            l += k;
        }
        cout<<cnt;
    }
}
