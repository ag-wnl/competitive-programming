#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
const int MOD = 1e9 + 7;
 
//fast power -> exponentiating by squaring
// (n^x) % m
long long fastpow(long long n, long long x, long long m){
  long long ret = 1;
  while(x){
    if(x&1)
     (ret*=n)%=m;
    x>>=1;
    (n*=n)%=m;
  }
  return ret;
}

//problem link : https://codeforces.com/problemset/problem/584/B

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n;
    cin >> n;

    ll tot = fastpow(1LL * 3, 1LL* 3 * n, MOD);
    ll bad = fastpow(1LL * 7, n, MOD);
    ll ans = ((tot % MOD - bad % MOD) + MOD ) % MOD;
    cout << ans;
}
