#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


vector<int> c(1e6), a(2e5);
void solve(){
	int n, k, d;
	cin >> n >> k >> d;

	for(int i=0; i<n; i++) {
		cin >> a[i];
		a[i]--;
	}

	int tmp = 0;
	for(int i=0; i<d; i++) {
		tmp += c[a[i]]++ == 0;
	}

	int ans = tmp;
	for(int i=d; i<n; i++) {
		tmp += c[a[i]]++ == 0;
		tmp -= --c[a[i-d]] == 0;

		ans = min(ans, tmp);
	}

	for(int i=n-d; i<n; i++) {
		--c[a[i]];
	}

	cout << ans << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
