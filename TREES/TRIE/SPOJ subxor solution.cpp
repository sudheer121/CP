//https://www.spoj.com/problems/SUBXOR/
//awesome---> https://ide.geeksforgeeks.org/jdClUUNh7A
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//1 5 2 4 1 3 2 7
struct trie
{   ll lc,rc;
    trie* l ;
    trie* r ;
    trie()
    {   l = NULL ; r = NULL;
        lc=0;rc=0;
    }
};
 
trie* insert(trie*root,ll n,int idx) //log maxN = max idx
{ if(root==NULL || idx == -1) { return root; }
    bool p = (n >> idx) & 1;
    if(p)
    {   if(root->r == NULL) { root->r = new trie(); }
        root->rc++; root->r = insert(root->r,n,idx-1);
    }
    else
    {  if(root->l == NULL) { root->l = new trie(); }
       root->lc++; root->l = insert(root->l,n,idx-1);
    }
    return root;
}
 
ll query(trie*root,ll idx,ll n,ll k)
{ if(idx == -1 || root==NULL) { return 0; }
bool p = (n >> idx) & 1;
bool q = (k >> idx) & 1;
    if(p)
    {
    if(q) { return root->rc + query(root->l,idx-1,n,k); }
    else  { return query(root->r,idx-1,n,k); }
    }
    else
    {
    if(q) { return root->lc + query(root->r,idx-1,n,k); }
    else  { return query(root->l,idx-1,n,k); }
    }
}
ll a[100100] = {0};
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);cout.tie(NULL);
ll t,n,k,p=0,ans; cin>>t;
while(t--)
{ p=0;ans = 0;
trie* root = new trie();
insert(root,0,20);
cin>>n>>k;
for(ll i=1;i<=n;i++) {
    cin>>a[i]; p = p^a[i];
    ans += query(root,20,p,k);
    insert(root,p,20);
    }
    cout<<ans<<endl;
}
    return 0;
}
