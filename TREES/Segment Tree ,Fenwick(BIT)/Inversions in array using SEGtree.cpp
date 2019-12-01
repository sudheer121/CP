//Counting number of inversions in an array in nlogn time using bit.
// Best Resource : http://pavelsimo.blogspot.com/2012/09/counting-inversions-in-array-using-BIT.html
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define max 200100
#define el cout<<endl;
int n;
ll a[max];
ll b[max];
ll tree[max] = {0};
// eg. a = [1000,4,5,4]
void update(int node,int l,int r,int idx)
{
   if(l==r) { tree[node]++; return;} 
   int mid = (l+r)/2;
   if(l<=idx && idx<=mid)
   {
       update(2*node,l,mid,idx);
   }
   else
   {
       update(2*node+1,mid+1,r,idx);
   }
   tree[node] = tree[2*node] + tree[2*node+1];
}
ll query(int node, int start, int end, int l, int r)
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
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

int main()
{  ll x, inv_count = 0 ;
ios_base::sync_with_stdio(false); cin.tie(NULL);
cin>>n;
for(int i=1;i<=n;i++) { cin>>a[i]; b[i-1]=a[i]; }
sort(b,b+n);//nlongn
for(int i=0;i<n;i++)
{
     int rank = int(lower_bound(b, b + n, a[i+1]) - b); //gives vakues 0 to n-1
     a[i+1] = rank+1; 
}
// If previously a = [1000,4,5,4] .Now a = [3,2,1,2]
//till this point the max value of a[i] will be n if all elements are distinct 
//hence now the values will fit into bit


for(int i=n;i>0;i--) //start reading from end and update the cooresponding element
{   if(a[i]!=1)
    { x = query(1,1,n,1,a[i]-1); }//gives the number of numbers less than a[i]
    cout<<a[i]<<endl;
    update(1,1,n,a[i]);
    inv_count += x;
    
    cout<<x; el
}
    cout<<inv_count;
    return 0;
}


