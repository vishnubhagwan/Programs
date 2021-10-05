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

int main() {
	cin >> t;
	while(t--) {
		int n,m,k;
		scanf("%d%d%d", &n, &m, &k);
		ok = false;
		vector<int> a(n+1);
		for(int i = 1 ; i <= n ; i++)
			scanf("%d", &a[i]);
		// dp[i][j] = max score till i with last zero set at j
		// dp[i][j] = max(dp[i-1][j], dp[i-1][k] + g[i] + d[k+1][i]) for j >= 0 and k < j
	}
	return 0;
}

