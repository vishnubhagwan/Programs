#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
#define fi first
#define se second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int x[] = {0,1,0,-1,1,1,-1,-1};
int y[] = {1,0,-1,0,1,-1,1,-1};

bool safe(int a, int b, int n, int m) {
	return a >= 0 && a < n && b >= 0 && b < m;
}

void solve() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	int m = s.size();
	vector<string> a(n);
	int dir = 0;
	for(int i = -1, j = 0, k = 0 ; k < m ; k++) {
		switch(dir) {
			case 0:
				a[++i].push_back(s[k]);
				break;
			case 1:
				a[--i].push_back(s[k]);
				break;
		}
		if(i == n-1 || (i == 0 && dir == 1))
			dir ^= 1;
	}
	string ans = "";
	for(auto i : a)
		ans += i;
	cout << ans << endl;
	return;
}

int main() {
	solve();
	return 0;
}

