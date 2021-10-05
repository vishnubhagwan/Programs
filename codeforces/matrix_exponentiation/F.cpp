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
#define ipii pair<int, pair<int, int>>
#define pb push_back

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);
const ll MAX = ll(3e18);

struct Matrix {
	vector<vector<ll> > a;
	Matrix(int n) {
		this->a = vector<vector<ll> >(n,vector<ll>(n, MAX));
	}
	Matrix operator *(Matrix b) {
		int n = b.a.size();
		Matrix c = Matrix(n);
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				for(int k = 0 ; k < n ; k++)
					c.a[i][k] = min(c.a[i][k], a[i][j] + b.a[j][k]);
		return c;
	}
	void print() {
		int n = a.size();
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++)
				cout << a[i][j] << '\t';
			cout << '\n';
		}
	}
};

bool inside(int i, int j) {
	return i >= 0 && i < 8 && j >= 0 && j < 8;
}

int main() {
	int n,m,k;
	cin >> n >> m >> k;
	Matrix p = Matrix(n);
	for(int i = 0 ; i < m ; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u--,v--;
		p.a[u][v] = w;
	}
	Matrix ans = Matrix(n);
	for(int i = 0 ; i < n ; i++)
		ans.a[i][i] = 0;
	while(k > 0) {
		if(k & 1)
			ans = ans * p;
		p = p * p;
		k /= 2;
	}
	ll ans1 = MAX;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			ans1 = min(ans1, ans.a[i][j]);
	if(ans1 >= 2*MAX/3) cout << "IMPOSSIBLE\n";
	else
		cout << ans1 << '\n';
	return 0;
}

