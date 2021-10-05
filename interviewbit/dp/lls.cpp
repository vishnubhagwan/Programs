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
ll dp[N][2], M;
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(vector<int> a) {
	int n = a.size();
	if(n == 0)
		return 0;
	vector<int> dp(n,1), dp1(n,1);
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < i ; j++)
			if(a[i] > a[j])
				dp[i] = max(dp[i], dp[j]+1);
	}
//	for(auto i : dp) cout << i << ' '; cout << '\n';
	for(int i = n-1 ; i >= 0 ; i--) {
		for(int j = n-1 ; j > i ; j--)
			if(a[i] > a[j])
				dp1[i] = max(dp1[i], dp1[j]+1);
	}
//	for(auto i : dp1) cout << i << ' '; cout << '\n';
	int ans = 1;
	for(int i = 0 ; i < n ; i++)
		for(int j = i+1 ; j < n ; j++)
			if(a[i] != a[j])
				ans = max(ans, dp[i] + dp1[j]);
	return ans;
}

int main() {
	int n,m;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
//	for(auto i : a) cout << i << ' '; cout << '\n';
	cout << f(a) << '\n';
	return 0;
}

