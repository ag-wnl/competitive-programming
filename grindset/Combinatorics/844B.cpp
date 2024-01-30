#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e3+5;


//problem link:  https://codeforces.com/problemset/problem/844/B

// just (2^n) - 1 as no empty subsequence allowes
// also subtract m*n in the end as we double count the number of single elements
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<int> ones(m); //row cnts
    vector<int> zeros(m); //row cnts

    ll ans = 0;

    for(int i=0; i<n; i++) {
        int zs = 0, os = 0;

        for(int j=0; j<m; j++) {
            int x;
            cin >> x;

            if(x == 0) {zs++; zeros[j]++;}
            if(x == 1) {os++; ones[j]++;} 
        }

        ans += (1LL<<zs) - 1;
        ans += (1LL<<os) - 1;
    }

    for(int i=0; i<m; i++) {
        if(ones[i] > 0) ans += (1LL<<ones[i]) - 1;
        if(zeros[i] > 0) ans += (1LL<<zeros[i]) - 1;
    }

    ans = ans - 1LL*(m*n);

    cout << ans << "\n";

}
