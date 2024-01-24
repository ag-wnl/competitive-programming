#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+1;

// problem link : https://codeforces.com/problemset/problem/154/B

// To be pairwise co-prime with all active colliders, 
// their factors should not even contain same prime numbers (as factors are powers of prime)
// So sieve to find smallest prime factor of all numbers. The use it to factorize.

// When activating x: set all prime factors to x, if any position has any other collider: conflict
// When de-activating x : set all prime factors to 0 and mark active[x] = 0

    
int spf[MAXN], primeOccupied[MAXN], active[MAXN];

void sieve () {
    for(int i=1; i<MAXN; i++) spf[i] = i;

    for(int i=2; i<MAXN; i++) {
        for(int j=2*i; j<MAXN; j+=i) {
            if(spf[j] == j) spf[j] = i;
        }
    }
}

vector<int> factorize(int n) {
    vector<int> primes;
    while(n!=1) {
        int x = spf[n];
        while(n%x == 0) n = n/x;
        primes.push_back(x);
    }
    return primes;
}

 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    sieve();

    int n,m;
    cin >> n >> m;

    while(m--) {
        char op; 
        int x;
        cin >> op >> x;
        vector<int> primes = factorize(x);

        if(op == '+') {
            if(active[x]) {
                cout << "Already on\n";
            } else {
                int same = 0;
                for(int it : primes) {
                    if(primeOccupied[it]) {
                        same = primeOccupied[it]; 
                        break;
                    }
                }
                
                if(same) {
                    cout << "Conflict with " << same << "\n";
                } else {
                    cout << "Success\n";
                    active[x] = 1;
                    for(auto it : primes) primeOccupied[it] = x;
                }
            }
        } else {
            if(active[x] == 0) {
                cout << "Already off \n";
            } else {
                cout << "Success\n";
                active[x] = 0;
                for(auto it : primes) primeOccupied[it] = 0;
            }
        }
    }
}
