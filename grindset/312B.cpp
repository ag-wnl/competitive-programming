#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;    
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;

// problem link : https://codeforces.com/problemset/problem/312/B

// let p=a/b,q=(1-c/d)*(1-a/b). The answer of this problem can be showed as:p*q^0+p*q^1+p*q^2+………… That is the sum of a geometric progression which is infinite but 0<q<1.We can get the limit by the formula:p/(1-q)

// SmallR, who shoots first can win in the following cases:

// He shoots the target in the first shot. OR
// He misses AND his opponent misses AND he shoots the target. OR
// He misses AND his opponent misses AND he misses AND his opponent misses AND he shoots the target
// When there is an OR between 2 events(which lead to same result) happening, it means EITHER of them will lead to the same result, so the probability of the result is the SUM OF ALL THESE PROBABILITIES.

// On the other hand, when there is AND between 2 events, it means that BOTH OF THEM SHOULD HAPPEN TO GET THE DESIRED OUTCOME. So if event A happens with probability = 1/2 and event B happens with probability = 1/2 and event C happens when both A and B happen, then probability of C happening is 1/2 * 1/2 = 1/4, which also makes sense logically. Because C will happen in only 1 out 4 cases, when BOTH A and B have happened. You can imagine the 4 cases:

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    long double p1 = a / (double)b;
    long double p2 = c / (double)d;
    long double q = (1 - p1) * (1 - p2);

    long double ans = p1 / (double)(1-q); // as < 1 given
    cout << setprecision(12) << ans << "\n";
}
