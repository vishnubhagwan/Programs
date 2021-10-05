#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <assert.h>

#define pii pair<int, int>
#define fi first
#define se second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;
typedef long long int ll;

const int N = int(2e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vl vector<ll>
#define vll vector<ll>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

ll gcd(ll a, ll b) {
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	if(a < b)
		swap(a,b);
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

ll seg[4*N];
vl d;

void build(int id, ll l, ll r) {
	if(l == r) {
		seg[id] = d[l];
		return;
	}
	int m = (l+r)/2;
	build(2*id, l, m);
	build(2*id+1, m+1, r);
	seg[id] = gcd(seg[2*id], seg[2*id+1]);
}

ll query(int id, int l, int r, int x, int y) {
	if(l > y || r < x)
		return 0;
	if(x <= l && r <= y)
		return seg[id];
	int m = (l+r)/2;
	return gcd(query(2*id, l, m, x, y), query(2*id+1, m+1, r, x, y));
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vl a(n);
		d.clear();
		memset(seg,0,sizeof seg);
		int ans = 1;
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		for(int i = 0 ; i < n-1 ; i++)
			d.pb(a[i+1]-a[i]);
		if(n <= 2) {
			if(n == 2 && d[0] > 1)
				cout << 2;
			else cout << 1;
			cout << endl;
			continue;
		}
		build(1,0,n-2);
		for(int i = 0, j = 0 ; i < n-1 && j < n-1 ; ) {
			if(query(1,0,n-2,i,j) == 1)
				i++;
			else {
				j++;
				ans = max(ans, j-i+1);
			}
		}
		cout << ans << endl;
	}
}

