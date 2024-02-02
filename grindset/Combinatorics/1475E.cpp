#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e3+5;
const int mod = 1e9 + 7;

// problem link : https://codeforces.com/problemset/problem/1475/E

// sort array, in the top k elements to have more number of ways
// we check if frequency of any element in top k element (let it be a) differs from
// its frequency of occurance in the entire array (let it be b)
// so answe is bCa (from b choose a)

long long pwr( long long a, int pw )
{
    long long ret = 1;
    long long x = a;
    for( int i = 1; i <= pw; i <<= 1 ) {
        if( i & pw ) ( ret *= x ) %= mod;
        ( x *= x ) %= mod;
    }
    return ret;
}
 
long long mdiv( long long a, long long b ) {
    return a * ( pwr( b, mod - 2 ) ) % mod;
}
 
long long cnk( long long n, long long k )
{
    long long ret = 1;
    for( int i = 0; i < k; i++ ) {
        ret = ( ret * ( long long )( n - i ) ) % mod;
        ret = ( mdiv( ret, i + 1 ) ) % mod;
    }
    return ret;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int,int> freq;

    for(int i=0; i<n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }


    sort(all(a));
    
    int maxi = 0;
    vector<int> res;
    map<int,int> mp;

    for(int i=n-1; i>n-k-1; i--) {
        maxi += a[i];
        res.push_back(a[i]);
        mp[a[i]]++;
    }

    int need = 0;
    int cnt = 0;
    reverse(all(res));
    
    for(auto it : res) {
        if(mp[it] <= freq[it]) {
            need = mp[it];
            cnt = freq[it];
            break;    
        }
    }

    // need if for top k dif number of times:
    ll ans = cnk(cnt, need) % mod; 
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
