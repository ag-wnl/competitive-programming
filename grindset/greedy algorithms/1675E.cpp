#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// https://codeforces.com/problemset/problem/1675/E

void solve(){
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int maxi = 0;
	for(int i=0; i<n; i++) {
		if(s[i] - 'a' > k) {
			char l = s[i] - (k - maxi);
			char r = s[i];

			for(int j=0; j<n; j++) {
				if(l <= s[j] && s[j] <= r) {
					s[j] = l;
				}
			}
			break;
		}

		maxi = max(maxi, s[i] - 'a');
	}

	for(int i=0; i<n; i++) {
		if(s[i] <= 'a' + maxi) {
			s[i] = 'a';
		}
	}

	cout << s << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
