#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
const int mod = 1e9 + 7;

// problem link : https://codeforces.com/contest/1084/problem/C

// keep counts of length of distinct segments of a (distinct by b in between)
// we store length + 1 as we also have the option to not consider any a in that segment
// we multiply all these values stored as they are all the options we can do
// in the end - 1 because there is a case where we choose none of the segment a

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<int> a;
    int cnt = 0;
    int cnta = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 'a') {
            cnt++;
            cnta++;
        }
        
        if(s[i] == 'b'){
            if(cnt) {
                a.push_back(cnt+1);
            }
            cnt = 0;
        }

        if(i == n-1 && cnt) {
            a.push_back(cnt+1);
        }
    }


    ll ans = 1;
    for(int i=0; i<a.size(); i++) {
        ans = ans * a[i] % mod;
    }


    cout << ans - 1 << "\n";
} 
