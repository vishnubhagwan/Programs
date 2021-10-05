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

const int N = 150;

ll MOD = ll(1e9+7);
int dp[N][N][N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(string a, string b, string c) {
	int n = a.size();
	int m = b.size();
	int l = c.size();
	dp[0][0][0] = 1;
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
			for(int k = 0 ; k <= l ; k++) {
				int& ans = dp[i][j][k];
				if(i > 0 && k > 0 && a[i-1] == c[k-1]) {
					ans |= dp[i-1][j][k-1];
				}
				if(j > 0 && k > 0 && b[j-1] == c[k-1])
					ans |= dp[i][j-1][k-1];
				if(i > 0 && j > 0 && k > 0 && a[i-1] == b[j-1] && b[j-1] == c[k-1])
					ans |= dp[i-1][j-1][k-1];
			}
//	for(int i = 1 ; i <= l ; i++) {
//		cout << i << '\n';
//		for(int j = 1 ; j <= n ; j++) {
//			for(int k = 1 ; k <= m ; k++)
//				cout << dp[j][k][i] << '\t';
//			cout << '\n';
//		}
//		cout << '\n';
//	}
	return dp[n][m][l];
}

int main() {
	string a,b,c;
	cin >> a >> b >> c;
	cout << f(a,b,c) << '\n';
	return 0;
}

