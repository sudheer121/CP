//Extended EUCLID'S algorithm gives gcd in terms of original numbers
#include<bits/stdc++.h>
using namespace std;
int x_1,y_1,gcd,temp;//x_1 is x1,y_1 is y_1
int GCD(int A, int B) {
    
    if(B==0)
        {   x_1=1;y_1=0;gcd=A;
            return A;
        }
    else
        {   GCD(B, A % B);
            temp=x_1;
            x_1=y_1; y_1=temp-(A/B)*y_1;
            return 0;
        }
}
int main()
{   int x,y;
    cin>>x>>y;
    GCD(x,y);
    cout<<gcd<<"  "<<x_1<<" "<<y_1<<endl;
    return 0;
}
