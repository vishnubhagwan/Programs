#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
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
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

string testCase() {
	string a,b,s,t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	a = b = "";
	for(int i = 0 ; i < n ; i++) {
		if(s[i] == '*')
			a += "????";
		else
			a += s[i];
	}
	for(int i = 0 ; i < m ; i++) {
		if(t[i] == '*')
			b += "????";
		else
			b += t[i];
	}
	n = a.size(), m = b.size();
	// dp[i][j] = true if a[0..i] matches b[0..j]
	// dp[i][j] |=	dp[i-1][j] if b[j-1] == '?'
	//		dp[i][j-l] if a[i-1] == '?'
	bool dp[n+1][m+1];
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;
	for(int i = 1 ; i <= n && a[i-1] == '?' ; i++)
		dp[i][0] = 1;
	for(int i = 1 ; i <= m && b[i-1] == '?' ; i++)
		dp[0][i] = 1;
	for(int i = 1; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++) {
			bool& ret = dp[i][j];
			if(a[i-1] == '?' || b[j-1] == '?') {
				ret |= dp[i-1][j-1];
				if(a[i-1] == '?')
					ret |= dp[i-1][j];
				if(b[j-1] == '?')
					ret |= dp[i][j-1];
			}
			else
				ret = dp[i-1][j-1] && a[i-1] == b[j-1];
		}
//	cout << endl;
//	cout << a << endl << b << endl;
//	for(int i = 1 ; i <= n ; i++) {
//		for(int j = 1 ; j <= m ; j++)
//			cout << dp[i][j];
//		cout << endl;
//	}
	return dp[n][m] ? "TRUE" : "FALSE";
}

int main() {
	int n;
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++) {
		string ans = testCase();
		printf("Case #%d: %s\n", i, ans.c_str());
	}
	return 0;
}

