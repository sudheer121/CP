//Kruksal's algorithm to find the minimum spanning tree
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int maxn = 1e5+10;
pair <ll, pair<int, int> > p[maxn];
int n,m; // n nodes and m edges
int id[maxn];
void initialize()
{
  for(int i=1;i<maxn;i++){ id[i]=i; }
}
int root(int x)
{
  while(id[x]!=x)
  { id[x] = id[id[x]];//for flattening the tree
    x = id[x];
  }
  return x;
}
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

ll kruksal(pair <ll, pair<int, int> > p[])
{  ll x,y,wt,mincost=0;
  for(int i=0;i<m;i++)//iterate over edge in asc order
  {
     x = p[i].second.first;
     y = p[i].second.second;
     wt = p[i].first;

     if(root(x)!=root(y)) //check if disconnected
     { 
       mincost+=wt;
       union1(x,y);
     }
  }
return mincost;
}
int main()
{
initialize(); // very very important
cin>>n>>m; int u,v; ll edge;
for(int i=0;i<m;i++)
{
cin>>u>>v>>edge;
p[i] = make_pair( edge, make_pair(u,v) );
}
sort(p,p+m);
ll mincost = kruksal(p);
cout<<mincost<<endl;
return 0;
}
//O(mlogn)
