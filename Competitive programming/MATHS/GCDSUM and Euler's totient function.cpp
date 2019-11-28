#include<bits/stdc++.h>
using namespace std;
#define max 500010
#define ll long long 
/*
https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
https://www.geeksforgeeks.org/least-prime-factor-of-numbers-till-n/
https://www.geeksforgeeks.org/eulers-totient-function/ 
**https://www.quora.com/How-can-I-solve-the-problem-GCD-Extreme-GCDEX-on-SPOJ
***https://www.geeksforgeeks.org/summation-gcd-pairs-n/
***https://codeforces.com/blog/entry/7308
*/
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

//Including duplicate factors
vector<ll> primefactors(ll x)// gives prime factorization of each query in O(log2(n)) time ,  better than usual  sqrt(n)
{                         //first call lpfactor function from main to fill lpf[] array
    vector<ll> v;         //storing factors in vector v everytime
    v.clear();    
    int cnt = 0;
    while(x!=1)
    {
    cnt++;
    v.push_back(lpf[x]); 
    x = x/lpf[x]; 
    //for x=315  v= {3,3,5,7};
    }
    return v;
} //O(log2(n)) for each query

//Excluding duplicate factors ( for use in Euler's totient function )
set<ll> pfactors(ll x)
{                         
    set<ll> s;         
    v.clear();    
    int cnt = 0;
    while(x!=1)
    {
    cnt++;
    s.insert(lpf[x]); 
    x = x/lpf[x]; 
    //for x=315  v= {3,5,7};
    }
    return s;
} //O(log2(n)) for each query


ll phi(ll n)//gives the number of pairs (i,n) with gcd 1, 1<=i<=n
{
ll result = n;
for(int p=2;p*p<n;p++)
{
    if(n%p==0)
    {
        n=n/p;
        result = result - result/p ;
    }
}
    if (n > 1) 
        result -= result / n; 
    return result;
}

int main()
{
    lpfactor(500);
    primefactors(315);
    for(int i=0;i<v.size();i++) { cout<<v[i]; }
}

