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

int MOD = int(1e9+7);

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> a(n+1);
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	int dp[k+1];
	for(int i = 0 ; i <= k ; i++)
		dp[i] = 0;
	for(int i = 0 ; i <= k ; i++)
		for(int j = 1 ; j <= n ; j++)
			if(i >= a[j])
				dp[i] |= !dp[i-a[j]];
	if(dp[k])
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}
