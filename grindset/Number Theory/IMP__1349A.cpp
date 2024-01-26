#include<bits/stdc++.h>
using namespace std;
#include<math.h>

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 2e5+1;

// problem link: https://codeforces.com/contest/1349/problem/A

// gcd = smallest power of prime factors among all ai
// lcm = largest power of prime factor among all ai

// so when we take lcm of all pairs by observation:
// 1) Smallest power of prime disappears
// 2) 2nd smallest power of prime occurs once ofc
// So just multiply the 2nd smallest power of prime present in all elements for gcd


vector<int> spf(MAXN);

void sieve() {
    for(int i=1; i<MAXN; i++) spf[i] = i;

    for(int i=2; i<MAXN; i++) {
        for(int j=2*i; j<MAXN; j+=i) {
            if(spf[j] == j) {
                spf[j] = i;
            }
        }
    }    
}


 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    sieve();

    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> primes(MAXN, vector<int>());

    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++) {
        while(a[i] != 1) {
            int x = spf[a[i]], cnt = 0;
            
            while(a[i] % x == 0) {
                a[i] /= x;
                cnt++;
            }
            primes[x].push_back(cnt);
        }
    }

    ll gcd = 1;

    for(int i=1; i<=MAXN; i++) {        
        sort(primes[i].begin(), primes[i].end());

        if(primes[i].size() >= n-1) {
            if(primes[i].size() == n) gcd *= pow(i, primes[i][1]);
            else gcd *= pow(i, primes[i][0]);    
        } 
    }

    cout << gcd << "\n";
}
