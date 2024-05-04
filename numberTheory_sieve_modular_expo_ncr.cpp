#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int m = 1e9+7;
const int INF = LONG_MAX >> 1;

vector<int> factorial(100);


vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    return prime;
}

void primeFactorization(int n){
    vector<int>SmallestPrimeFactor(n+1,0);
    for(int i=2;i<=n;i++){
        if(SmallestPrimeFactor[i]==0){
            for(int j=i;j<=n;j+=i){
                if(SmallestPrimeFactor[j]==0){
                    SmallestPrimeFactor[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<SmallestPrimeFactor[n]<<" ";
        n/=SmallestPrimeFactor[n];
    }
}
int modular_adddition(int a, int b, int m){
    return ((a%m)+(b%m))%m;
}

int modular_subtraction(int a, int b, int m){
    return ((a%m)-(b%m)+m)%m;
}

int modular_multiplication(int a, int b, int m){
    return ((a%m)*(b%m))%m;
}

int modular_exponentiation(int a, int b , int m){
    if (b==0) return 1;
    int res=modular_exponentiation(a,b/2,m);//for even number as power
    res=modular_multiplication(res,res,m);//for even number as power
    if(b%2) res=modular_multiplication(res,a,m);//if odd number as power
    return res;
}

int modular_inverse(int a, int m){ 
    return modular_exponentiation(a,m-2,m);//derived from fermert's little theorem
}

int modular_division(int a, int b, int m){
     return modular_multiplication(a,modular_inverse(b,m),m);
}

int ncr(int n, int r,int m){
    if(r<0 or r>n) return 0;
    return modular_division(factorial[n],modular_multiplication(factorial[r],factorial[n-r],m),m);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    factorial[0]=1;
    for(int i=1;i<100;i++){
         factorial[i]=modular_multiplication(factorial[i-1],i,m);
    }

    cout<<ncr(5,2,m)<<endl;
    cout<<modular_exponentiation(2,5,m)<<endl;
    cout<<modular_inverse(2,m)<<endl;
    cout<<modular_division(5,2,m)<<endl;
    cout<<modular_multiplication(5,2,m)<<endl;
    cout<<modular_subtraction(5,2,m)<<endl;
    cout<<modular_adddition(5,2,m)<<endl;
    primeFactorization(100);
    cout<<endl;


}
