#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <assert.h>

#define pii pair<int, int>
#define fi first
#define se second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >
#define fast_io {cin.tie(0); ios_base::sync_with_stdio(false);}

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}
ll dp[200001][10];

int main() {
	int n,m,t;
	for(int i = 0 ; i < 10 ; i++)
		dp[0][i] = 1;
	// dp[i][j] = size of number j after i operations
	// dp[i][j] = dp[i-1][j+1] if j < 9 else dp[i-1][0] + dp[i-1][1]
	for(int i = 1 ; i < 200001 ; i++) {
		for(int j = 0 ; j < 10 ; j++) {
			if(j <= 8)
				dp[i][j] = dp[i-1][j+1];
			else
				dp[i][j] = (dp[i-1][0] + dp[i-1][1])%MOD;
		}
	}
	scanf("%d", &t);
	while(t--) {
		ll ans = 0;
		scanf("%d%d", &n, &m);
		for( ; n ; n /= 10) {
			ans += dp[m][n%10];
			ans %=MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

