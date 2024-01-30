#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e4+5;
const int MOD = 1000000007;

//problem  link : https://codeforces.com/problemset/problem/152/C

// so we need to to find how many ways we can change 1st word w.r.t others
// Simple: i'th posn of each word mein jitne unique chars, count and multiple for i=0 to m;
// as these many distinct words can be formed, so check unique char cnt for each column and multiply them.

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<set<int>> a(m);

    for(int i=0; i<n; i++) {
    
        string s;
        cin >> s;

        for(int i=0; i<m; i++) {
            int x = s[i] - 'a';
            a[i].insert(x);
        }

    }

    ll ans = 1;
    for(int i=0; i<m; i++) {
        ans = (1LL * ans * a[i].size()) % MOD;
    }

    cout << ans << "\n";
}
