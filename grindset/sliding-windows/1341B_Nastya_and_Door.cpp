#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

//problm link: https://codeforces.com/contest/1341/problem/B
void solve(){
    int n,k;
    cin >> n >> k;


    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> peaks(n);
    for(int i=1; i<n-1; i++) {
        if(a[i] > a[i-1] && a[i] > a[i+1]) {
            peaks[i] = 1 + peaks[i-1];
        } else {
            peaks[i] = peaks[i-1];
        }
    }

    int maxi = -1; // maximum peaks in a window
    int l = -1; //left most maximum peaks window
    for(int i=k-1; i<n; i++) {
        int curPeaks = peaks[i-1] - peaks[i-k+1];
        if(curPeaks > maxi) {
            maxi = curPeaks;
            l = i-k+1;
            // cout << "Left index: " << l << " ";
        }
    }

    cout << maxi + 1 << " " << l+1 << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}
