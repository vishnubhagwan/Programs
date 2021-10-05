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

const int N = int(1e6+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int numCount(int x) {
	int cnt = 0;
	while(x > 0) {
		x /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int a,b,c;
		cin >> a >> b >> c;
		if(c == 1) {
			if(a == 1 && b == 1) {
				cout << 2 << ' ' << 3 << '\n';
				continue;
			}
			int x = 2;
			int y = 3;
			while(numCount(x) < a)
				x *= 2;
			while(numCount(y) < b)
				y *= 3;
			cout << x << ' ' << y << '\n';
			continue;
		}
		int x,y;
		x = y = 2;
		while(numCount(x) < c)
			x *= 2;
		while(numCount(y) < c)
			y *= 2;
		while(numCount(x) < a)
			x *= 3;
		while(numCount(y) < b)
			y *= 5;
		cout << x << ' ' << y << '\n';
	}
	return 0;
}

