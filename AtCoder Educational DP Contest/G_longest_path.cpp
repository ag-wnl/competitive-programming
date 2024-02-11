#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


int dfs(int node, vector<int> adj[], int length, vector<int> &dp) {
    
    if(adj[node].size() == 0) return length;

    if(dp[node] != -1) return length + dp[node];
    
    int len = length;
    for(auto it : adj[node]) {
        len = max(len, dfs(it, adj, length+1, dp));
    }

    dp[node] = len - length;
    return len; 
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int x, y; 
        cin >> x >> y;

        adj[x].push_back(y);
    }

    int ans = 0;
    vector<int> dp(n+1, -1);

    for(int i=1; i<=n; i++) {
        if(adj[i].size() != 0) {
            ans = max(ans, dfs(i, adj, 0, dp));
        }
    }

    cout << ans << "\n";
}
