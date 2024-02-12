#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


int dp[MAXN]; // dp[i] -> if a player starts with i stones, will they win?
// 0 means no, 1 means yes

 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];


    dp[0] = 0;  // when 0 stones left ofc we loose
    for(int i=1; i<=k; i++) {
        for(int j=0; j<n; j++) {
            if(i - a[j] < 0) continue; 
            
            if(dp[i - a[j]] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(k - a[i] < 0) continue;

        if(dp[k - a[i]] == 0) {
            cout << "First";
            return 0;
        }
    }

    cout << "Second";
    return 0;
}
