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

int f(vector<int> a) {
	int n = a.size();
	int dp[n];
	for(int i = 0 ; i < n ; i++) dp[i] = 1;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < i ; j++)
			if(a[i] > a[j])
				dp[i] = max(dp[i], dp[j]+1);
	int ans = 0;
	for(int i = 0 ; i < n ; i++)
		ans = max(ans, dp[i]);
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cout << f(a) << '\n';
	return 0;
}

