#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 250005;


// problem link : https://codeforces.com/problemset/problem/1284/C

// just think about a segment [l,r] -> if [l,r] is framed segment, all no.s [min, max] where min and max are in segment i = l to r are exactly in this segment
// and we know order of numbers inside it and outside it dont matter with each other as they are two distinct events
// so (r-l+1)! = len! arrangement in [l,r] and (n-len+1)! arrangement for no.s not in framed segment
// so len! * (n-len+1)! ways for for length -> len segment of [l,r]
//  also by observation we can see for length len, there are (n-len+1) pairs of l and r
// so just go i = 1 to i = n; (where i = len) and calc for each and keep adding

// nice editorial too

ll fact[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);


    int n,m;
    cin >> n >> m;

    fact[0] = 1;
    for(int i=1; i<=n; i++) fact[i] = fact[i-1] * i % m;

    ll ans = 0;
    for(int i=1; i<=n; i++) {
        ans += (n-i+1) * (fact[i] * fact[n-i+1] % m);
        ans %= m;
    }

    cout << ans;
}
