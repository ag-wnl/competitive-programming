#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://cses.fi/problemset/task/1085/

void solve(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);

    for(ll i=0; i<n; i++) cin >> a[i];

    auto meow = [&] (ll m, ll k) {
        ll sum = 0;
        ll cnt = 1;

        for(ll i=0; i<n; i++) {
            if(a[i] > m) return false;

            if(sum + a[i] <= m) sum += a[i];
            else  {
                sum = a[i];
                cnt++;
            }
        }
        return cnt <= k;
    };

    ll l = 1, r = 1e15;

    while(r-l > 1) {
        ll m = l + (r-l)/2;
        if(meow(m,k) == true) {
            r = m;
        } else {
            l = m;
        }
    }

    cout  << r << "\n";

}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
