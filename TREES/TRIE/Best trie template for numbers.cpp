#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct trie
{
    trie* l = NULL;
    trie* r = NULL;
};
ll minxor(trie* root,ll  x,int idx)//minimum exor with number x
{ if(idx == -1) { return 0; } 
  bool p = (x >> idx) & 1;
  if(p)
  {
    if(root->r != NULL) { return pow(2,idx) + minxor(root->r,x,idx-1); }
    else { return minxor (root->l,x,idx-1); }
  }
  else
  {
    if(root->l != NULL) { return minxor (root->l,x,idx-1); } 
    else { return pow(2,idx) + minxor(root->r,x,idx-1); }
  }
}

trie* insert(trie*root,ll n,int idx) //log maxN = max idx
{ if(idx == -1) { return root; }
    bool p = (n >> idx) & 1;
    if(p)
    {   if(root->r == NULL) { root->r = new trie(); }
        root->r = insert(root->r,n,idx-1);
    }
    else
    {  if(root->l == NULL) { root->l = new trie(); }
       root->l = insert(root->l,n,idx-1); 
    }
    return root;
}

int main()
{   trie* root = new trie();
    int x = 1;
    insert(root,4,4); // now trie will make a 5 bit number 00100 since idx = 4
    insert(root,3,4); 
    insert(root,2,4);
    cout<<minxor(root,1,4);
    return 0;
}
