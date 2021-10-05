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

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(int n) {
	int dp[n+1];
	for(int i = 0 ; i <= n ; i++)
		dp[i] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3 ; i <= n ; i++)
		dp[i] = dp[i-1] + dp[i-2];
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << f(n) << '\n';
	return 0;
}

