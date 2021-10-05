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

const int N = int(1e3+5);

ll MOD = ll(1e9+7);
ll M;
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	// dp[k] = number of sequences of length l such that current number used is k
	vector<ll> pre(n+1);
	for(int i = 1 ; i <= n ; i++)
		pre[i] = 1;
	for(int l = 2 ; l <= n ; l++) {
		vector<ll> dp(l+1);
		for(int j = 1 ; j <= l ; j++) {
			if(s[l-2] == '>') {
				(dp[j] += pre[l-1] - pre[j-1] + MOD)%=MOD;
			}
			if(s[l-2] == '<') {
				(dp[j] += pre[j-1] - pre[0] + MOD)%=MOD;
			}
		}
		for(int j = 1 ; j <= l ; j++)
			(pre[j] = pre[j-1] + dp[j])%=MOD;
	}
	cout << pre[n] << '\n';
	return 0;
}

