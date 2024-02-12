#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 3005;

ll dp[MAXN][MAXN]; //dp[l][r] = scores currently , l and r are left and right pointers

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];


    // starting from short interval to long interval
    for(int l=n-1; l>=0; l--) {
        for(int r=l; r<n; r++) {

            // when we take left element, opponent can choose l+1, r segment and when we choose right element, opponent can choose l to r-1 elements 
            // -> in both cases we subtract the score of the opponent

            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }

    cout << dp[0][n-1] << "\n";
}
