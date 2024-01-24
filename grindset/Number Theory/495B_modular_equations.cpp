#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// problem link : https://codeforces.com/problemset/problem/495/B

void solve(){
    int a,b;
    cin >> a >> b;

    if(a < b) {
        cout << "0\n";
        return;
    }

    if(a==b) {
        cout << "infinity\n";
        return;
    }

    int ans = 0;
    for(int i=1; i*i <= (a-b); i++) {
        if((a-b) % i == 0) {

            if(i > b) ans++;
            if((a-b) / i > b && (a-b) / i != i) ans++; //making sure no double counting

        } 
    }

    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
