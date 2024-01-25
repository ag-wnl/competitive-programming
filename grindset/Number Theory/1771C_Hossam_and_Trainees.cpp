#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 5e4; //sqrt(1e9), as in factorizan we need only primes upto sqrt n

// problem link : 

// As obvious, check for common prime factors, to be more efficient as 1e9 range
// we only factorize using pre-computed primes instead of going 2 to sqrt N 

vector<int> isPrime(MAXN + 1, 1), primes;

void findPrimes() {
    isPrime[0] = isPrime[1] = 0;

    for(ll i=2; i<=MAXN; i++) {
        if(isPrime[i]) {
            primes.push_back(i);

            for(ll j = 1LL* i * i; j<=MAXN; j+=i) {
                isPrime[j] = 0;
            }
        }
    }
}



void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n);   
    map<ll,ll> mp;

    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }

    for(ll i=0; i<n; i++) {
        ll x = a[i];

        for(auto it : primes) {
            if(it*it > a[i]) {
                break;
            }
            bool ok = false;
            while(x % it == 0) {
                ok = true;
                x = x/it;
            }

            if(ok) {
                if(mp.find(it) != mp.end()) {
                    cout << "YES\n";
                    return;
                }
                mp[it]++;
            }
        }

        if(x > 1) {
            if(mp.find(x) != mp.end()) {
                cout << "YES\n";
                return;
            }
            mp[x]++;
        }
    }
    cout << "NO\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;

    findPrimes();
    while(T--) solve();
}
