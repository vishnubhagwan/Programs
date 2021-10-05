#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
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
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

bool cmp(pii a, pii b) {
	if(a.f == b.f)
		return a.s > b.s;
	return a.f < b.f;
}

int maxset(vector<int> a, int b) {
	int n = a.size();
	vector<pii> coords;
	int minLeft, maxRight;
	minLeft = n;
	maxRight = -1;
	for(int i = 0 ; i < n ; i++) {
		if(a[i]) {
			int x = max(i-b+1, 0);
			if(maxRight < x-1)
				return -1;
			minLeft = min(minLeft, x);
			int y = min(i+b-1, n-1);
			maxRight = max(maxRight, y);
			coords.pb({x, y});
		}
	}
	if(minLeft > 0 || maxRight < n-1)
		return -1;
	maxRight = -1;
	sort(coords.begin(), coords.end(), cmp);
//	for(auto i : coords)
//		cout << i.f << ' ' << i.s << endl;
	int ans = 0;
	for( ; maxRight < n ; ) {
		if(maxRight == -1) {
			if(coords[0].f != 0)
				return -1;
			maxRight = coords[0].s + 1;
		}
		else {
			int preRight = maxRight;
			maxRight = lower_bound(coords.begin(), coords.end(), make_pair(maxRight, INT_MIN)) - coords.begin();
			if(maxRight > 0 && coords[maxRight].f != preRight)
				maxRight = lower_bound(coords.begin(), coords.end(), make_pair(coords[maxRight-1].f, INT_MIN)) - coords.begin();
			maxRight = coords[lower_bound(coords.begin(), coords.end(), make_pair(coords[maxRight].f, INT_MIN)) - coords.begin()].s + 1;
		}
		ans++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	int b;
	cin >> b;
	cout << maxset(a, b) << endl;
	return 0;
}

