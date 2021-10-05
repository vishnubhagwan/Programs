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
ll dp[N][2], M;
vector<int> g[N];

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(string a, string b) {
	int n = a.size();
	int m = b.size();
	if(a == b)
		return true;
	if(a.size() == b.size()) {
		int c[26] = {0};
		for(int i = 0 ; i < n ; i++)
			c[a[i]-'a']++, c[b[i]-'a']--;
		for(int i = 0 ; i < 26 ; i++)
			if(c[i] != 0)
				return false;
	}
	else return false;
	int ans = 0;
	for(int i = 1 ; i < n ; i++) {
		if((f(a.substr(0,i), b.substr(m-i)) && f(a.substr(i), b.substr(0,n-i))) ||
			(f(a.substr(0,i), b.substr(0,i)) && f(a.substr(i), b.substr(i))))
			return true;
	}
	return false;
}

int main() {
	string a,b;
	cin >> a >> b;
	cout << f(a,b) << '\n';
	return 0;
}

