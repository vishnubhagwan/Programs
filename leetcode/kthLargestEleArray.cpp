#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	int k;
	cin >> k;
	multiset<int> st;
	for(int i = 0 ; i < k ; i++)
		st.insert(a[i]);
	for(int i = k ; i < n ; i++) {
		st.insert(a[i]);
		if(st.size() > k)
			st.erase(st.begin());
	}
	cout << *st.begin() << '\n';
	return;
}

int main() {
	solve();
	return 0;
}
