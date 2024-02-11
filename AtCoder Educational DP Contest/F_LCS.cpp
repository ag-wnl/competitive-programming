#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5 + 5;

int dp[3000][3000];
int pick[3000][3000];

// pick not pick at every char of strings, we also made pick to help us backtrack and reconstruct the string
// pick : 2 means we came from i--, j--; pick : 1 means came from i, j-1, pick : 0 means came from i-1, j

// we backtrack our pick array to check where we came from -> its in reverse order so we reverse it in the end

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
       
    string s,t;
    cin >> s;
    cin >> t;

    int n = s.size(), m = t.size();

    dp[0][0] = 0;
    if(s[0] == t[0]) {
        dp[0][0] = 1;
        pick[0][0] = 2;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i > 0) {
                dp[i][j] = dp[i-1][j]; 
                pick[i][j] = 0;
            }
            
            if(j > 0 && dp[i][j] < dp[i][j-1]) {
                dp[i][j] = dp[i][j-1];
                pick[i][j] = 1;
            }
        
            if(s[i] == t[j]) {
                int ans = 1;
                if(i>0 && j>0) {
                    ans =  1 + dp[i-1][j-1]; 
                }

                if(ans > dp[i][j]) {
                    dp[i][j] = ans;
                    pick[i][j] = 2;
                }
            }
        }
    }

    int i = n-1, j = m-1;
    string res;
    while(i>=0 && j>=0) {
        if(pick[i][j] == 0) {
            i--;
        }
        else if(pick[i][j] == 1){
             j--;
        }
        else{
            res.push_back(s[i]); 
            i--; 
            j--;
        }
    }

    reverse(all(res));
    cout << res;
}
