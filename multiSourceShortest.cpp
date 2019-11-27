// Multi Source Shortest Path in Unweighted Graph
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#define f first
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e9+1)
#define N int(1e6+1)

void dij(vector<vector<char> > a) {
	int n = a.size();
	vector<vector<bool> > vis;
	vector<vector<int> > d;
	vis.resize(n);
	d.resize(n);
	for(int i = 0 ; i < n ; i++)
		vis[i].resize(n, false), d[i].resize(n, MAX);
	set<pair<int, pair<int, int> > > t;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(a[i][j] == 'x')
				t.insert({0, {i,j}}), d[i][j] = 0;
	vector<int> x = {0, 0, -1, 1, -1, 1, 1, -1};
	vector<int> y = {1, -1, 0, 0, 1, -1, 1, -1};
	while(!t.empty()) {
		auto p = *t.begin();
		t.erase(p);
		int u = p.s.f, v = p.s.s, dist = p.f;
		vis[u][v] = true;
		for(int k = 0 ; k < 8 ; k++) {
			int i = u+x[k], j = v+y[k];
			if(i < 0 || i >= n || j < 0 || j >= n)
				continue;
			if(!vis[i][j] && d[i][j] > dist + abs(x[k]) + abs(y[k]))
				d[i][j] = dist + abs(x[k]) + abs(y[k]), t.insert({d[i][j], {i,j}});
		}
	}
	int ans = MAX;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(a[i][j] == 'y')
				ans = min(ans, d[i][j]);
	cout << ans << '\n';
}

int main() {
	vector<vector<char> > a = {
		{ 'x', '0', '0', 'y' },
		{ '0', '0', '0', 'y' },
		{ 'x', 'x', '0', '0' },
		{ '0', '0', '0', 'y' }
	};
	dij(a);
	return 0;
}
