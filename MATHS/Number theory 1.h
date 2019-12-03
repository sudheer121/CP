// INPUT a,b,c,m
// Output (a^b/c)%m
#include <iostream>
using namespace std;
#define ll long long int
ll x_1,y_1,temp,gcd;
ll modexpo(ll x,ll y,ll m)
{   
    x=x%m;
    if(y==0){return 1;}
    if(y%2==0){return modexpo(x*x,y/2,m); }
    else
    {
        return  (x*modexpo(x*x,y/2,m))%m; 
    }
}
ll extendedeuclid(ll A,ll B)
{   
    if( B==0) {x_1=1,y_1=0;gcd=A;return gcd;}
    else
    {extendedeuclid(B,A%B);
     temp=x_1; x_1=y_1; y_1=temp-(A/B)*y_1;
     return gcd;
    }
}
ll modmultinverse(ll A,ll M)
{ extendedeuclid(A,M);
  return (x_1%M+M)%M;  
}
int main() { ll a,b,c,m;cin>>a>>b>>c>>m;
	cout<<(modexpo(a,b,m)*modmultinverse(c,m)%m)%m;
}
