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
	// dp[i][j] = number of ways make subsequences from a[0..i] identical to sequence b[0..j]
	vector<vector<int> > dp = vector<vector<int> >(n+1, vector<int>(m+1));
	for(int i = 0 ; i <= n ; i++)
		dp[i][0] = 1;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
			if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1];
			dp[i][j] += dp[i-1][j];
		}
	}
//	for(int i = 1 ; i <= n ; i++) {
//		for(int j = 1 ; j <= m ; j++)
//			cout << dp[i][j] << '\t';
//		cout << '\n';
//	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
		ans = max(ans, dp[i][m]);
	return ans;
}

int main() {
	string s1,s2;
	cin >> s1 >> s2;
	cout << f(s1,s2) << '\n';
	return 0;
}

