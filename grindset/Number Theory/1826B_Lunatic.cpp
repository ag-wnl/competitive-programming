#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

//problem: https://codeforces.com/contest/1826/problem/B

// a[i] = a[n-i-1] in pallindrome -> subtract both side by min(a[i],a[n-i-1]);
// then we know any x has to be divisible by one of them, as the other 
// is always 0, so finally we take gcd to get largest such value of x

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n/2; i++) {
        if(a[i] > a[n - 1 - i]) {
            a[i] -= a[n - 1 - i];
            a[n - 1 - i] = 0;
        } else {
            a[n - 1 - i] -= a[i];
            a[i] = 0;
        }
    }

    int g = 0;
    for(int i=0; i<n; i++) {
        if(n%2 != 0 && i == (n+1)/2 - 1) {
            continue;
        }
        g = __gcd(g, a[i]);
    }

    cout << g << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
