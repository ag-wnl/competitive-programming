#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()


// problem link : https://codeforces.com/contest/888/problem/D

// 0 to k elements which we can arrange. Actually notice that we need to arrange
// these k elements so that nonce of them are at p(i) = i. So number of de-arrangement formula
// multiplied with number of ways to choose k elements from n -> nCk

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    ll n,k;
    cin >> n >> k;

    vector<ll> fact(5);
    fact[0] = 1;
    for(ll i=1; i<=4; i++) fact[i] = fact[i-1]*i;

    ll ans = 1;

    for(ll i=2; i<=k; i++) {
        // nCk 
        ll res = fact[i];
        ll den = 1;
        ll parity = -1;

        for(ll j=1; j<=i; j++) {
            den *= j;
            res += parity * (fact[i] / den);
            parity *= -1;
        }

        ll num = 1;
        for(int j=n; j>n-i; j--) {
            num *= j;
        }

        ll nCr = num / fact[i];
        ans += (res * nCr);
    }   

    cout << ans << "\n";
}
