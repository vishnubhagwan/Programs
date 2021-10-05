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
	int n;
	cin >> n;
	int a[n+1][3];
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	int dp[n+1][3];
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j < 3 ; j++)
			dp[i][j] = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 0 ; j < 3 ; j++) {
			int ans = 0;
			for(int k = 0 ; k < 3 ; k++)
				if(k != j)
					ans = max(ans, dp[i-1][k] + a[i][k]);
			dp[i][j] = ans;
		}
	cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
	return 0;
}
