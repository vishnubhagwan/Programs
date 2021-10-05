#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vi >
#define pii pair<int, int>
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

map<pii, int> m;

int g(int mask) {
	int tmp = -1;
	int ans = 0;
	for(int j = 0 ; j < 18 ; j++) {
		if(mask & (1<<j)) {
			if(tmp == -1)
				tmp = j;
			ans += m[{tmp, j}];
			tmp = j;
		}
	}
	return ans;
}

int overlap_length(string s, string t) {
	int n = s.size(), m = t.size();
	int j = 0;
	for(int i = n-1 ; i >= 0 && j < m && s[i] == t[j] ; i--, j++);
	return n+m-j;
}

int f(vector<string> a) {
	int n = a.size();
	m.clear();
	for(int i = 0 ; i < n ; i++)
		for(int j = i ; j < n ; j++)
			m[{i,j}] = overlap_length(a[i], a[j]);
	vii dp = vii(n, vi((1<<n)+1, MOD));
	for(int i = 0 ; i < n ; i++)
		dp[i][0] = 0;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 1 ; j < (1<<n) ; j++) {
			int& ans = dp[i][j];
			for(int k = 0 ; k < n ; k++) {
				if(j & (1<<k)) {
					cout << i << ' ' << j << ' ' << (j ^ (1<<i)) << ' ' << dp[k][(j^(1<<i))] << ' ' << g(j) << '\n';
					ans = min(ans, dp[k][j^(1<<i)] + g(j));
				}
			}
		}
	}
	int tmp = MOD;
	cout << '\n';
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < (1<<n) ; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	for(int i = 0 ; i < n ; i++)
		tmp = min(tmp, dp[i][(1<<n)-1]);
	return tmp; 
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cout << f(a) << '\n';
	return 0;
}

