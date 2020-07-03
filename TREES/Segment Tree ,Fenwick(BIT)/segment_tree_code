#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5; 
ll a[maxn];
ll tree[2*maxn]; 

// ss = segment start
// se = segment end
// si = segment index
// qs = query start
// qe = query end 

void build(int si,int ss,int se)
{
 int mid = (ss + se)/2;
 if(ss==se)
 {
   tree[si] = a[mid]; 
 }
 
 build(2*si,ss,mid);
 build(2*si+1,mid+1,se);
 
 tree[si] = tree[2*si] + tree[2*si+1];
}

ll query(int si,int ss,int se,int qs,int qe)
{
int mid = (ss + se)/2;
if(se < qs || ss > qe) { return 0; } //compeletely outside query range
if(ss >= qs && se <= qe) { return tree[si]; } //compeletely inside query range

int lans = query(2*si,ss,mid,qs,qe);
int rans = query(2*si+1,mid+1,se,qs,qe);

return lans + rans; 
}

void update(int si,int ss,int se,int i,int val)
{
int mid = (ss + se)/2; 

if( i < ss || i > se ) { return; } // No overlap
if(ss == se) { tree[si] = val; } // reached leaf node.

update(2*si,ss,mid,i,val);
update(2*si+1,mid+1,se,i,val);

tree[si]  = tree[2*si] + tree[2*si+1]; 
}

int main()
{
  int i,j,n;
  cin>>n;
  for(int i=0;i<n;i++) { cin>>a[i]; }
  build(1,0,n-1); // root node of seqtree is at index 1.
  
}
