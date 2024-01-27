#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    ll ans = 0;
    ll p = 2;

    for(int i=1; i<=n; i++) {
        ans += p;
        p *= 2;
    } 

    cout << ans << "\n";
}
