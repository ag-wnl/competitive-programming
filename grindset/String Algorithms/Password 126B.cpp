#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

ll mod = 1e9 + 7;

// https://codeforces.com/contest/126/problem/B

// find lengths of good prefix and suffix
// then binary search on them to find the maximum of them which exists acc to conditions
  
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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.size();
	hasher h1 = hasher(s);

	vector<ll> lengths;
	for(int i=0; i<n-1; i++) {
		if(h1.subStringHash(0, i) == h1.subStringHash(n-1-i, n-1)) {
			lengths.push_back(i+1);
		}
	}

	if(lengths.size() == 0) {cout << "Just a legend\n"; return 0;}

	int lo = 0, hi = lengths.size() - 1;
	int ans = -69;	

	while(lo <= hi) {
		int mid = (hi+lo) >> 1;
		int len = lengths[mid];

		bool ok = false;
		ll curHash = h1.subStringHash(0, len-1);
		for(int i=1; i<=n-1 - len; i++) {
			if(h1.subStringHash(i, i+len-1) == curHash) {
				ok = true;
			}
		}

		if(ok) {
			ans = len;
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}

	if(ans == -69) {
		cout << "Just a legend\n";
	} else {
		cout << s.substr(0, ans) << "\n";
	}
}
