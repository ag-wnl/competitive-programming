#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

//problem : https://codeforces.com/contest/876/problem/B

// any number X = q * d + r (quotient x divisor + remainder)
// Xi - Xj = (Qi * m + Ri) - (Qj * m + Rj)  (divisor in this problem is m)
// Xi - Xj = (Qi-Qj) * m + (Ri - Rj), so for Xi-Xj to be divisible Ri - Rj to be 0
// so find k such numbers who all have the same remainder

void solve(){
    int n,k,m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[a[i] % m]++;
    }

    for(auto it : mp) {
        if(it.second >= k) {
            cout << "Yes\n";

            int r = it.first;
            int cnt = 0;
            
            for(int i=0; i<n; i++) {
                if(a[i] % m == r) {
                    cout << a[i] << " ";
                    cnt++;
                }
                if(cnt == k) {
                    cout << "\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
