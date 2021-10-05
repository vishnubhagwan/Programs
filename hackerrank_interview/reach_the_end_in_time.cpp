// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;

int n,m,t;
vector<string> s;

bool inside(int x, int y, int n, int m) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

string ff() {
	int x[] = {0,1,-1,0};
	int y[] = {1,0,0,-1};
	int inf = int(1e9)+1;
	int n = s.size();
	int m = s[0].size();
	vector<vector<int> > f, vis;
	queue<pair<int, int> > q;
	f.resize(n);
	vis.resize(n);
	for(int i = 0 ; i < n ; i++)
		f[i].resize(m,inf), vis[i].resize(m);
	f[0][0] = 0;
	q.push({0,0});
	while(!q.empty()) {
		auto tp = q.front();
		q.pop();
		int u = tp.f, v = tp.s;
		for(int i = 0 ; i < 4 ; i++) {
			int xx = u + x[i];
			int yy = v + y[i];
			if(inside(xx,yy,n,m) && !vis[xx][yy] && s[xx][yy] == '.')
				q.push({xx,yy}), f[xx][yy] = min(f[xx][yy], f[u][v] + 1), vis[xx][yy] = 1;
		}
	}
	return f[n-1][m-1] <= t ? "Yes" : "No";
}

int main(){
	cin >> n;
	s.resize(n);
	for(int i = 0 ; i < n ; i++)
		cin >> s[i];
	m = s[0].size();
	cin >> t;
	cout << ff() << '\n';
	return 0;
}

