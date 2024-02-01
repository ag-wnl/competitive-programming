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

// problem link : https://codeforces.com/problemset/problem/1236/B

// consider 1 type of item -> distributing it -> each box can either have it or not
// 2^m chances - 1 (as not possible that no box has an item of a type)
// now for n types of present (2^m  - 1) ^ n lmao and this is 1500 rated lol

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);


    ll n,m;
    cin >> n >> m;

    ll each = (fastpow(2, m, MOD) - 1 + MOD) % MOD;
    ll every = fastpow(each, n, MOD) % MOD;

    cout << every << "\n";
}
