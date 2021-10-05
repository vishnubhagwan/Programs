// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;
typedef long long int ll;

int main() {
	string s,t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int dp[n+1][m+1];
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
			dp[i][j] = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//	for(int i = 0 ; i <= n ; i++) {
//		for(int j = 0 ; j <= m ; j++)
//			cout << dp[i][j] << ' ';
//		cout << '\n';
//	}
//	cout << dp[n][m] << '\n';
	int i = n, j = m;
	string ans = "";
	while(i > 0 && j > 0) {
		if(s[i-1] == t[j-1])
			ans += s[i-1], i--, j--;
		else {
			if(dp[i-1][j] > dp[i][j-1])
				i--;
			else j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
