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
#define vii vector<vector<int> >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

int main() {
	int n,m;
	cin >> n >> m;
	int a[n][m];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> a[i][j];
	int cnt = 0, xdir = 1, ydir = 1, d = 0, x = 0, y = 0;
	vector<int> ans;
	int l = 0;
	while(cnt < n*m) {
		ans.push_back(a[x][y]);
		switch(d%4) {
			case 0:
				y += ydir;
				if(y == m-l-1)
					d++, ydir *= -1;
				break;
			case 1:
				x += xdir;
				if(x == n-l-1)
					d++, xdir *= -1;
				break;
			case 2:
				y += ydir;
				if(y == l)
					d++, ydir *= -1;
				break;
			case 3:
				x += xdir;
				if(x == l+1)
					d++, xdir *= -1, l++;
				break;
		}
		cnt++;
	}
	for(auto i : ans)
		cout<<i << ' ';
	cout << '\n';
	return 0;
}

