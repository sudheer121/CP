//suffix array
#include <bits/stdc++.h>
using namespace std;
string s;
int suffixarr[100100];//contains 
struct sfx
{
  int idx; int r1; int r2;
};
bool cmp(sfx a,sfx b)
{
  if(a.r1 != b.r1) { return a.r1<b.r1;}
  else return a.r2<b.r2;
}
void sfxarr(string s,int n)
{
sfx arr[n];
for(int i=0;i<n;i++)
{
  arr[i].idx = i;
  arr[i].r1 = s[i]-'a';
  if(i==n-1) { arr[i].r2 = -1;continue;}
  arr[i].r2 = s[i+1] - 'a';
}
sort(arr, arr+n, cmp); 
int ind[n];// idx to position mapping
for(int k=4;k<=2*n;k*=2)
{
int new_rank = 0;
int old_rank = arr[0].r1; 
arr[0].r1 = new_rank;
ind[arr[0].idx] = 0; 
for(int i=1;i<n;i++)//assign r1
{
if(arr[i].r1 == old_rank && arr[i].r2 == arr[i-1].r2)
{
old_rank = arr[i].r1;
arr[i].r1 = new_rank;
} 
else
{
old_rank = arr[i].r1;
arr[i].r1 = ++new_rank;
}
ind[arr[i].idx] = i;
}
for(int i=0;i<n;i++)
{
int next_idx = arr[i].idx + k/2;
if(next_idx >= n) {arr[i].r2 = -1; continue;}
arr[i].r2 = arr[ind[next_idx]].r1;
}
sort(arr, arr+n, cmp); 
}//nlognlogn
for(int i=0;i<n;i++) { suffixarr[i] = arr[i].idx; }
}

int  lcpfunc(int n)
{
int lcp = 0; int x,y,temp;
for(int i=1;i<n;i++)
{ temp = 0;
x = suffixarr[i];
y = suffixarr[i-1];
while(x<n && y<n && s[x]==s[y]) 
{
temp++;x++;y++;
}
if(temp>lcp) { lcp=temp; }
}//for  
return lcp;
}

int main()
{int t;cin>>t;
while(t--)
{ int temp;
cin>>temp>>s;  
sfxarr(s,s.size());
//for(int i=0;i<s.size();i++){ cout<<suffixarr[i]<<" ";}
cout<<lcpfunc(s.size())<<endl;
}
return 0;}

//qn 6
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
const int maxn = 1e5+10;
int n;
ll t,x,y,tp;
ll arr[maxn][2];
map<ll,ll> l,r,m;
set<ll> s;
vector<ll> v,idx;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);    
cin>>t;
while(t--)
{ l.clear();r.clear();s.clear();v.clear();m.clear();idx.clear();
tp=0;
cin>>n;
for(int i=0;i<n;i++){cin>>arr[i][0]>>arr[i][1];}
for(int i=0;i<n;i++)
{
s.insert(arr[i][0]);s.insert(arr[i][1]);
if(arr[i][0]==arr[i][1]){m[arr[i][0]]++;continue;}
l[arr[i][0]]++;  r[arr[i][1]]++;
}

v.pb(0);
for(auto it=s.begin();it!=s.end();it++)
{ 
 
if(m[*it]!=0){ 
  int x = v[v.size()-1];
  v.pb(x+l[*it]-r[*it]+m[*it]);
  v.push_back(x+l[*it]-r[*it]); }
else
{ v.pb(v[v.size()-1]+l[*it]-r[*it]);}


if(l[*it]>0 && r[*it]>0){++tp;}
else { tp=0; }  
if(tp>1){ if(m[*it]==0) { idx.pb(v.size()-2); }
          else idx.pb(v.size()-3);
        } 

}
for(int i=0;i<idx.size();i++){cout<<idx[i]<<" k ";} 
//v.erase(v.begin());
//v.erase(v.begin()+v.size()-1);
int min = 100100;//tp = touch point
for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;
for(int i=1;i<v.size()-1;i++)
{
if(v[i-1]>=v[i] && v[i]<=v[i+1] && v[i]<min){min=v[i];}
else if(binary_search(idx.begin(),idx.end(),i)){min = v[i];}
}

if(min == 100100){cout<<-1<<endl;}
else
{cout<<min<<endl;
}

}

return 0;}
