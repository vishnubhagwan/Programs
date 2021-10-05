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

#define vi vector<int>
#define pb push_back

ll MOD = ll(1e9+7);

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(vi a) {
	int n = a.size();
	vi dp(n);
	dp[0] = 1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 1 ; j <= a[i] && i + j < n; j++)
			dp[i+j] |= dp[i];
	}
	return dp[n-1];
}

int main() {
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cout << f(a) << '\n';
	return 0;
}

