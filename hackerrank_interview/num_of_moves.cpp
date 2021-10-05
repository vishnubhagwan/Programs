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

int n,a,b,c,d;

bool inside(int x, int y, int n) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int ff() {
	int x[] = {2,1,-2,-1,-2,2,-1,1};
	int y[] = {1,2,-1,-2,1,-1,2,-2};
	int inf = int(1e9)+1;
	vector<vector<int> > f, vis;
	queue<pair<int, int> > q;
	f.resize(n+1);
	vis.resize(n+1);
	for(int i = 0 ; i <= n ; i++)
		f[i].resize(n+1,inf), vis[i].resize(n+1);
	f[a][b] = 0;
	q.push({a,b});
	while(!q.empty()) {
		auto t = q.front();
		q.pop();
		int u = t.f, v = t.s;
		vis[u][v] = 1;
		for(int i = 0 ; i < 8 ; i++) {
			int xx = u + x[i];
			int yy = v + y[i];
			if(inside(xx,yy,n) && !vis[xx][yy])
				q.push({xx,yy}), f[xx][yy] = min(f[xx][yy], f[u][v] + 1);
		}
	}
	return f[c][d];
}

int main(){
	cin >> n >> a >> b >> c >> d;
	a++,b++,c++,d++;
	cout << ff() << '\n';
	return 0;
}

