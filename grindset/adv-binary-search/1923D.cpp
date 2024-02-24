#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
const int inf = 1e9 + 10;

// https://codeforces.com/contest/1923/problem/D

// Binary search on left and right parts for each element
// also keep track to not include segments where all elements equal

void solve(){
	ll n;
	cin >> n;

	vector<ll> a(n), res(n);
	for(ll i=0; i<n; i++) cin >> a[i];

	vector<ll> prev(n), nxt(n);
	vector<ll> pref(n+1);

	for(ll i=0; i<n; i++) pref[i+1] = pref[i] + a[i]; 

	for(ll i=1; i<n; i++) {
		if(a[i] == a[i-1]) prev[i] = prev[i-1];
		else prev[i] = i;
	}

	nxt[n-1] = n-1;
	for(ll i=n-2; i>=0; i--) {
		if(a[i] == a[i+1]) nxt[i] = nxt[i+1];
		else nxt[i] = i;
	} 

	for(ll i=0; i<n; i++) {
		ll v1 = inf, v2 = inf;
		{
			int l = 0, r = i + 1;
			while(r - l > 1) {
				ll mid = (r+l)/2;

				ll cur = pref[i] - pref[i - mid];
				if(prev[i-1] <= i - mid) cur = a[i - 1];

				if(cur > a[i]) r = mid;
				else l = mid;
			}

			if(r != i+1) v1 = r;
		} 

		{
			ll l = 0, r = n - i;
			while(r - l > 1) {
				ll mid = (r + l)/2;

				ll cur = pref[i + mid + 1] - pref[i + 1];
				if(nxt[i+1] >= i + mid) cur = a[i + 1];

				if(cur > a[i]) r = mid;
				else l = mid;
			}

			if(r != n-i) v2 = r;
		}

		res[i] = min(v1,v2);
	}

	for(int i=0; i<n; i++) {
		cout << (res[i] == inf ? -1 : res[i]) << " ";
	}
	cout << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
} 
