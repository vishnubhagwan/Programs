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
	int n;
	cin >> n;
	vector<double> p(n+1);
	for(int i = 1 ; i <= n ; i++)
		cin >> p[i];
	// dp[i] = probability of i heads coming up
	double dp[n+1];
	dp[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		dp[i] = 0;
	for(int j = 1 ; j <= n ; j++) {
		for(int i = 0 ; i <= j ; i++)
			dp[i] = (i == 0 ? 0 : dp[i-1] * p[j]) + dp[i] * (1-p[j]);
	}
	double ans = 0;
	for(int i = 0 ; i <= n ; i++)
		if(n-i < i)
			ans += dp[i];
	printf("%.10lf\n", ans);
	return 0;
}
