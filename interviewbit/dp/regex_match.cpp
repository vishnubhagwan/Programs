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

int f(string a, string b) {
	int n = a.size();
	int m = b.size();
	vector<int> dp(m+1);
	dp[0] = 1;
	for(int i = 1 ; i < m && b[i-1] == '*' ; i++)
	    dp[i] = 1;
	for(int i = 1 ; i <= n ; i++) {
	    vector<int> new_dp(m+1);
		for(int j = 1 ; j <= m ; j++) {
			if(a[i-1] == b[j-1] || b[j-1] == '?')
				new_dp[j] = dp[j-1];
			else if(b[j-1] == '*')
				new_dp[j] = dp[j] | dp[j-1] | new_dp[j-1];
		}
		dp = new_dp;
	}
	return dp[m];
}

int main() {
	string a,b;
	cin >> a >> b;
	cout << f(a,b) << '\n';
	return 0;
}

