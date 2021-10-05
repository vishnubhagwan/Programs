#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
//#define f first
//#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >
#define pb push_back

using namespace std;
typedef long long int ll;

vector<int> vis, dp;
vector<vector<int> > g;
stack<int> s;

void dfs(int u) {
	vis[u] = 1;
	for(auto v : g[u])
		if(!vis[v]) dfs(v);
	s.push(u);
}

void dfs1(int u) {
	for(auto v : g[u]) {
		if(dp[v] < dp[u]+1) {
			dp[v] = dp[u] + 1;
			dfs1(v);
		}
	}
}

int main() {
	int n,m;
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	dp.resize(n+1);
	while(m--) {
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
	}
	for(int i = 1 ; i <= n ; i++)
		if(!vis[i]) {
			dfs(i);
		}
	vis.clear();
	vis.resize(n+1);
	assert(s.size() == n);
	while(!s.empty()) {
		int tp = s.top();
		s.pop();
		dfs1(tp);
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
}
