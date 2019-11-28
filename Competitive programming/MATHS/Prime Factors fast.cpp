#include<bits/stdc++.h>
using namespace std;
#define max 500010
#define ll long long 

ll lpf[max] = {0};
void lpfactor(ll n)//least prime factors of all till n 
{   //using Sieve we are storing the corresponding lpf for every composite encountered 
    lpf[1] = 1;
    for(int i=2;i<=n;i++)
    {
        if( lpf[i]==0 )// means i is prime
        {
            lpf[i]=i; 
            
            for(int j=i*i;j<=n;j+=i)
            {
                if( lpf[j]== 0) { lpf[j] = i ;} //lpf[prime multiples] = prime 
            }
            
        }
    }
}   // O(n*log(log(n)))

vector<ll> v;
void primefactors(ll x)// gives prime factorization of each query in O(log2(n)) time ,  better than usual  sqrt(n)
{   //storing factors in vector v everytime
    v.clear();
   //first call lpfactor function from main to fill lpf[] array
    
    while(x!=1)
    {
    v.push_back(lpf[x]); 
    x = x/lpf[x]; 
    //for x=315  v= {3,3,5,7};
    }
} //O(log2(n)) for each query

int main()
{
    lpfactor(500);
    primefactors(315);
    for(int i=0;i<v.size();i++) { cout<<v[i]; }
}

