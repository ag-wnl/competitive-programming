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

//Better Runtime code almost O(1):
// As 16 = 10000, 15 = 01111 -> which has all powers of 2 added (from 0 to n-1) -> so answer = 2^(n+1) - 1 - 1(removing 2^0);
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
    int n;
    cin >> n;
    
    ll ans = 1LL<<(n+1);
    ans -= 2;
 
    cout << ans << "\n";
}
