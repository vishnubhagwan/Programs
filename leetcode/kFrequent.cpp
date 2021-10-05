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

ll inf = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n;
	cin >> n;
	map<int, int> m;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	auto comp = [&] (int x, int y) {
		return m[x] < m[y];
	};
	set<int, decltype(comp)> st(comp);
	int k;
	cin >> k;
	for(int i = 0 ; i < n ; i++) {
		st.insert(a[i]);
		if(st.size() > k)
			st.erase(*st.begin());
	}
	vector<int> ans;
	while(!st.empty())
		ans.pb(*st.begin()), st.erase(*st.begin());
	reverse(ans.begin(), ans.end());
	for(auto i : ans)
		cout << i << ' ';
	cout << '\n';
	return 0;
}
