#include<bits/stdc++.h>
using namespace std;
 
using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
const int MOD = 998244353; 

// problem  link : https://codeforces.com/problemset/problem/1102/E

//Array b will always be non decreaing array, all overlapping ranges will have same values (range : i to j when a(i) = a(j))

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    map<int,int> last;

    for(int i=1; i<=n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }

    ll ans = 1;
    for(int i=1; i<=n; i++) {
        if(i > 1) {
            ans = (ans*2) % MOD;
        }

        //Extending till all overlapping subsequences are crossed
        int cur = last[a[i]];
        int ind = i+1;
        
        while(ind <= cur) {
            cur = max(cur, last[a[ind]]);
            ind++;
        }
        i = cur;
    }

    cout << ans << "\n";
}
