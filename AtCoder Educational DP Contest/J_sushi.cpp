#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 301;

double dp[MAXN][MAXN][MAXN]; // dp[no. of 3][no. of 2][no. of 1] , no. here is sushis on plate
// no. of plates with 0 sushi are total - (no. of 2 + no. of 2 + no. of 1)
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt[4] = {0};

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    dp[0][0][0] = 0; // All all plates empty

    // i-> 3 vale, j -> 2 vale, k-> 1 vale
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            for(int k=0; k<=n; k++) {

                int zeros = n - i - j - k;
                if(zeros == n || i+j+k > n) continue;

                double cur = 1; // We making a move
                if(i > 0) cur += (1.0 * i / n) * dp[i-1][j+1][k];  // picking a plate with 3 sushi
                if(j > 0) cur += (1.0 * j / n) * dp[i][j-1][k+1];  // picking a plate with 2 sushi
                if(k > 0) cur += (1.0 * k / n) * dp[i][j][k-1];    // picking a plate with 1 sushi
                dp[i][j][k] = cur / (1 - 1.0 * zeros / n);         // also accounting for picking a plate with 0 sushi
            }
        }
    }

    cout << setprecision(10) << dp[cnt[3]][cnt[2]][cnt[1]] << "\n";
}
