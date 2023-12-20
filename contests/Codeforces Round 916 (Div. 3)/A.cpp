#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<int, int> mp;
    for(int i=0; i<s.size(); i++) {
        mp[s[i] - 'A' + 1] += 1;
    }

    int ans = 0;
    for(auto it : mp) {
        if(it.second >= it.first) {
            ans++;
        }
    }

    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
