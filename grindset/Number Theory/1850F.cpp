#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// problem link:  https://codeforces.com/problemset/problem/1850/F

// visit each multiple of hop length a[i], and increment the positions value
// do it only for range [1,n] and then in the end take max value in any position,
// as it will have maximum number of frogs going over and getting trapped

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> freq(2e5+1, 0);

    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i] <= n) {
            freq[a[i]]++;
        }
    }

    vector<int> res(n+1, 0);
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            res[j] += freq[i];
        }
    }

    int ans = 0;
    for(int i=0; i<=n; i++) {
        ans = max(ans, res[i]);
    }

    cout << ans << "\n";

}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
