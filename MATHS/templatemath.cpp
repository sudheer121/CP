/* Joined codes need each other */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define eu extendedeuclid
#define mmi modmultinverse
#define poww modexpo
#define pb push_back;

const int mod = 1e9 + 7;
ll modexpo(ll x,ll y,ll m){x=x%m;if(y==0){return 1;}if(y%2==0){return modexpo(x*x,y/2,m); }else{return(x*modexpo(x*x,y/2,m))%m; }}

ll x_1,y_1,temp,gcd;
ll extendedeuclid(ll A,ll B)
{if( B==0) {x_1=1,y_1=0;gcd=A;return gcd;}else{extendedeuclid(B,A%B);temp=x_1; x_1=y_1; y_1=temp-(A/B)*y_1;return gcd;}}
ll modmultinverse(ll A,ll M)
{ extendedeuclid(A,M);return (x_1%M+M)%M; }

const int maxn = 1e6+10;
int fact[maxn];
void initfact() {
        fact[0] = 1;
        for(int i = 1; i < maxn; i++) {
                fact[i] = (fact[i-1] * i);
                fact[i] %= mod;
        }
}
long long ncr(int n, int i) {
        long long res = fact[n];
        long long div = fact[n-i] * fact[i];
        div %= mod;  div = modexpo(div, mod - 2, mod); //using fermat's little theorem
        return (res * div) % mod;
}


const double pi = 3.14159265358979;
struct pnt
{
    ll x;
    ll y;
};
double polar(pnt a) // cartesian coordinate to polar angle in radians
{   double x = a.x , y = a.y , th;
    if(x==0) {
        (y>0)?(th=pi/2):(th=pi*(1.5));
    }
    else if(y==0) {
        (x>0)?(th=0):(th=pi);
    }
    else if(x> 0 && y > 0)
    {
        th = atan(x/y);
    }
    else if ( x > 0 && y < 0)
    {
        th = 2*pi + atan(x/y);
    }
    else
    {
        th = pi + atan(x/y);
    }
    return th;
}
ll area(pnt a,pnt b,pnt c) // triangle area
{   // returns twice area to avoid precision
    return abs( ( a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y) ) );
}


void ipgraph(int n, int m);
int a[maxn]; //data
vector<int> g[maxn];
void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
        u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

bool vis[maxn];
int pa[maxn];
void dfs(int x,int parent) // graph dfs
{
    vis[x] = 1;
    pa[x]  = parent;
    for(int u:g[x])
    {
        if(!vis[u])
        {
            dfs(u,x);
        }
    }
}

/* // tree dfs
void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}
*/


int main()
{
    return 0;
}

/*
Modulo multiplicative inverse of a with m only exits when a and m are coprime.

Fermat's little theorem:
If m is prime,
Modulo multiplicative inverse of a = (a^(m-2))%m;

*/
/*
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
*/
