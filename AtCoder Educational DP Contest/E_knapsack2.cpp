#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5;

//dp[items][value] = minimum weight required to achieve that value
vector<vector<ll>> dp(101, vector<ll>(MAXN+1, 1e18));


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll n,W;
    cin >> n >> W;

    vector<ll> w(n), v(n);
    for(ll i=0; i<n; i++) cin >> w[i] >> v[i];

    dp[0][0] = 0;
    dp[0][v[0]] = w[0];

    for(ll i=1; i<n; i++) {
        dp[i][0] = 0;

        for(ll j = 1; j<=MAXN; j++) {
            dp[i][j] = dp[i-1][j];   //not pick

            if(j - v[i] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]); //pick
            }
        }
    } 


    ll ans;
    for(ll value=MAXN; value>=0; value--) if(dp[n-1][value] <= W) {ans = value; break;}

    cout << ans << "\n";
}
