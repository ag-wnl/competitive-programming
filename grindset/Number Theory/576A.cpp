#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e3+5;

//problem link : https://codeforces.com/problemset/problem/576/A

// notice for a prime p, if we dont ask for p^k, we cant distinguish 
// between p^k-1 and p^k for example. We cant distinguish between any p^k in range 1 to n
// they are enough to determine any number.

void solve(){
    int n;
    cin>>n;

    vector<int> isPrime(MAXN, 1);
    isPrime[0] = isPrime[1] = 0;

    for(int i=2; i<=MAXN; i++) {
        if(isPrime[i] == 1) {
            for(int j=i*i; j<=MAXN; j+=i) {
                isPrime[j] = 0;
            }
        } 
    }


    vector<int> res;
    for(int i=1; i<=n; i++) {
        if(isPrime[i] == 1) {
            int p = 1;
            while(p*i <= n) {
                p*=i;
                res.push_back(p);
            }
        }
    }

    cout << res.size() << "\n";
    for(auto it : res) cout << it << " ";
    cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
