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
	vector<vector<int> > dp = vector<vector<int>>(n+1, vector<int>(m+1));
	// dp[i][j] = longest common subsequence in string s[0..i] and t[0..j]
	// dp[i][j] = dp[i-1][j-1] + 1 if s[i] == t[j] else max(dp[i-1][j], dp[i][j-1])
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++)
			if(a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
	}
	return dp[n][m];
}

int main() {
	string s1,s2;
	cin >> s1 >> s2;
	cout << s1 << ' ' << s2 << '\n';
	cout << f(s1,s2) << '\n';
	return 0;
}

