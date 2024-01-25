#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


// problem link : https://codeforces.com/problemset/problem/1822/G1
// Literally optimized bruteforce lol, major takeaway: dont always think for complex
// solutions, i was thinking about checking prime factors (possible solution) but will
// be hard to implement

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    map<int,int> mp;

    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(all(a));

    ll ans = 0;
    for(int i=0; i<n; i+=mp[a[i]]) {
        ans += 1LL * mp[a[i]] * (mp[a[i]] - 1) * (mp[a[i]] - 2);

        for(int b = 2; a[i] * b * b <= a[n-1]; b++) {
            if(mp.find(a[i] * b) == mp.end() || mp.find(a[i]*b*b) == mp.end()) {
                continue;
            } else {
                ans += 1LL * mp[a[i]] * mp[a[i]*b] * mp[a[i]*b*b];
            }
        }
    }
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
