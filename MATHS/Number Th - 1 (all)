// NAIVE POWER.....................................................................................................................
int recursivePower(int x,int n)
{
    if(n==0)
        return 1;
    return x*recursivePower(x,n-1);
}

int iterativePower(int x,int n)
{
    int result=1;
    while(n>0)
    {
        result=result*x;
        n--;
    }
    return result;
}
// BINARY EXPONENTIATION.............................................................................................................
int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}

int binaryExponentiation(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=result * x;
        x=x*x;
        n=n/2;
    }
    return result;
}
// MODULAR EXPONENTIATION ......................................................................................................
int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}

int modularExponentiation(int x,int n,int M)
{
    int result=1;
    while(n>0)
    {
        if(power % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

//NAIVE GCD .......................................................................................................................
int GCD(int A, int B) {
    int m = min(A, B), gcd;
    for(int i = m; i > 0; --i)
        if(A % i == 0 && B % i == 0) {
            gcd = i;
            return gcd;
        }
}

//EUCLID'S GCD .......................................................................................................................
int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}

//EXTENDED EUCLIDS ALGO .......................................................................................................................
#include < iostream >

int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main( ) {
extendedEuclid(16, 10);
cout << ”The GCD of 16 and 10 is ” << d << endl;
cout << ”Coefficients x and y are ”<< x <<  “and  “ << y << endl;
return 0;   
}
//NAIVE  MODULAR MULTILICATIVE INVERSE .......................................................................................................................

int modInverse(int A,int M)
{
    A=A%M;
    for(int B=1;B<M;B++)
        if((A*B)%M)==1)
            return B;
}
//MODULAR MULTILICATIVE INVERSE USING EXTENDED EUCLIDS ALGO.......................................................................................................................
int d,x,y;
int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
Time complexity:
O(log(max(A,M)))

//MODULAR MULTILICATIVE INVERSE( using fermat's littlr theorem)...............................................................................................................
// applies only when m is prime
int modInverse(int A,int M)
{
    return modularExponentiation(A,M-2,M);
}




