//https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
//https://www.quora.com/q/lbsknuilzujwaqtg/Cut-Vertex-Articulation-point
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(v) memset(v,0,sizeof(v)*sizeof(v[0]))
const int mxn = 1e5 + 10;

int n,m,p;//n vertices m edges

bool  vis[mxn] = {0};
bool AP[mxn] = {false};//Ap[i] means i is articulation point  
vector<int> adj[mxn];    // adjacency list
int disc[mxn]; //discovery time/number
int low[mxn]; //minumum disc value connected;
int child[mxn];//dfs tree child count(used for root)
int parent[mxn]={-1}; //

void dfs(int v)
{ static int c = 0; 
  vis[v] = true;
  disc[v] = low[v] = c++;
  child[v] = 0; 
  for(int u:adj[v])
  {
    if(!vis[u])
    { child[v]++;
      parent[u] = v;
      dfs(u);
      low[v] = min(low[u],low[v]); //parent's low changes value wrt child 
      if(parent[v]==-1 && child[v]>1)//i.e root
      {
        AP[v]=true;
      }
      if (parent[v]!=-1 && low[u]>=disc[v])
      {
        AP[v]=true;
      }
    }
    else 
    {
     low[v] = min(low[u],low[v]);
    }
  }
}
int x,y;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);cout.tie(NULL);  
cin>>n>>m; 
for(int i=1;i<=m;i++)
{
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
}
dfs(1);

for(int i=1;i<=n;i++)
{
  if(AP[i]==1){ cout<<i<<" ";}
}
return 0;
}
