#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// only number of trailing zeros matter as if they reversed, digits in last element reduce
// https://codeforces.com/contest/1931/problem/E

void solve(){
	ll n,m;
	cin >> n >> m;

	vector<ll> a(n), zeros;
	for(ll i=0; i<n; i++) cin >> a[i];

	// need m+1 digits to be >= 10^m
	for(auto it : a) {
		ll z = 0, digits = 0;

		while(it % 10 == 0) {z++; it /= 10;}

		while(it) {digits++; it /= 10;}

		m -= digits; 
		zeros.push_back(z);
	}

	sort(all(zeros), greater<ll>());

	// sasha moves always odd, so before that anna reverses largest zeros
	for(ll i=1; i<zeros.size(); i+=2) {
		m -= zeros[i];
	}

	if(m < 0) {
		cout << "Sasha\n";
	} else {
		cout << "Anna\n";
	}
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
