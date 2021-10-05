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

const int N = int(1e3+1);

int MOD = int(1e9+7);
int dp[N][N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	int sum = 0;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i], sum += a[i];
	for(int i = n ; i >= 1 ; i--) {
		for(int j = 1 ; j <= n ; j++)
			if(i <= j)
				dp[i][j] = mx(dp[i][j], dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
		for(int j = 0 ; j <= n ; j++) {
			for(int k = 0 ; k <= n ; k++)
				cout << dp[j][k] << '\t';
			cout << '\n';
		}
		cout << '\n';
	}
	cout << dp[1][n] - (sum - dp[1][n]) << '\n';
	return 0;
}
