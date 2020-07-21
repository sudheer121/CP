https://codeforces.com/contest/86/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fo(i,j,k) for(i=j;i<k;i++)
#define pb push_back
const int maxn = 2e6 + 10 ; 
int n,t,a[maxn];
ll cnt[maxn],ansf[maxn]; 
int blk; 
struct Query
{
  int i,l,r;
};
bool cmp(Query a,Query b)
{
    if(a.l/blk != b.l/blk){ return a.l/blk < b.l/blk ; }
    else return a.r < b.r ; 
}
vector<Query> v; 
ll ans = 0; 
void add(int idx)
{
    ans -= cnt[a[idx]]*cnt[a[idx]]*a[idx];
    cnt[a[idx]]++;
    ans += cnt[a[idx]]*cnt[a[idx]]*a[idx];
}
void rem(int idx)
{
    ans -= cnt[a[idx]]*cnt[a[idx]]*a[idx];
    cnt[a[idx]]--;
    ans += cnt[a[idx]]*cnt[a[idx]]*a[idx];
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>t;
    blk = (int)sqrt(n+.0) + 1; 
    int i,x,y; 
    Query temp; 
    fo(i,0,n)
    {
        cin>>a[i]; 
    }
    fo(i,0,t)
    {
        cin>>x>>y; 
        x-- ; y -- ; 
        temp.i = i; temp.l = x ; temp.r = y;
        v.pb(temp); 
    }
    sort(v.begin(),v.end(),cmp);
    int lptr = -1, rptr = -1; 
    fo(i,0,t)
    {
        int l = v[i].l;
        int r = v[i].r; 
        while(rptr < r){ add(++rptr); }
        while(rptr > r){ rem(rptr--); }
        while(lptr < l)
        {
            if(lptr != -1){ rem(lptr); } 
            lptr++; 
        }
        while(lptr > l){ add(--lptr); }
        ansf[v[i].i] = ans; 
    }
    
    fo(i,0,t)
    {
        cout<<ansf[i]<<"\n"; 
    }
    return 0; 
}
