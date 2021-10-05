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

int f(vi a) {
	int n = a.size();
	vii dp = vii(n, vi(n));
	map<int, int> m;
	int ans = 1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = i+1 ; j < n ; j++) {
			dp[i][j] = 2;
			int k = 2*a[i]-a[j];
			if(m.count(k))
				dp[i][j] = dp[m[k]][i] + 1;
			ans = max(ans, dp[i][j]);
		}
		m[a[i]] = i;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	cout << f(a) << '\n';
	return 0;
}

