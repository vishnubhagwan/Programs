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

const int N = int(1e3+1);

int MOD = int(1e9+7);
int dp[N][N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> a(n+1);
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	// dp[n][k] = number of ways to distribute k candies to n children such that nth children receives k candies
	// dp[n][k] = dp[n-1][k-p] + dp[n-1][k] for 0 <= p <= a[n]
	dp[0][0] = 1;
	int pre[k+1];
	for(int i = 1 ; i <= n ; i++) {
		if(i == 1)
			for(int j = 0 ; j <= k ; j++)
				pre[j] = 1;
		for(int j = 0 ; j <= k ; j++)
			dp[i][j] = (pre[j] - (j >= a[i]+1 ? pre[j-a[i]-1] : 0) + MOD)%MOD;
		pre[0] = dp[i][0];
		for(int j = 1 ; j <= k ; j++)
			(pre[j] = pre[j-1] + dp[i][j])%=MOD;
	}
	cout << dp[n][k] << '\n';
	return 0;
}

