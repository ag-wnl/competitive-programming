#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


void solve(){
	int n;
	cin >> n;

	ll sum1 = (1LL<<n);
	for(int i=1; i<=(n/2 - 1); i++) {
		sum1 += (1LL<<i);
	}

	ll sum2 = 0;
	for(int i=n/2; i<=n-1; i++) {
		sum2 += (1LL<<i);
	}

	cout << abs(sum1 - sum2) << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}	
