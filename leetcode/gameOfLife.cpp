#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
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

int x[] = {0,1,0,-1,1,1,-1,-1};
int y[] = {1,0,-1,0,1,-1,1,-1};

bool safe(int a, int b, int n, int m) {
	return a >= 0 && a < n && b >= 0 && b < m;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> a[i][j];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++) {
			int cnt = 0;
			for(int k = 0 ; k < 8 ; k++)
				if(safe(i+x[k], j+y[k], n, m)) {
					cout << cnt << ' ';
					cnt += a[i+x[k]][j+y[k]] > 0;
				}
			cout << cnt << endl;
			if(cnt < 2 || cnt > 3)
				a[i][j] = -1;
			if(cnt == 3)
				a[i][j] = 1;
		}
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			if(a[i][j] == -1)
				a[i][j] = 0;
	for(int i = 0 ; i < n ; i++) {
		for(auto j : a[i]) cout << j << ' ';
		cout << endl;
	}
	return;
}

int main() {
	solve();
	return 0;
}

