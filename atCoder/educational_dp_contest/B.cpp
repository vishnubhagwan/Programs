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
	int n,k;
	cin >> n >> k;
	vector<int> h(n);
	for(int i = 0 ; i < n ; i++)
		cin >> h[i];
	vector<ll> dp(n, 1e18+2);
	dp[0] = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = max(0,i-k) ; j < i ; j++)
			dp[i] = min(dp[i], dp[j] + abs(h[i]-h[j]));
	cout << dp[n-1] << '\n';
	return 0;
}
