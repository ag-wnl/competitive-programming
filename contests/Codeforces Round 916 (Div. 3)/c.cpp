#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    int ans = INT_MIN;
    int sum = 0;
    int maxb = 0;
    for(int i=0; i<n && i<k; i++) {
        sum += a[i];
        maxb = max(maxb, b[i]);
        ans = max(ans, sum + maxb * (k-1-i));
    }   

    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
