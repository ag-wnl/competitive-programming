#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

//https://codeforces.com/submissions/ag_wnl

void solve(){
	ll a,b,c,m;
	cin >> a >> b >> c >> m;

	vector<ll> v1;
	vector<ll> v2;
	vector<ll> v3;

	for(int i=0; i<m; i++) {
		ll x; string s;
		cin >> x >> s;

		if(s == "USB") v1.push_back(x);
		if(s == "PS/2") v2.push_back(x);
	}

	sort(all(v1));
	sort(all(v2));

	ll cnt = 0;
	ll cost = 0;

	ll i1 = 0, i2 = 0;
	
	while(a) {
		if(i1 >= v1.size()) break;

		cost += v1[i1];
		i1++;
		a--;
		cnt++;
	}

	while(b) {
		if(i2 >= v2.size()) break;

		cost += v2[i2];
		i2++;

		b--;
		cnt++;
	}

	while((i1 < v1.size() || i2 < v2.size()) && c) {
		if(i1 < v1.size() && i2 < v2.size()) {
			if(v1[i1] <= v2[i2]) {
				c--;
				cost += v1[i1];
				i1++;
				cnt++;
			}else{
				c--;
				cost += v2[i2];
				i2++;
				cnt++;
			}
		}
		else if(i1 < v1.size() && i2>=v2.size()) {
			for(int i=i1; i<v1.size() && c; i++) {
				cost += v1[i];
				c--;
				cnt++;
			} 
			break;
		}
		else if (i1 >= v1.size() && i2 < v2.size()) {
			for(int i=i2; i<v2.size() && c; i++) {
				cost += v2[i];
				c--;
				cnt++;
			} 
			break;
		}
	}

	cout << cnt << " " << cost << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T=1;
	// cin >> T;
	while(T--) solve();
}
