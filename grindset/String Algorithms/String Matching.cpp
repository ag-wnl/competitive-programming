#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

ll mod = 1e9 + 7;

// problem : https://cses.fi/problemset/task/1753/
// classic substring matching problem, used string hashing for it

long long pwr( long long a, int pw )
{
    long long ret = 1;
    long long x = a;
    for( int i = 1; i <= pw; i <<= 1 ) {
        if( i & pw ) ( ret *= x ) %= mod;
        ( x *= x ) %= mod;
    }
    return ret;
}

long long mdiv( long long a, long long b ) {
    return a * ( pwr( b, mod - 2 ) ) % mod;
}



struct hasher {
	string s;
	ll p = 30;
	int n;

	vector<ll> pref;
	vector<ll> powP;
	vector<ll> invPowP;

	hasher(string inpString) {
		s = inpString; 
		n = s.size();

		pref.resize(n);
		powP.resize(n);
		invPowP.resize(n);
		calc();
		calcPref();
	}

	void calc() {
		ll curPow = 1;
		for(int i=0; i<n; i++) {
			powP[i] = curPow;
			curPow = (curPow*p) % mod;
		}

		invPowP[n-1] = mdiv(1LL, powP[n-1]);
		for(int i=n-2; i>=0; i--) {
			invPowP[i] = (p * invPowP[i+1]) % mod;
		}
	}

	void calcPref() {
		ll curHash = 0;
		for(int i=0; i<n; i++) {	
			curHash = (curHash + (s[i] - 'a' + 1) * powP[i]) % mod;
			pref[i] = curHash; 
		}
	}

	ll subStringHash(int l, int r) {
		ll a = pref[r];
		ll b = (l > 0) ? pref[l-1] : 0LL;
		return ((a - b + mod) * invPowP[l]) % mod;
	}
};

void solve(){
	string s1,s2;
	cin >> s1 >> s2;

	hasher h1 = hasher(s1);
	hasher h2 = hasher(s2);

	int n = s1.size(), m = s2.size();
	ll pattern = h2.subStringHash(0, m-1);

	ll ans = 0;
	for(int i=0; i<= n-m; i++) {
		if(pattern == h1.subStringHash(i, i + m - 1)) {
			ans++;
		}
	}

	cout << ans << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T=1;
	// cin >> T;
	while(T--) solve();
}
