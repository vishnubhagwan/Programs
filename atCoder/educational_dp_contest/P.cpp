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
ll dp[N][2], M;
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

void dfs(int u, int p = -1) {
	ll& res0 = dp[u][0];
	ll& res1 = dp[u][1];
	res0 = res1 = 1;
	for(auto v : g[u]) {
		if(v == p) continue;
		dfs(v,u);
		(res1 *= dp[v][0] + dp[v][1])%=MOD;
		(res0 *= dp[v][1])%=MOD;
	}
	return;
}

int main() {
	cin >> M;
	for(int i = 0 ; i < M-1 ; i++) {
		int u,v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	cout << (dp[0][0] + dp[0][1]) << '\n';
	return 0;
}

