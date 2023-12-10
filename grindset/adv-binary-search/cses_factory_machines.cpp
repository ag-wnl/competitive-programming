#include<bits/stdc++.h>
using namespace std;

//author: @ag_wnl

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://cses.fi/problemset/task/1620/

void solve(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);

    for(int i=0; i<n; i++) cin >> a[i];

    //function:
    auto meow = [&](long long m) {
        ll prods = 0;
        for(int i=0; i<n; i++) {
            prods += (m/a[i]);
            if(prods >= t) return true;
        }
        return false;
    };

    ll l=0, r = 1e18;
    while(r-l > 1) {
        ll m = l + (r-l)/2;
        if(meow(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
