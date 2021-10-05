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
	int n;
	cin >> n;
	map<int, int> m;
	vector<int> a;
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		a.pb(l);
		m[l]++;
	}
	for(auto i : a) {
		if(m.count(2*i) && m.count(i))
			m[i] = 2*i, m.erase(2*i);
	}
	bool ok = true;
	for(auto i : m) {
		if(i.se == -1) {
			ok = false;
			goto x;
		}
	}
x:	cout << ok << '\n';
	return;
}

int main() {
	solve();
	return 0;
}

