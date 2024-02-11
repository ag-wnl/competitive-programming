#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

double dp[3000][3000]; //dp[index][no. of heads] = probab

 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int  n;
    cin >> n;

    vector<double> p(n);
    for(int i=0; i<n; i++) cin >> p[i];

    dp[0][0] = (1 - p[0]);
    dp[0][1] = p[0];
    
    for(int i=1; i<n; i++) {
        for(int heads=0; heads<3000; heads++) {
            //tails on current
            dp[i][heads] += (1-p[i]) * dp[i-1][heads];

            //heads on current
            if(heads > 0) dp[i][heads] += p[i] * dp[i-1][heads-1];
        }
    }

    double ans = 0;

    // going from n/2 + 1 heads as heads count will be more than tails always
    for(int i=n/2+1; i<3000; i++) {
        ans += dp[n-1][i];
    }

    cout << setprecision(16) << ans;    
}
