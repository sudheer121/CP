// Suppose the graph is undirected and connected then the whole graph is a SCC, but if graph is directed then we need Kosaraju's algo for finding each SCC
/*
In a strongly connected component, every vertex is reachable from every other vertex. 

*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define pb push_back
#define vi vector<int> 

const int mod  = 1e9+7;
const int maxn = 1e5 + 10;
int n,m;
int a[maxn];
vi adj[maxn],radj[maxn];
bool vis[maxn];
int x,y;
stack<int> stk; 
void dfs1(int v)
{
    if(!vis[v])
    {   vis[v] = 1;
        for(int u:adj[v])
        {   
            dfs1(u);
        }
        stk.push(v);
    }
}
void dfs2(int v)
{
    if(!vis[v])
    {   vis[v] = 1;
        for(int u:radj[v])
        {   
            dfs2(u);
        }
    }
}
int kosarajus()
{
int cnt = 0; // no of strongly connected components
for(int i=1;i<=n;i++)
{
    if(!vis[i])
    {
dfs1(i); 
    }
}
memset(vis,0,sizeof(vis));

while(!stk.empty())
{
int x = stk.top();
stk.pop();
if(!vis[x]) { cnt++; dfs2(x); }
}

return cnt;
}
int main()
{
fastio; 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif 
int i,j;
cin>>n;
/*for(int i=0;i<n;i++)
{ cin>>a[i]; }*/
cin>>m;
for(int i=0;i<m;i++)
{
    cin>>x>>y;
    adj[x].pb(y);  //actual graph
    radj[y].pb(x); //reverse graph
}
cout<<kosarajus();
return 0;
}
//g++ -g c.cpp -o c.exe
/*
Example:
10
12
1 2 
2 3 
3 1
3 4
4 5
5 6 
6 7
7 4 
4 10
8 7 
8 9 
9 8

Ans = 4 

*/ 
