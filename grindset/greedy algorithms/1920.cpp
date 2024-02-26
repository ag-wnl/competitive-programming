#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
	int n,k,x;
	cin >> n >> k >> x;

	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	sort(all(a), greater<int>());
	vector<int> pref(n+1);

	for(int i=0; i<n; i++) pref[i+1] = pref[i] + a[i];

	ll ans = -1e16;
	for(int i=0; i<=k; i++) {
		// when elements -ve : 2 * sum of largest present x
		// as they were positive before now to make their contribution -ve, 2 baar minus (once to make 0 then to make their val -ve)
		ll cur =  pref[n] - 2*pref[min(i + x, n)] + pref[i];	
		ans = max(ans, cur);
	}
	cout << ans << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
