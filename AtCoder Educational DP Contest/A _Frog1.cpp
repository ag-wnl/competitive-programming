#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];


    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int op1 = dp[i-1] + abs(h[i] - h[i-1]);
        int op2 = 1e5;
        
        if(i>1) {
            op2 = dp[i-2] + abs(h[i] - h[i-2]);
        }

        dp[i]= min(op1, op2);
    }

    cout << dp[n-1] << "\n";
}
