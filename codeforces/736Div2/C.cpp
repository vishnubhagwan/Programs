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

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n,m;
	cin >> n >> m;
	vi w(n+1);
	while(m--) {
		int u,v;
		cin >> u >> v;
		if(u > v)
			swap(u,v);
		w[u]++;
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
		ans += w[i] == 0;
	int q;
	cin >> q;
	while(q--) {
		int t,u,v;
		cin >> t;
		switch(t) {
			case 1:
				cin >> u >> v;
				if(u > v)
					swap(u,v);
				if(w[u] == 0)
					ans--;
				w[u]++;
				break;
			case 2:
				cin >> u >> v;
				if(u > v)
					swap(u,v);
				w[u]--;
				if(w[u] == 0)
					ans++;
				break;
			case 3:
				cout << ans << '\n';
				break;
		}
	}
	return 0;
}

