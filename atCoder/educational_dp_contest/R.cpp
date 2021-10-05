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
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

struct Matrix {
	vector<vector<ll> > a;
	Matrix(vector<vector<ll> > a) {
		this->a = a;
	}
	Matrix(int n) {
		a.resize(n);
		for(int i = 0 ; i < n ; i++) {
			a[i].resize(n);
			for(int j = 0 ; j < n ; j++)
				if(i == j) a[i][j] = 1;
		}
	}
	Matrix operator *(Matrix b) {
		int n = b.a.size();
		Matrix c = Matrix(vector<vector<ll>>(n, vector<ll>(n)));
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				for(int k = 0 ; k < n ; k++)
					(c.a[i][k] += a[i][j] * b.a[j][k])%=MOD;
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
	ll sum() {
		int n = a.size();
		ll ans = 0;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				(ans += a[i][j])%=MOD;
		return ans;
	}
};

int main() {
	ll n,k;
	cin >> n >> k;
	vector<vector<ll> > a(n, vector<ll>(n));
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			cin >> a[i][j];
		}
	}
	Matrix ans = Matrix(n), p = Matrix(a);
	while(k > 0) {
		if(k & 1)
			ans = ans * p;
		p = p * p;
		k /= 2;
	}
	cout << ans.sum() << '\n';
	return 0;
}

