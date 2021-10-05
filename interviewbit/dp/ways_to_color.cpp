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

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vi >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(int n) {
	ll dp[4][4][4][n+1];
	for(int i : {0,1,2,3})
		for(int j : {0,1,2,3})
			for(int k : {0,1,2,3})
				for(int l = 0 ; l <= n ; l++)
					dp[i][j][k][l] = 0;
	for(int i : {0,1,2,3})
		for(int j : {0,1,2,3})
			for(int k : {0,1,2,3})
				dp[i][j][k][0] = 1;
	for(int l = 1 ; l <= n ; l++)
		for(int i : {0,1,2,3})
			for(int j : {0,1,2,3})
				for(int k : {0,1,2,3})
					for(int u : {0,1,2,3})
						for(int v : {0,1,2,3})
							for(int w : {0,1,2,3})
								if(i != u && j != v && k != w && i != j && j != k && u != v && v != w)
									(dp[i][j][k][l] += dp[u][v][w][l-1])%=MOD;
	ll ans = 0;
	for(int i : {0,1,2,3})
		for(int j : {0,1,2,3})
			for(int k : {0,1,2,3})
				if(i != j && j != k)
					(ans += dp[i][j][k][n-1])%=MOD;
	return ans;
}

int main() {
	int n;
	cin >> n;
	cout << f(n) << '\n';
	return 0;
}

