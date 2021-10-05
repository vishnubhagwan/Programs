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

ll MOD = ll(1e9+7);
ll dp[N][2], M;
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

struct Matrix {
	vector<vector<ll> > a;
	Matrix(vector<vector<ll> > a) {
		this->a = a;
	}
	Matrix operator *(Matrix b) {
		int n = b.a.size();
		Matrix c({{0,0}, {0,0}});
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
};

int main() {
	ll n;
	cin >> n;
//	dp[0][1] = 1;
//	for(int i = 1 ; i <= n ; i++) {
//		(dp[i][1] += dp[i-1][0] * 6 + dp[i-1][1] * 19)%=MOD;
//		(dp[i][0] += dp[i-1][0] * 20 + dp[i-1][1] * 7)%=MOD;
//	}
	Matrix ans = Matrix({{1,0},{0,1}});
	Matrix p = Matrix({{20, 7}, {6,19}});
	while(n > 0) {
		if(n&1)
			ans = ans * p;
		p = p * p;
		n /= 2;
	}
	cout << ans.a[1][1] << '\n';
	return 0;
}

