#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

//problem link: https://codeforces.com/problemset/problem/476/B

// Each  ? has 0.5 chance to be something.
// If unused spaces after using unknowns odd -> probab 0 as we will be one off
// nCr -> n : unknown spaces, r : used spaces + unused / 2; 
// used spaces = different in s1 and s2 final posn ofc!

long double ncr(ll n, ll  r) {
    int i;
    long double p=1.0, q=1.0, ans=1.0;
    if(r > n) {
        return 0.0;
    }

    if(r == n) {
        return 1.0;
    }

    for(i=0; i<r; i++) {
        p = n-i;
        q = i+1;
        ans*=(p/q);
    }

    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s1;
    cin >> s1;

    string s2;
    cin >> s2;


    int pos1 = 0;
    int pos2 = 0;
    int un = 0;

    for(int i=0; i<s1.size(); i++) {
        if(s1[i] == '+') pos1++;
        else pos1--;
    }

    for(int i=0; i<s2.size(); i++) {
        if(s2[i] == '+') pos2++;
        if(s2[i] == '-') pos2--;
        if(s2[i] == '?') un++;
    }

    cout << setprecision(10) << "\n";

    int dif = abs(pos1 - pos2);
    if(dif > un) {
        cout << 0 << "\n";
        return 0;
    }

    int unusedExtras = un - dif;
    if(unusedExtras % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long double ans = ncr(un, dif + unusedExtras/2) * pow(0.5, un);
    cout << setprecision(15) << ans << "\n";
}
