#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int> (3)), dp(n, vector<int> (3));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> a[i][j];
        }
    } 

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];


    for(int day=1; day<n; day++) {
        dp[day][0] = a[day][0] + max(dp[day-1][1], dp[day-1][2]);
        dp[day][1] = a[day][1] + max(dp[day-1][0], dp[day-1][2]);
        dp[day][2] = a[day][2] + max(dp[day-1][0], dp[day-1][1]);
    }

    int ans = 0;
    for(int i=0; i<3; i++) {
        ans = max(ans, dp[n-1][i]);
    }

    cout << ans << "\n";
}
