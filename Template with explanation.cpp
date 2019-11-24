#include<bits/stdc++.h>
#define all(c) c.begin(),c.end()
#define ll long long int
#define em emplace_back
#define pb push_back
#define mt make_tuple
#define mp make_pair

using namespace std;

typedef vector<ll>vi;
typedef vector<vi>vii;
typedef pair<ll,ll>pi;
typedef tuple<ll,ll,ll>ti;

using namespace std;

const int N = 1e5 + 100;    //note this ,declaring int n = 100100

vii Node(N,vi(27,-1));      // Vector of vectors
//In vii ->   N rows .Each row is vector of type vi. vi has size 27
//In vi  ->  27 rows .Each row is initialized to -1
// vector<int> vect(n, 10); ----------------> intitialize vect with size n and each value 10.

vii Node_value(N,vi(vector<int> vect(n, 10); 27,-1));
