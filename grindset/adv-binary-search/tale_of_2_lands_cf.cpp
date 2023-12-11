#include<bits/stdc++.h>
using namespace std;

//author: @ag_wnl

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://codeforces.com/problemset/problem/1166/C

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a[i] = abs(x);
    }

    sort(all(a));
    ll ans = 0;
    for (int i=0; i<n; i++) {
        int j = upper_bound(a.begin(), a.end(), a[i] * 2) - a.begin();
        ans += max(0, j - i - 1);
    }
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
