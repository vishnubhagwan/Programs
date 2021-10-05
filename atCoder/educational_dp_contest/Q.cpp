#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >
#define pb push_back

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);
ll dp[N];
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n;
	cin >> n;
	vector<int> h, a;
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		h.pb(l);
	}
	vector<ll> dp(n);
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		a.pb(l);
		dp[i] = l;
	}
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < i ; j++) {
			if(h[i] > h[j]) {
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
	}
	ll ans = 0;
	for(auto i : dp) ans = max(ans, i);
	cout << ans << '\n';
	return 0;
}

