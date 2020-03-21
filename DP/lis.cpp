//https://algorithmsandme.com/longest-increasing-subsequence-in-onlogn/
//https://leetcode.com/problems/longest-increasing-subsequence/solution/
//=====================================================================================================================================
//O(N*N) solution

int ans=1;
int dp[maxn];//dp[i] stores the length of lis containing a[i]
void lis()
{
dp[1] = 1;
for(int i=2;i<n;i++)
{ a[i] = INT_MIN;
  for(int j=i-1;j>0;j--)
  {
    if(a[j]<a[i])
    {
  dp[i] = max(a[i],dp[j]+1);
  if(dp[i]>ans) ans = dp[i];
    }
  }
}
  

//===================================================================================================================================  
//O(NlogN) solution
void bsrch(vector<int> v,int x)
{
  int l = 0;
  int r = v.size()-1;
  int mid;
  while(l<=r)
  {
    mid = (l+r)/2;
    if(x>v[mid])
    { l=mid+1; }
    else if(x<v[mid])
    {
      r=mid-1;
    }
    else 
    {
      break;
    }
  }
  if(v[mid]==x){return;}
  else
  {
    if(v[mid]<x){ v[mid+1] = x; }
    else 
    {
      v[mid]=x;
    }
  } 
}
int l = 0;
vector<int> v;
void fastlis()
{
v.push_back(a[0]);
l = 1;
for(int i=1;i<n;i++)
{
  if(a[i]>v[v.size()-1]) { v.push_back(a[i]); }
  else bsrch(v,a[i]);
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++) { cin>>a[i] ; }
  fastlis();
  cout<<v.size()<<endl;
  return 0;
}
/=====================================================================================================================================
