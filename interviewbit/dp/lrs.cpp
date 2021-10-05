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

int f(string s) {
	int n = s.size();
	vector<vector<int> > dp = vector<vector<int> >(n+1, vector<int>(n+1));
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			if(s[i-1] == s[j-1] && i != j)
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
//	for(int i = 1 ; i <= n ; i++) {
//		for(int j = 1 ; j <= n ; j++)
//			cout << dp[i][j] << '\t';
//		cout << '\n';
//	}
	return dp[n][n] > 1 ? 1 : 0;
}

int main() {
	string s;
	cin >> s;
	cout << f(s) << '\n';
	return 0;
}

