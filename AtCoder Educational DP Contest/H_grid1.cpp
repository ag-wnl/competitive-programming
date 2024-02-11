#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
const int mod = 1e9+7;

int dp[1000][1000];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> a(h, vector<char> (w));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w;j ++) {
            cin >> a[i][j];
        }
    }

    dp[0][0] = 1;   

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(a[i][j] == '#') {
                continue;
            } 
            
            if(i && a[i-1][j] != '#') dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;

            if(j && a[i][j-1] != '#') dp[i][j] = (dp[i][j] +  dp[i][j-1]) % mod; 

        }
    }

    cout << dp[h-1][w-1] << "\n";

}
