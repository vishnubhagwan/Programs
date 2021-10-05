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
	int n,k,t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a,b;
		a = b = 0;
		for(int i = 0 ; i< n ; i++) {
			int l;
			cin >> l;
			if(l == 3)
				if(a < b) b++;
				else a++;
			else if(l == 1) {
				if(a < b) b++;
				else a++;
			}
			else if(l == 2) {
				if(a < b) a--;
				else b--;
			}
		}
		cout << max(a,0) + max(b,0) << '\n';
	}
	return 0;
}

