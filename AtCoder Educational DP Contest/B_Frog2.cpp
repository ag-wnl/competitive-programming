#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<ll> h(n);
    for(ll i=0; i<n; i++) cin >> h[i];


    vector<ll> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(ll i=1; i<n; i++) {
        for(ll j=i-1; j>=0 && (i-j) <= k; j--) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n-1] << "\n";
}
