//https://codeforces.com/problemset/problem/1623/C

#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
    int n;
    cin >> n;

    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];

    auto meow = [&](int x) {
        vector<int> a = h;

        for(int i=n-1; i>=0; i--) {
            if(a[i] < x) {
                return false;
            }

            int d = (a[i] - x)/3;
            d = min(d, h[i]/3);

            a[i] -= 3*d;
            if(i>=2) {
                a[i-1] += d;
                a[i-2] += 2*d;
            }
        }
        return true;
    };

    int l = 0, r = 1e9;
    while(r-l > 1) {
        int m = l + (r-l)/2;

        if(meow(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
