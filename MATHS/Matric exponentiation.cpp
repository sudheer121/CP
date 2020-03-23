// https://www.hackerearth.com/practice/notes/fast-matrix-exponentiation-2/
//https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
//https://www.geeksforgeeks.org/tribonacci-numbers/
#===================================================================================================================================
//Fibonacci in logn time
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
#====================================================================================================================
#tribonacci in logn time
 #include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int m = 1e9+7;
const int maxn = 1e5+10;
ll n,a[maxn];void multiply(ll T[3][3], ll M[3][3]) 
{ 
    ll a, b, c, d, e, f, g, h, i; 
    a = T[0][0] * M[0][0] +  
        T[0][1] * M[1][0] +  
        T[0][2] * M[2][0]; 
    b = T[0][0] * M[0][1] +  
        T[0][1] * M[1][1] +  
        T[0][2] * M[2][1]; 
    c = T[0][0] * M[0][2] +  
        T[0][1] * M[1][2] +  
        T[0][2] * M[2][2]; 
    d = T[1][0] * M[0][0] +  
        T[1][1] * M[1][0] +  
        T[1][2] * M[2][0]; 
    e = T[1][0] * M[0][1] +  
        T[1][1] * M[1][1] +  
        T[1][2] * M[2][1]; 
    f = T[1][0] * M[0][2] +  
        T[1][1] * M[1][2] +  
        T[1][2] * M[2][2]; 
    g = T[2][0] * M[0][0] +  
        T[2][1] * M[1][0] +  
        T[2][2] * M[2][0]; 
    h = T[2][0] * M[0][1] +  
        T[2][1] * M[1][1] +  
        T[2][2] * M[2][1]; 
    i = T[2][0] * M[0][2] +  
        T[2][1] * M[1][2] +  
        T[2][2] * M[2][2]; 
    T[0][0] = a%m; 
    T[0][1] = b%m; 
    T[0][2] = c%m; 
    T[1][0] = d%m; 
    T[1][1] = e%m; 
    T[1][2] = f%m; 
    T[2][0] = g%m; 
    T[2][1] = h%m; 
    T[2][2] = i%m; 
} 
  
// Recursive function to raise  
// the matrix T to the power n 
void power(ll T[3][3], ll n) 
{ 
    // base condition. 
    if (n == 0 || n == 1) 
        return; 
    ll M[3][3] = {{ 1, 1, 1 },  
                   { 1, 0, 0 },  
                   { 0, 1, 0 }}; 
  
    // recursively call to 
    // square the matrix 
    power(T, n / 2); 
  
    // calculating square  
    // of the matrix T 
    multiply(T, T); 
  
    // if n is odd multiply  
    // it one time with M 
    if (n % 2) 
        multiply(T, M); 
} 
ll tribonacci(ll n) 
{ 
    ll T[3][3] = {{ 1, 1, 1 },  
                   { 1, 0, 0 }, 
                   { 0, 1, 0 }}; 
  
    // base condition 
    if (n == 0 || n == 1) 
        return 0; 
    else
        power(T, n - 2); 
  
    // T[0][0] contains the  
    // tribonacci number so 
    // return it 
    return T[0][0]; 
} 

int main()
{ 
  cin>>n;
  for(int i=1;i<=n;i++) { cin>>a[i]; }
  for(int i=1;i<=n;i++) { cout<<tribonacci(a[i]+3)%m<<endl; }
  

  return 0;
}
