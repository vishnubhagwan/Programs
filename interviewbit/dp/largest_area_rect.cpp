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

const int N = int(1e2+1);

ll MOD = ll(1e9+7);
vector<int> g[N];
int n,m;

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int a[N][N];
int dp[N][N];

int f() {
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			dp[i][j] = a[i][j];
	int ans = 0;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			if(a[i][j] == 1 && i > 0)
				dp[i][j] += dp[i-1][j];
		}
		int cnt[n+2];
		for(int j = 0 ; j <= n+1 ; j++)
			cnt[j] = 0;
		for(int j = 0 ; j < m ; j++)
			cnt[dp[i][j]]++;
		for(int j = n ; j >= 0 ; j--) {
			cnt[j] += cnt[j+1];
			ans = max(ans, cnt[j] * j);
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> a[i][j];
	cout << f() << '\n';
	return 0;
}

