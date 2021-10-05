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
#define vl vector<ll>
#define vii vector<vi >
#define vll vector<vl >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(int n, int k) {
	vll dp = vll(n+1, vl(k+1));
	dp[0][0] = 1;
	// dp[n][k] += dp[n-1][k-j]
	for(int l = 1 ; l <= n ; l++)
		for(int i = 1 ; i <= k ; i++) {
			for(int j = (l > 1) ? 0 : 1 ; j < 10 ; j++)
				if(i >= j)
					(dp[l][i] += dp[l-1][i-j])%=MOD;
		}
//	for(int i = 0 ; i <= n ; i++) {
//		for(int j = 0 ; j <= k ; j++)
//			cout << dp[i][j] << '\t';
//		cout << '\n';
//	}
	return dp[n][k];
}

int main() {
	int n,k;
	cin >> n >> k;
	cout << f(n,k) << '\n';
	return 0;
