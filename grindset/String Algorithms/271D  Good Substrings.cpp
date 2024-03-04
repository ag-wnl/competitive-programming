#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 2e6+5;


// https://codeforces.com/contest/271/problem/D
// o(n^2) to go through each subarray, and use prefix to check if no of bad okay
// everything inside the two loops = O(1) due to precomputation

// easiest div2 D I've ever solved 


string gud;
vector<ll> gudPref(MAXN, 0);


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
#define sz(x) ((int)(x).size())


struct Hashing{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a){
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 

        for(int i = 0; i < sz(hashPrimes); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            } 
        }
        for(int i = 0; i < sz(hashPrimes); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r){
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++){
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	string s;
	cin >> s >> gud;

	ll k;
	cin >> k;

	ll n = s.size();
	Hashing h1 = Hashing(s);

	for(int i=0; i<n; i++) {
		gudPref[i+1] = gudPref[i] + (gud[s[i] - 'a'] == '1'); 
	}

	vector<vector<ll>> res;

	for(ll i=0; i<n; i++) {
		for(ll j=i; j<n; j++) {
			vector<ll> curSub = h1.substringHash(i, j);
			ll guds = gudPref[j+1] - gudPref[i];

			if(j-i+1 - guds <= k) {
				res.push_back(curSub);
			}
		}
	}

	sort(res.begin(), res.end());
	int unq = 0;
	for(int i=1; i<res.size(); i++) {
		if(res[i] != res[i-1]) unq++;
	}

	if(res.size() == 0) {
		cout << 0 << "\n";
	} else {
		cout << unq + 1 << "\n";
	}
}
