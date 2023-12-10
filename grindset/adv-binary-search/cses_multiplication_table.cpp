#include<bits/stdc++.h>
using namespace std;

//author: @ag_wnl

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
    ll n;
    cin >> n;

    //as we need to find median, and n*n numbers in table in total, so median ofc gonna have
    // n*n+1/2 no.s including it and behind it. So find smallest such number which return true for this

    ll l = 1, r = n*n;
    ll tar = (n*n + 1) / 2;

    auto meow = [&](ll m) {
        ll cnt = 0;
        for(ll row=1; row<=n; row++) cnt += min(n, (m/row));
        return cnt >= tar;
    };

    while(r-l > 1) {
        ll m  = l + (r-l) / 2;
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
