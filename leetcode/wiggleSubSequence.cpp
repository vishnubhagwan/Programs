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

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int maxSellStock(vector<int> a) {
	int n = a.size();
	int dp[n][2];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < 2 ; j++)
			dp[i][j] = 0;
	// dp[i][j] = length of max wiggle sequence ending at i with state increasing j=1 or decreasing j=1
	// dp[i][0] = max(dp[j][1] + 1) if a[j] > a[i] for 0 <= j < i
	// dp[i][1] = max(dp[j][0] + 1) if a[j] < a[i] for 0 <= j < i
	// else dp[i][j] = -INF
	int ans = 0;
	for(int i = 1 ; i < n ; i++) {
		if(a[i] == a[i-1]) {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][1];
			continue;
		}
		else {
			if(a[i-1] > a[i])
				dp[i][0] = dp[i-1][1] + 1, dp[i][1] = dp[i-1][1];
			else
				dp[i][1] = dp[i-1][0] + 1, dp[i][0] = dp[i-1][0];
		}
	}
	for(int i = 0 ; i < n ; i++)
		ans = mx(ans, dp[i][0], dp[i][1]);
	return ans+1;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cout << maxSellStock(a) << endl;
	return 0;
}

