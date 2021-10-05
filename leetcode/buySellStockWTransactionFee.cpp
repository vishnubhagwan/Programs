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

int maxSellStock(vector<int> a, int fee) {
	int n = a.size();
	vector<int> dp(n);
	int maxDiff = -1e9;
	for(int i = 0 ; i < n ; i++) {
		dp[i] = max(dp[i], maxDiff + a[i] - fee);
		if(i > 0)
			dp[i] = max(dp[i], dp[i-1]);
		maxDiff = max(maxDiff, dp[i] - a[i]);
	}
	return dp[n-1];
}

int main() {
	int n, fee;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cin >> fee;
	cout << maxSellStock(a,fee) << endl;
	return 0;
}

