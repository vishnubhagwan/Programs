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
	string a,b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	// dp[i][j] = true if a[0..i] matches b[0..j]
	// dp[i][j] |=	dp[i-k][j] if b[j-1] == '*' for 0 <= k <= 4
	//		dp[i][j-l] if a[i-1] == '*' for 0 <= l <= 4
	//		dp[i-k][j-l] if a[i-1] == '*' and b[j-1] == '*' for 0 <= k <= 4 and 0 <= l <= 4
	bool dp[n+1][m+1];
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
			dp[i][j] = 0;
	dp[0][0] = true;
	for(int i = 1 ; i <= n && a[i-1] == '*' ; i++)
		dp[i][0] = 1;
	for(int i = 1 ; i <= m && b[i-1] == '*' ; i++)
		dp[0][i] = 1;
	int preA[n+1], preB[m+1];
	preA[0] = preB[0] = 0;
	for(int i = 1 ; i <= n ; i++)
		preA[i] = preA[i-1] + (a[i-1] == '*');
	for(int i = 1 ; i <= m ; i++)
		preB[i] = preB[i-1] + (b[i-1] == '*');
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			if(a[i-1] == '*' || b[j-1] == '*') {
				bool& ret = dp[i][j];
				if(a[i-1] == '*')
					for(int k = j, cnt = 0 ; k >= 0 && cnt <= 4 ; k--) {
						if(b[k-1] != '*')
							cnt++;
						ret |= dp[i-1][k];
					}
				if(b[j-1] == '*')
					for(int k = i, cnt = 0 ; k >= 0 && cnt <= 4 ; k--) {
						if(a[k-1] != '*')
							cnt++;
						ret |= dp[k][j-1];
					}
			}
			else
				dp[i][j] = dp[i-1][j-1] && a[i-1] == b[j-1];
//	cout << a << endl << b << endl;
//	cout << '\n';
//	for(int i = 0 ; i <= n ; i++) {
//		for(int j = 0 ; j <= m ; j++)
//			cout << dp[i][j];
//		cout << '\n';
//	}
	return dp[n][m] ? "TRUE" : "FALSE";
}

int main() {
	int n;
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++) {
		string ans = testCase();
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}

