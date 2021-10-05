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

const int N = int(1e4+1);

ll MOD = ll(1e9+7);
ll dp[N][100][2], M;
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int d;
	string k;
	cin >> k >> d;
	vector<int> a;
	int n = k.size();
	dp[0][0][1] = 1;
	for(int l = 1 ; l <= n ; l++) {
		int c = k[l-1]-'0';
		for(int s = 0 ; s < d ; s++) {
			for(int i = 0 ; i < 10 ; i++)
				(dp[l][(s+i)%d][0] += dp[l-1][s][0])%=MOD;
			for(int i = 0 ; i < c ; i++)
				(dp[l][(s+i)%d][0] += dp[l-1][s][1])%=MOD;
			(dp[l][(s+c)%d][1] += dp[l-1][s][1])%=MOD;
		}
	}
	ll ans = 0;
	ans = (dp[n][0][0] + dp[n][0][1])%MOD;
	ans = (ans+MOD-1)%MOD;
	cout << ans << '\n';
	return 0;
}
