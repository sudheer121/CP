//Max exor subarray 
#include<bits/stdc++.h>
using namespace std;
#define ll long
struct trie
{ trie* a[2];
  trie()
  {
    for(int i=0;i<2;i++){ a[i] = NULL; }
  }
};
string binrep(ll x)//gives 21 bit binary representation of number x
{   string s = "";char arr[21];
    for(int i=20;i>=0;i--) //stores binary of a[i] in arr
    {
     if(x != 0){ if(x%2==0)  arr[i] = '0';  else arr[i] = '1';  x = x/2; }
     else { arr[i] = '0'; }
    }
    for(int i=0;i<21;i++) { s = s + arr[i]; } // a[i] as string in binary
    return s;
}

//insert string s with weight wt in trie recursively
trie* insert(string s,int idx,trie* root) //recursive function
{ int cur = s[idx] - '0' ; //idx = index of string s

  if( root->a[cur]==NULL ) { root->a[cur] = new trie(); }

  if(idx != s.size()-1)
  {
   root->a[cur]= insert(s,idx+1,root->a[cur]);
  }
  return root;
}

ll querymax(ll x,trie* root)//gives a number ans from tree,which gives maximum exor corresponding to x
{ ll ans = 0;
  string s = binrep(x);
  for(int i=0;i<21;i++)
  {
if(s[i]=='0')
     {
     if(root->a[1]!=NULL) { ans += pow(2,20-i); root = root->a[1];}
     else { root = root->a[0]; }
     }
else{
    if(root->a[0]!=NULL)   { root = root->a[0]; }
    else {ans += pow(2,20-i); root = root->a[1];}
    }
}
  return ans;
}

int g;
int main()
{   trie* root = new trie(); string s;
    ll n;cin>>n;
    ll a[n+1];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    /*
    for(int i=0;i<n;i++) //sets the trie for each number
    {
    cin>>a[i];
    //assuming a[i] has 20 digits max in its binary representation
    s = binrep(a[i]);
    root = insert(s,0,root);
    }
    */
    ll pre = 0; ll ans = 0;
    for(int i=0;i<n;i++) //find max exor subarray in array
    {
       pre = pre^a[i];
       s = binrep(pre);
       root = insert(s,0,root);
       cout<<pre<<" "<<querymax(pre,root)<<endl;
       ans = max(ans,pre^querymax(pre,root));

    }
    cout<<ans;
}




