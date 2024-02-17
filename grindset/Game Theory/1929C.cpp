#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://codeforces.com/contest/1929/problem/C

// every move we dont know if we win it, for a range of x moves
// so to always ensure that if we win at current move, we make more money than we had
// we bet in an amount that if we win the current move, we have a net money after profit more than what we initially had
// also if this strategy works for x moves, then it works forever

void solve(){
	ll k,x,a;
	cin >> k >> x >> a;


	if(x + 1 > a) {
		cout << "NO\n";
		return;
	}


	ll loss = 0;
	for(int i=0; i<=x; i++) {
		ll cur = loss / (k-1) + 1;
		loss += cur;

		if(loss > a) break;
	}

	if(loss <= a) {cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
