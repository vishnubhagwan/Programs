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
#define pb insert_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

ll testCase() {
	int n,m;
	cin >> n >> m;
	int a[n][m];
	set<ipii> s;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> a[i][j], s.insert({a[i][j], {i,j}});
	auto updateNeighbors = [&] (int x, int y, int height) {
		ll ans = 0;
		if(x > 0 && a[x-1][y] < height) {
			ans += height-a[x-1][y];
			a[x-1][y] = height;
			s.insert({height,{x-1, y}});
		}
		if(y > 0 && a[x][y-1] < height) {
			ans += height-a[x][y-1];
			a[x][y-1] = height;
			s.insert({height,{x, y-1}});
		}
		if(x+1 < n && a[x+1][y] < height) {
			ans += height-a[x+1][y];
			a[x+1][y] = height;
			s.insert({height,{x+1, y}});
		}
		if(y+1 < m && a[x][y+1] < height) {
			ans += height-a[x][y+1];
			a[x][y+1] = height;
			s.insert({height,{x, y+1}});
		}
		return ans;
	};
	ll cost = 0;
	vector<vector<bool>> vis(n, vector<bool>(m));
	while(!s.empty()) {
		auto it = *--s.end();
		s.erase(it);
		int height, x, y;
		height = it.fi;
		x = it.se.fi, y = it.se.se;
		if(vis[x][y])
			continue;
		vis[x][y] = true;
		cost += updateNeighbors(x,y,height-1);
	}
	return cost;
}

int main() {
	int n;
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++) {
		ll ans = testCase();
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}

