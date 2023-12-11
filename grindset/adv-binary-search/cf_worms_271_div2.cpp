#include<bits/stdc++.h>
using namespace std;

//author: @ag_wnl

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://codeforces.com/contest/474/problem/B

void solve(){
    int n;
    cin >> n;
    vector<int> pref(n+1, 0);
    vector<int> a(n+1);

    for(int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    int m; cin >> m;
    for(int i=0; i<m; i++) {
        int q; cin >> q;

        int ans = lower_bound(pref.begin(), pref.end(), q) - pref.begin();
        cout << ans << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
