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

const int N = int(1e5+1);

ll MOD = ll(1e9+7);
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(string a, string b) {
	int n = a.size();
	if(a.size() != b.size())
		return 0;
	int c[26] = {0};
	for(int i = 0 ; i < 26 ; i++)
		c[a[i]-'a']++, c[b[i]-'a']--;
	for(int i = 0 ; i < 26 ; i++)
		if(c[i] != 0)
			return 0;
	int dp[n+1][n+1][n+1];
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= n ; j++)
			for(int k = 0 ; k <= n ; k++)
				dp[i][j][k] = 0;
	// dp[i][j][l] = a[i..i+l] is scrambled string of b[j..j+l]
	// dp[i][j][l] = 
}

int main() {
	string a,b;
	cin >> a >> b;
	cout << f(a,b) << '\n';
	return 0;
}

