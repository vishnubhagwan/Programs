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
	int t;
	cin >> t;
x:	while(t--) {
		int n;
		cin >> n;
		n += 2;
		vector<ll> a(n);
		multiset<ll> m;
		ll sum = 0;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i], sum+=a[i];
			m.insert(a[i]);
		}
		for(auto i : a) {
			m.erase(m.find(i));
			sum -= i;
			if(sum%2 == 0 && m.count(sum/2)) {
				m.erase(m.find(sum/2));
				for(auto j : m)
					cout << j << ' ';
				cout << '\n';
				goto x;
			}
			m.insert(i);
			sum += i;
		}
		cout << "-1\n";
	}
	return 0;
}

