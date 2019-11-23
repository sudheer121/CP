#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[100009];
ll tree[200009];
void build(ll node,ll start,ll end)
{ 
    if(start == end) { tree[node] = a[start] ;}
    else
    {   ll mid= (start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(int node, int start, int end, int idx, int val)
{//Takes O(N) time for update
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= x and x <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, x, y);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, x, y);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
/* Inefficient update bcoz it traverses through all nodes
void update(ll node,ll start,ll end,ll x,ll y)
{//update array a's index x by value y and reflect that in tree;
    if(start == end && start == x)
    {
        if(start == x) { a[x] = y ; tree[node] = y ;}
    }
    else
    {  ll mid = (start+end)/2;
       update(2*node,start,mid,x,y);
       update(2*node,mid+1,end,x,y);
       tree[node] = tree[2*node] + tree[2*node+1];
    }
}*/
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    ll mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}/*
Inefficient query bcoz traverses through all the tree nodes
int query(ll node,ll start,ll end,ll x,ll y)//add from index x to y
{
if(start<x || end<y){return 0;}
if(x<=start && end<=y )
{ return tree[node];}
ll mid = (start + end) / 2;
ll a = query(2*node,start,mid,x,y);
ll b = query(2*node,mid+1,end,x,y);
    return a+b;   
}*/
int main()
{ ll n;cin>>n;
for(ll i=0;i<n;i++){cin>>a[i];}    
build(1,0,n-1);//tree[] array indexing from 1;
for(ll i=1;i<2*n-1+1;i++){cout<<tree[i]<<" ";}cout<<endl;
    
}