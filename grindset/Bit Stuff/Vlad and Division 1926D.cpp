#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://codeforces.com/contest/1926/problem/D

// Only 2 at max can be in a group, all bits should be 0. So eventually they add upto 2^31 - 1.
// Find pair of a(i) and a(j) distinct which add upto that. 

void solve(){
	int n;
	cin >> n;

	vector<ll> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	sort(all(a));
	int ans = n;
	int l=0, r=n-1;

	ll aim = (1LL << 31) - 1;	
	while(l < r) {
		ll cur = a[l] + a[r];

		if(cur == aim) {
			ans--;
			l++, r--;
		}
		else if(cur > aim) {
			r--;
		}
		else {
			l++;
		}
	}

	cout << ans << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
} 
