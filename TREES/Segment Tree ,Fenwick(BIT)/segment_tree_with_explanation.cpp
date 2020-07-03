#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5; 
ll a[maxn];
ll tree[2*maxn]; 

/*
We recurse from root of tree to leaves,
and put values in the tree from bottom up. 
*/
void build(int idx,int start,int end)
{
 int mid = (start + end)/2;
 if(start==end)
 {
   tree[idx] = a[mid]; 
 }
 
 build(2*idx,start,mid);
 build(2*idx+1,mid+1,end);
 
 tree[idx] = tree[2*idx] + tree[2*idx+1];
}

/*
We start from root, 
Reject the nodes that lie outside the query range.(i.e they return 0)
Return the node values that lie compeletely inside
Pass the query to childern if they are not competely inside or not compeletely outside
*/
ll query(int idx,int start,int end,int l,int r)
{
int mid = (start + end)/2;
if(end < l || start > r) { return 0; } //compeletely outside query range
if(start >= l && end <= r) { return tree[idx]; } //compeletely inside query range

int lans = query(2*idx,start,mid,l,r);
int rans = query(2*idx+1,mid+1,end,l,r);

return lans + rans; 
}

/*
Suppose we are at node x,
If left child contains the index(i) to be updated we recurse down the left 
child,else right child. 

Basically, we are rejecting all nodes that do not contain index to be updated.
Once we reach bottom, we just build the path we came from bottom to up.
*/
void update(int idx,int start,int end,int i,int val)
{
int mid = (start + end)/2; 

if( i < start || i > end ) { return; } // No overlap
if(start == end) { tree[idx] = val; } // reached leaf node.

update(2*idx,start,mid,i,val);
update(2*idx+1,mid+1,end,i,val);

tree[idx]  = tree[2*idx] + tree[2*idx+1]; 
}

int main()
{
  int i,j,n;
  cin>>n;
  for(int i=0;i<n;i++) { cin>>a[i]; }
  build(1,0,n-1); // root node of seqtree is at index 1.
  
}
