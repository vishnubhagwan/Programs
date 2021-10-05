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

const int N = (1<<21)+1;

ll MOD = ll(1e9+7);
ll dp[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n;
	cin >> n;
	vector<vector<int> > a;
	a.resize(n+1);
	for(int i = 1 ; i <= n ; i++) {
		a[i].resize(n+1);
		for(int j = 1 ; j <= n ; j++)
			cin >> a[i][j];
	}
	// dp[b][i] = number of ways to pair b boys with j girls
	// dp[b][j] += dp[b^(1<<i)][j] for 1 <= i <= n such that a[i][j] = 1
	dp[0] = 1;
	for(int b = 1 ; b < (1<<n) ; b++) {
		int cnt = __builtin_popcount(b);
		for(int j = 1 ; j <= n ; j++) {
			if(a[cnt][j]) { 
				(dp[b] += dp[b^(1<<(j-1))])%=MOD;
			}
		}
	}
	cout << dp[(1<<n)-1] << '\n';
	return 0;
}
