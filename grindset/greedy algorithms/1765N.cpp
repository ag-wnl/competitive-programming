#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;	
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;


// using digit value as indice of deque, and storing indices of their occurance in original number
// then each iteration just traversea dn find current min index, then iterte from 0 to 9 digit values and keep appending least value if possible
// also pop all occurances of digits before current new index

// https://codeforces.com/problemset/problem/1765/N

void solve(){
	string s; cin >> s;
	int k; cin >> k;

	deque<int> nums[10];
	for(int i=0; i<s.size(); i++) nums[s[i] - '0'].push_back(i);

	string res;

	for(int i=0; i<s.size(); i++) {
		int cur = s.size(), ind = s.size();

		for(int j=0; j<10; j++) {
			if(nums[j].size() != 0) cur = min(cur, nums[j].front()); 
		}

		for(int j = (i==0); j<10; j++) {
			if(nums[j].size() != 0 && nums[j].front() - cur <= k) {
				res += ('0' + j);
				ind = nums[j].front();
				break;
			}
		}

		k -= ind - cur;
		for(int j=0; j<10; j++) while(nums[j].size() && nums[j].front() <= ind) nums[j].pop_front();
	}

	cout << string(res.begin(), res.end() - k) << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
