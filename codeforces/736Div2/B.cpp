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
	int p,t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[2][n];
		for(int i = 0 ; i < 2 ; i++)
			for(int j = 0 ; j < n ; j++) {
				char ch;
				cin >> ch;
				a[i][j] = ch - '0';
			}
		int ans = 0;
		for(int i = 0 ; i < n ; i++) {
			if(a[0][i] == 0)
				ans += a[1][i], a[1][i] = 0;
			else {
				if(i-1 >= 0 && a[1][i-1] == 1)
					ans++, a[1][i-1] = 0;
				else if(i+1 < n && a[1][i+1] == 1)
					ans++, a[1][i+1] = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

