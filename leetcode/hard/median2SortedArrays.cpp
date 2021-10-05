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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	int m;
	cin >> m;
	vector<int> b(m);
	for(int i = 0 ; i < m ; i++)
		cin >> b[i];
	int l = 0, r = n-1;
	double ans = 0.0;
	while(l <= r) {
		int m1 = (l+r)/2;
		int m2 = (n+m)/2-m1;
		int l1 = m1 == 0 ? -MOD : a[m1-1];
		int l2 = m2 == 0 ? -MOD : b[m2-1];
		int r1 = m1 == n ? MOD : a[m1];
		int r2 = m2 == m ? MOD : b[m2];
		cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
		if(l1 <= r2 && l2 <= r1) {
			if((n+m)%2 == 0)
				ans = (max(l1,l2) + min(r1,r2))/2.0;
			else
				ans = min(r1,r2);
			break;
		}
		else if(l1 > r2)
			r = m1;
		else
			l = m1+1;
	}
	if(l > r)
		ans = (n+m)%2 == 0 ? (a[n-1] + b[0])/2.0 : b[0];
	cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}

