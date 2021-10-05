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
#define fi first
#define se second
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

int maxSellStock(string s, int X, int Y) {
	int n = s.size();
	//dp[i][j] = min cost for first i characters given that ith char was C (j = 0) and J (j = 1)
	// dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y)
	// dp[i][1] = min(dp[i-1][1], dp[i-1][0] + X)
	vector<vector<int> > dp(n, vector<int>(2, 1e9));
	if(s[0] == '?')
		dp[0][0] = dp[0][1] = 0;
	else
		dp[0][s[0] == 'J'] = 0;
	for(int i = 1 ; i < n ; i++) {
		if(s[i] == 'C') {
			if(s[i-1] == 'J')
				dp[i][0] = dp[i-1][1] + Y;
			else if(s[i-1] == 'C')
				dp[i][0] = dp[i-1][0];
			else
				dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
		}
		else if(s[i] == 'J') {
			if(s[i-1] == 'C')
				dp[i][1] = dp[i-1][0] + X;
			else if(s[i-1] == 'J')
				dp[i][1] = dp[i-1][1];
			else
				dp[i][1] = min(dp[i-1][1], dp[i-1][0] + X);
		}
		else {
			dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
			dp[i][1] = min(dp[i-1][1], dp[i-1][0] + X);
		}
	}
//	cout << '\n';
//	for(int i = 0 ; i < n ; i++)
//		dp[i][0] == 1e9 ? printf("%s ", "i") : printf("%d ", dp[i][0]); cout << '\n';
//	for(int i = 0 ; i < n ; i++)
//		dp[i][1] == 1e9 ? printf("%s ", "i") : printf("%d ", dp[i][1]); cout << '\n';
	return min(dp[n-1][0], dp[n-1][1]);
}

int main() {
	int n;
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++) {
		int x,y;
		string s;
		cin >> x >> y >> s;
		cout << "Case #" << i << ": " <<  maxSellStock(s,x,y) << endl;
	}
	return 0;
}

