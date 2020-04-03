#include<bits/stdc++.h>
using namespace std;
const int maxy = 31621;
vector<int> pstore; //prime store
void superprime() //stores prime numbers in pstore
{
  int a[maxy];
  for(int i=1;i<maxy;i++)
  {
  a[i] = i;
  }
  for(int i=2;i<maxy;i++)
  { if(a[i]==i)
    { 
    pstore.push_back(i);
    for(long long j=i*i;j<=maxy;j+=i)
    {
      if(a[j]==j) { a[j]=i; }
    }
    }
  }
}
int pf(int x)//prime factorization
{
int cnt=0;
for(int i=0;i<pstore.size();i++)
{ if(pstore[i]>x){ break; }
  if(x%pstore[i]==0)
  {
    while(x%pstore[i]==0)
    {
     cnt++;
     x = x/pstore[i];
    }
  }
}
return cnt;
}

int main()
{ 

  return 0;
}
