#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


// https://codeforces.com/problemset/problem/58/A

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	string s;
	cin >> s;

	string a = "hello";

	int pos = 0;
	for(int i=0; i<s.size(); i++) {
		if(a[pos] == s[i]) {
			pos++;
		}

		if(pos == a.size()) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}
