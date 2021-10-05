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

int num(char a, char b) {
	if(a == '0') return 0;
	int p = a-'0';
	int q = b-'0';
	return p*10+q;
}

int f(string s) {
	if(s[0] == '0')
		return 0;
	int n = s.size();
	ll dp[n+1];
	for(int i = 0 ; i <= n ; i++)
		dp[i] = 0;
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2 ; i <= n ; i++) {
		int k = num(s[i-2], s[i-1]);
		if(k >= 1 && k <= 26) {
			if((i < n && s[i] == '0') || s[i-1] == '0')
				dp[i] = dp[i-1];
			else (dp[i] = dp[i-1] + dp[i-2])%=MOD;
		}
		else if(s[i-1] != '0')
			(dp[i] = dp[i-1])%=MOD;
		else
			dp[i] = 0;
	}
//	for(auto i : dp) cout << i << ' '; cout << '\n';
	return dp[n];
}

int main() {
	string s;
	cin >> s;
	cout << f(s) << '\n';
	return 0;
}

