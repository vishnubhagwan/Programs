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

const int N = int(1e5+1);

ll MOD = ll(1e9+7);
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n,i=1;
	double p, ans;
	cin >> n >> p;
	// dp[n] = probability of limak be happy after n seconds
	// dp[n] = dp[n-1] * (1-p) +  (1-d[n-1]) * p
	ans = 1;
	while(n > 0) {
		if(n&1)
			ans = ans * (1-p) + (1-ans) * p;
		p = p * (1-p) + (1-p) * p;
		n /= 2;
	}
	printf("%.9lf\n", ans);
	return 0;
