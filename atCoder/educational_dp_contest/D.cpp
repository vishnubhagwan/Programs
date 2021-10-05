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
	int w[N+1], v[N+1];
	for(int i = 1 ; i <= N ; i++)
		cin >> w[i] >> v[i];
	ll dp[N+1][W+1];
	for(int i = 0 ; i <= N ; i++)
		for(int j = 0 ; j <= W ; j++)
			dp[i][j] = 0;
	for(int i = 1 ; i <= N ; i++)
		for(int j = 1 ; j <= W ; j++) {
			if(w[i] <= j)
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
//	for(int i = 1 ; i <= N ; i++) {
//		for(int j = 1 ; j <= W ; j++)
//			cout << dp[i][j] << ' ';
//		cout << '\n';
//	}
	cout << dp[N][W] << '\n';
	return 0;
}
