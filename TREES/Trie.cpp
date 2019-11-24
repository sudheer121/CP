#include<bits/stdc++.h>
using namespace std;
struct trie
{ trie* a[26];
  int weight;
  trie()
  {
    for(int i=0;i<26;i++){ a[i] = NULL; }
    weight = 0;
  }
};

//insert string s with weight wt in trie recursively
trie* insert(string s,int wt,int idx,trie* root) //recursive function
{ int cur = s[idx] - 'a' ; //idx = index of string s
  if( root->a[cur]==NULL ) { root->a[cur] = new trie(); } 
  root->a[cur]->weight =  max(root->a[cur]->weight , wt); 
  if(idx != s.size()-1)
  {
    insert(s,wt,idx+1,root->a[cur]);
  }
  return root;
}

int best_suggestion(string s,trie* root) //returns weight of best suggestion string
{
int max = 0;
for(int i=0;i<s.size();i++) 
{   int cur = s[i] - 'a' ;
    if(root->a[cur] == NULL){ return -1; } 
    root = root -> a[cur] ; 
    max = root->weight;
    
}
return max;
}
int main()
{   trie* root = new trie();
    root = insert("dassd",34,0,root);
    root = insert("dasse",45,0,root);
    root = insert("dassegfmkldgm",54,0,root);
    cout<<best_suggestion("dass",root);
}
