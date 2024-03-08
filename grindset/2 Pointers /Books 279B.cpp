#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n,t; cin >> n >> t;

	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	ll l = 0, ans = 0, sum = 0;
	for(int i=0; i<n; i++) {
		sum += a[i];
		while(sum > t) {
			sum -= a[l];
			l++;
		}

		ans = max(i - l + 1, ans);
	}

	cout << ans << "\n";
}
