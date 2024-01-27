#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
const int mod = 1000000007;

//problem link : https://codeforces.com/contest/57/problem/C

// either a(i) <= a(i+1) or a(i) >= a(i+1)

// to form an eqn : x1 + x2 + x3 + .... + xn = n;  We can see order already determined
// non increasing and non decreasing order acceptable : ways * 2;

// stars and bars : n items k boxes : C(n+k-1, n), here: n=n, k=n;

//No of beautiful arrays : Ways to choose elements * ways to arrange elements - double counting
// => C(2n-1, n) * 2 - n 
// n double countings as arrays with all elemnts same are still same when reversed.

// (2n-1)! / n! * (n-1)! => n+1*n+2*..*2n-1 / (n-1)!

long long pwr( long long a, int pw )
{
    long long ret = 1;
    long long x = a;
    for( int i = 1; i <= pw; i <<= 1 ) {
        if( i & pw ) ( ret *= x ) %= mod;
        ( x *= x ) %= mod;
    }
    return ret;
}
 
long long mdiv( long long a, long long b ) {
    return a * ( pwr( b, mod - 2 ) ) % mod;
}
 
long long cnk( long long n, long long k )
{
    long long ret = 1;
    for( int i = 0; i < k; i++ ) {
        ret = ( ret * ( long long )( n - i ) ) % mod;
        ret = ( mdiv( ret, i + 1 ) ) % mod;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n;
    cin >> n;

    cout <<  ( ( cnk( n + n - 1, n ) * 2 ) % mod + mod - n ) % mod << "\n";
}
