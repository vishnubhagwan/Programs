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
		map<int, int> m,c;
		int n;
		cin >> n;
		for(int i = 1 ; i<= n ; i++) {
			int l;
			cin >> l;
			m[l] = i;
			c[l]++;
		}
		for(auto i : c)
			if(i.se == 1) {
				cout << m[i.fi] << '\n';
				goto x;
			}
	}
	return 0;
}

