#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
	int n;
	cin >> n;

	vector<ll> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	ll sum = 0;
	for(int i=0; i<n; i++) {
		sum += a[i];
		if(sum <= 0) {cout << "NO\n"; return;}
	}

	sum = 0;
	for(int i=n-1; i>=0; i--) {
		sum += a[i];
		if(sum <= 0) {cout << "NO\n"; return;}
	}

	cout << "YES\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
