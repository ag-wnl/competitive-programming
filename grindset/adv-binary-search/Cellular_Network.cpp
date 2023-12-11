#include<bits/stdc++.h>
using namespace std;

//author: @ag_wnl

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://codeforces.com/problemset/problem/702/C

void solve(){
    ll n,m;
    cin >> n >> m;
    std::vector<ll> a(n);
    std::vector<ll> b(m);

    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<m; i++) cin >> b[i];

    ll mini = 0;
    
    for(ll i=0; i<n; i++) {
        ll ind = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        
        ll near1 = abs(b[ind]-a[i]);
        ll near2 = INT_MAX;
        if(ind > 0) {
            near2 = abs(a[i]-b[ind-1]);
        }
        
        mini = max(mini, min(near1, near2));
    }

    cout << mini << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
