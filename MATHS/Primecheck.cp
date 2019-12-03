//check if multiple numbers are prime or not
#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
vector<int> a;
void func()
{
for(ll i=2;i<8000;i++) 
{
if(a[i]==0){continue;}
if(i*i>8000){break;}
for(int j=i*i;j<8000;j+=i){ a[j]=0; }
}
for(int i=0;i<a.size();i++)
{
    if(a[i]==0){a.erase(a.begin()+i);i--;}
}
}
int isprime(int x)
{
    if(binary_search(a.begin(),a.end(),x)){return 1;}
    else{ return 0;}
}
int main()
{for(int i=0;i<8000;i++){a.push_back(i);}
func();
    cout<<isprime(8);
}
