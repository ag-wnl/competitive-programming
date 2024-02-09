#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

//Abdul Bari soln : https://www.youtube.com/watch?v=nLmhmB6NzcM

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll n,W;
    cin >> n >> W;

    vector<ll> w(n+1), v(n+1);
    for(int i=1; i<=n; i++) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(n+1, vector<ll>(W+1));

    for(ll i=0; i<=W; i++) dp[0][i] = 0;
    for(ll i=0; i<=n; i++) dp[i][0] = 0;

    for(ll i=1; i<=n; i++) {
        for(ll j = 1; j<=W; j++) {
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    } 

    cout << dp[n][W] << "\n";
}
