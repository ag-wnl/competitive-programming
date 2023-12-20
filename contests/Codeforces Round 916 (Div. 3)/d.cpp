#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(n);
    vector<pair<int,int>> c(n);

    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        b[i] = {x, i};
    }
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        c[i] = {x, i};
    }

    sort(all(a));
    sort(all(b));
    sort(all(c));

    reverse(all(a));
    reverse(all(b));
    reverse(all(c));

    int ans = INT_MIN;
    for(int i=0; i<min(n,5); i++) {
        for(int j=0; j<min(n,5); j++) {
            for(int k=0; k<min(n,5); k++) {
                if(a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second) {
                    ans = max(ans, a[i].first + b[j].first + c[k].first);
                }
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
