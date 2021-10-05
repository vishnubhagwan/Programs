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
	int N,W;
	cin >> N >> W;
	int w[N+1], v[N+1], MAX = 0;
	for(int i = 1 ; i <= N ; i++)
		cin >> w[i] >> v[i], MAX += v[i];
	ll dp[N+1][MAX+1];
	for(int i = 0 ; i <= N ; i++) {
		dp[i][0] = 0;
		for(int j = 0 ; j <= MAX ; j++)
			if(j != 0)
				dp[i][j] = int(1e9+1);
	}
	for(int i = 1 ; i <= N ; i++) {
		for(int j = 1 ; j <= MAX ; j++) {
			if(j >= v[i])
				dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
		}
//		for(int i = 1 ; i <= N ; i++) {
//			for(int j = 1 ; j <= MAX ; j++)
//				cout << dp[i][j] << ' ';
//			cout << '\n';
//		}
//		cout << "=================================================\n";
	}
//	for(int i = 1 ; i <= N ; i++) {
//		for(int j = 1 ; j <= MAX ; j++)
//			cout << dp[i][j] << ' ';
//		cout << '\n';
//	}
	int ans = 0;
	for(int i = 1 ; i <= MAX ; i++)
		if(dp[N][i] <= W)
			ans = max(ans, i);
	cout << ans << '\n';
	return 0;
}
