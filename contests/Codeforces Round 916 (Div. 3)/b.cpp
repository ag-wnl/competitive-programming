#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);

    int cur = n;
    int te = 1;
    for(int i=n-1; i>=0; i--) {
        if(k>0) {
            ans[i] = n--;
            k--;
        } else {
            ans[i] = te++;
        }
    }

    for(auto it : ans) cout << it << " ";
    cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
