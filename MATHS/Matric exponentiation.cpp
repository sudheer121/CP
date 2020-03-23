// https://www.hackerearth.com/practice/notes/fast-matrix-exponentiation-2/
 #include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int m = 1e9+7;
const int maxn = 1e5+10;
ll n,a[maxn];
ll F[2][2],M[2][2];

void multiply(ll A[2][2],ll B[2][2])
{ // A = A*B
  ll x =  (A[0][0]*B[0][0])%m +(A[0][1]*B[1][0])%m; 
  ll y =  (A[0][0]*B[0][1])%m + (A[0][1]*B[1][1])%m; 
  ll z =  (A[1][0]*B[0][0])%m + (A[1][1]*B[1][0])%m ; 
  ll w =  (A[1][0]*B[0][1])%m + (A[1][1]*B[1][1])%m; 
  
  A[0][0] = x%m; 
  A[0][1] = y%m; 
  A[1][0] = z%m; 
  A[1][1] = w%m; 
}
void power(ll F[2][2], ll n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  ll M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 

int fib(ll n) 
{ //cout<<n<<" ";
  ll F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 

int main()
{ 
  cin>>n;
  for(int i=1;i<=n;i++) { cin>>a[i]; }
  for(int i=1;i<=n;i++) { cout<<fib(a[i]+2)%m<<endl; }
  

  return 0;
}
