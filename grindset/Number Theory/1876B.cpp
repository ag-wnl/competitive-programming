#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
const int MOD = 998244353;

// problem link : https://codeforces.com/contest/1876/problem/B
// Take maximum values for an element, sort it order does not matter for max scores:
// Each element i in max array occur as maximum for exactly 2^(i-1) subsequences (as everything to the left is smaller than ai)

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++) {
        for(int j=2*i; j<=n; j+=i) {
            a[i] = max(a[i], a[j]);
        }
    }

    sort(a.begin()+1, a.end());

    ll ans = 0;
    int cnt = 1;
    for(int i=1; i<=n; i++) {
        ans = (ans + 1LL * a[i] * cnt) % MOD;
        cnt = (cnt*2) % MOD;
    }

    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
