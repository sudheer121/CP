//https://algorithmsandme.com/longest-increasing-subsequence-in-onlogn/
//https://leetcode.com/problems/longest-increasing-subsequence/solution/
//https://repl.it/@SudheerTripathi/longestincrsubnndp
//=====================================================================================================================================
//O(N*N) solution(Dynamic Programming)

//dp[i] gives lis ending at index i. 
int lis()
{ 
  int globalans = 0; 
  for(int i=0; i<n; i++)
  { 
    dp[i] = 1; 
    for(int j=0; j<i; j++)
    {
      if(a[j] < a[i])
      {
        dp[i] = max(dp[i],dp[j]+1); 
      }
    }
    globalans = max(globalans,dp[i]); 
  }
  return globalans; 
}

//===================================================================================================================================  
//O(NlogN) solution
//let's have another array v[], v is pretty special
//v[i] means: the minimum value of the last element of the longest increasing sequence whose length is i.
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
