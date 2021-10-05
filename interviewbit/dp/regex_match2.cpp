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
ll dp[N][2], M;
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(string a, string b) {
	int n = a.size();
	int m = b.size();
	vector<vector<int> > dp = vector<vector<int> > (n+1, vector<int>(m+1));
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++) {
			int& res = dp[i][j];
			if(j < m && b[j] == '*') {
				res = dp[i][j-1];
				if(b[j-1] == a[i-1] || b[j-1] == '.')
					res |= dp[i-1][j-1];
			}
			else if(b[j-1] == '.' || b[j-1] == a[i-1]) {
				res = dp[i-1][j-1];
			}
			else if(b[j-1] == '*') {
				res = dp[i][j-1];
				if(j >= 2)
					res |= dp[i][j-2] | ((b[j-2] == a[i-1] || b[j-2] == '.') && dp[i-1][j]);
			}
		}
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	return dp[n][m];
}

int main() {
	string a,b;
	cin >> a >> b;
	cout << f(a,b) << '\n';
	return 0;
}

