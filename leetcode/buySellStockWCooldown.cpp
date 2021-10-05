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
	vector<vector<int> > dp(n, vector<int>(2));
	int maxDiff = -1e9;
	for(int i = 0 ; i < n ; i++) {
		dp[i][0] = max(dp[i][0], a[i] + maxDiff);
		if(i > 0) {
			dp[i][1] = mx(dp[i][1], a[i-1] + maxDiff, dp[i-1][1]);
			dp[i][0] = max(dp[i][0], dp[i-1][1]);
		}
		maxDiff = max(maxDiff, dp[i][0] - a[i]);
	}
	return max(dp[n-1][0], dp[n-1][1]);
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

