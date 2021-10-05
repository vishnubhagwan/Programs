#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
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
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int f(int u, int v) {
	int sign = (u < 0) ^ (v < 0) ? -1 : 1;
	ll a = abs(u);
	ll b = abs(v);
	int ans = 0, tmp = 0;
	for(int i = 30 ; i >= 0 ; i--) {
		if(tmp + (b << i) <= a)
			tmp += b<<i, ans += 1<<i;
	}
	return ans * sign;
}

int main() {
	int a,b;
	cin >> a >> b;
	cout << f(a,b) << '\n';
	return 0;
}

