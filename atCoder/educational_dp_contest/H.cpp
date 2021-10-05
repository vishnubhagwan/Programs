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

int MOD = int(1e9+7);

int main() {
	int n,m;
	cin >> n >> m;
	char a[n+1][m+1];
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
	dp[1][1] = 1;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			if(a[i][j] == '.' && !(i == 1 && j == 1))
				(dp[i][j] = dp[i-1][j] + dp[i][j-1])%=MOD;
	cout << dp[n][m] << '\n';
	return 0;
}
