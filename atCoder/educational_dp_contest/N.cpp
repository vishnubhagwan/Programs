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

const int N = int(1e3+1);

ll MOD = ll(1e18+7);
ll dp[N][N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	// dp[i][j] = min cost to combine slimes from i to j
	// dp[i][j] = min(dp[i][k] + dp[k+1][j] + sum(i,j))
	vector<ll> pre(n);
	for(int i = 0 ; i < n ; i++) {
		pre[i] = (i > 0 ? pre[i-1] : 0) + a[i];
		for(int j = 0 ; j < n ; j++)
			dp[i][j] = MOD;
	}
	for(int i = n-1 ; i >= 0 ; i--) {
		dp[i][i] = 0;
		for(int j = i ; j < n ; j++) {
			ll& tmp = dp[i][j];
			for(int k = i ; k < j ; k++) {
				tmp = min(tmp, dp[i][k] + dp[k+1][j] + pre[j] - (i != 0 ? pre[i-1] : 0));
			}
		}
	}
	cout << dp[0][n-1] << '\n';
	return 0;
}

