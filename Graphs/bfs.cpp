#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int n = 50; //total no of nodes
int s = 3;
vector<int> adj[n];
//vector<vector<int>> adj;  // adjacency list representation

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);
//  d[i] is distance of node i  from source
//  p[i] is parent of node i
void bfs(int s)
{
q.push(s);
used[s] = true;
p[s] = -1;
while(!q.empty())
{
  int v = q.front(); q.pop();
  cout<<v<<" ";
  for (int u : adj[v])
  {
  if(!used[u]) { used[u] = 1; 
  q.push(u); d[u] = d[v] + 1 ; p[u] = v ; 
               }  
  }
}
}
int main() {
int edges,source,x,y;
cin>>edges;
for(int i=0;i<edges;i++)
{
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
}
cin>>source;
bfs(source);
}
