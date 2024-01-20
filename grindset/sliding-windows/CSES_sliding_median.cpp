#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
//POLICY BASED DATA STRUCTURE: ordered_set

//problem: https://cses.fi/problemset/task/1076
void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    ordered_set s;

    for(int i=0; i<k; i++) {
        s.insert(make_pair(a[i], i));
    }

    for(int i=k-1; i<n; i++) {
        int pos = s.find_by_order((k-1) / 2) -> first;
        if(i != n-1) {
            s.erase(s.lower_bound({a[i-k+1], 0}));
            s.insert({a[i+1], i});
        }
        cout << pos << " ";
    }

}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while(T--) solve();
}
