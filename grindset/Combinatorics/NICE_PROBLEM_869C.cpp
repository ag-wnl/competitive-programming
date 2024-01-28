#include<bits/stdc++.h>
using namespace std;
 
using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const ll MAXN = 1000 + 5;
const ll mod = 998244353; 

//problem link : https://codeforces.com/contest/869/problem/C

// clusters are independent to other clusters:
// when 2 clusters interact, 1 to 1 (island to island) bridges only possible:
// so for 2 clusters a and b, ways : 
// summation i=0 to min(a,b) -> aCi * bCi * i! (i! as order of bridges can interchange)

//so calc this for the 3 clusters interaction and multiply all 3 interactions.

int a,b,c;
ll modpow(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

//f -> factorial, i -> factorial inverse
ll F[10005],R[10005];
void make(){
    F[0] = 1;
    for(int i=1;i<10005;i++) F[i] = F[i-1]*i%mod;
    for(int i=0;i<10005;i++) R[i] = modpow(F[i],mod-2);
}

ll C(int a,int b){
    return F[a]*R[b]%mod*R[a-b]%mod;
}

ll ret = 0,ret2 = 0,ret3 = 0;
int main(){
    cin>>a>>b>>c; make(); 
    for(int x=0;x<=min(a,b);x++){
        ret += C(a,x) * C(b,x) % mod * F[x] % mod;
        ret %= mod;
    }
    for(int x=0;x<=min(c,b);x++){
        ret2 += C(c,x) * C(b,x) % mod * F[x] % mod;
        ret2 %= mod;
    }
    for(int x=0;x<=min(a,c);x++){
        ret3 += C(a,x) * C(c,x) % mod * F[x] % mod;
        ret3 %= mod;
    }
    cout<<ret*ret2%mod*ret3%mod<<endl;
}
