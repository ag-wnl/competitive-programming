#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://codeforces.com/problemset/problem/1791/G1

void solve(){
	ll n, c;
	cin >> n >> c;

	vector<ll> a(n);
	for(ll i=0; i<n; i++) cin >> a[i];

	// a(i) + (i+1) :  coins for using the i(th) teleport
	for(ll i=0; i<n; i++) {
		a[i] += i+1;
	}

	sort(all(a));

	int cnt = 0;
	for(auto it : a) {
		if(c >= it) {
			c -= it;
			cnt++;
		}
	}

	cout << cnt << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
