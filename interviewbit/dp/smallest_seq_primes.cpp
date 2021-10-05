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
#define f first
//#define s second
#define vipii vector<int, pair<int, int> >
#define vi vector<int>
#define ipii pair<int, pair<int, int> >
#define pb push_back

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int mn(int a, int b, int c) {
	return min(a,min(b,c));
}

vector<int> f(int a, int b, int c, int n) {
	vector<int> d;
	vector<int> e = {a,b,c}, f = {0,0,0};
	int i = 0;
	while(d.size() < n) {
		int ans = mn(e[0], e[1], e[2]);
		if(d.size() > 0 && d[d.size()-1] != ans)
			d.push_back(ans);
		else if(d.size() == 0)
			d.push_back(ans);
		if(e[0] == ans)
			e[0] = d[f[0]++] * a;
		else if(e[1] == ans)
			e[1] = d[f[1]++] * b;
		else
			e[2] = d[f[2]++] * c;
	}
	return d;
}

int main() {
	int a,b,c,n;
	cin >> a >> b >> c >> n;
	vi d = f(a,b,c,n);
	for(auto i : d) cout << i << ' '; cout << '\n';
	return 0;
}

