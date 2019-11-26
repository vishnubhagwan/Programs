// Shortest distance between two cells in a matrix or grid
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
#define MAX ll(1e18+1)
#define N int(1e6+1)

vector<vector<bool> > vis;
vector<int> x = {0, 0, -1, 1}, y = {1, -1, 0, 0};
int u, v, r, t, n;
set<pair<int, pair<int, int> > > s;
vector<vector<int> > d;

void bfs(vector<vector<char> > a) {
	s.insert({0, {u, v}});
	d[u][v] = 0;
	while(!s.empty()) {
		auto p = *s.begin();
		s.erase(p);
		u = p.s.f, v = p.s.s;
		vis[u][v] = true;
		for(int k = 0; k < 4 ; k++) {
			int i = u+x[k], j = v+y[k];
			if(i < 0 || i >= n || j < 0 || j >= n)
				continue;
			if(!vis[i][j] && a[i][j] != '0') {
				s.insert({p.f+1, {i, j}});
				d[i][j] = p.f+1;
			}
		}
	}
	cout << d[r][t] << '\n';
}

int main() {
	n = 4;
	vector<vector<char> > a = { { '0', '*', '0', 's' }, 
                        { '*', '*', '*', '*' }, 
                        { '0', '*', '0', '*' }, 
                        { 'd', '*', '0', '*' } };
    vis.resize(n);
    d.resize(n);
    for(int i = 0 ; i < n ; i++) {
    	vis[i].resize(n, false);
    	d[i].resize(n);
    	for(int j = 0 ; j < n ; j++)
    		if(a[i][j] == 's')
    			u = i, v = j;
    		else if(a[i][j] == 'd')
    			r = i, t = j;
    }
	vis.resize(n);
	d.resize(n);
	bfs(a);
	return 0;
}
