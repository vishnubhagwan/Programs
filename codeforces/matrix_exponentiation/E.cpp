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

struct Matrix {
	vector<vector<unsigned> > a;
	Matrix(int n) {
		this->a = vector<vector<unsigned> >(n,vector<unsigned>(n));
	}
	Matrix operator *(Matrix b) {
		int n = b.a.size();
		Matrix c = Matrix(n);
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				c.a[i][j] = 0;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				for(int k = 0 ; k < n ; k++)
					(c.a[i][k] += a[i][j] * b.a[j][k]);
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
	ll k;
	cin >> k;
	vector<unsigned> dp(64);
	for(int j = 0 ; j < 64 ; j++)
		dp[j] = 0;
	dp[0] = 1;
	Matrix p = Matrix(65);
	for(int i = 0 ; i < 8 ; i++) {
		for(int j = 0 ; j < 8 ; j++) {
			for(int dx : {-1,1,-2,2})
				for(int dy : {-1,1,-2,2})
				{
					int x = i + dx, y = j + dy;
					if(inside(x,y) && abs(dx) != abs(dy)) {
						p.a[8*x+y][8*i+j] = 1;
					}
				}
		}
	}
	for(int i = 0 ; i <= 64 ; i++)
		p.a[i][64] = 1;
	Matrix ans = Matrix(65);
	for(int i = 0 ; i < 65 ; i++)
		ans.a[i][i] = 1;
	int n = k+1;
	while(n > 0) {
		if(n&1)
			ans = ans * p;
		p = p * p;
		n /= 2;
	}
	cout << ans.a[0][64] << '\n';
	return 0;
}

