#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://codeforces.com/problemset/problem/1810/C

void solve(){
	int n,c,d;
	cin >> n >> c >> d;

	set<int> st;
	ll ans = 1e18;
	ll cost = 0;

	for(int i=1; i<=n; i++) {
		int x; cin >> x;
		st.insert(x);
	}

	int rem = n - st.size();
	cost = 1LL*rem*c;

	vector<int> a(MAXN);
	int len = 0;
	for(auto it : st) a[++len] = it;

	for(int i=1; i<=len; i++) {
		ans = min(ans, 1LL*(a[i] - i)*d + 1LL*(len - i)*c);
	}

	ans = min(ans, 1LL*len * c + d); // remove all and just add a 1
	cout << ans + cost << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
