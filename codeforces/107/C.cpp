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
	int n, q;
	cin >> n >> q;
	int a[51] = {0};
	for(int i = 1 ; i <= n ; i++) {
		int l;
		cin >> l;
		if(a[l] == 0)
			a[l] = i;
	}
	vector<int> ans;
	while(q--) {
		int l;
		cin >> l;
		int to = a[l];
		cout << to << ' ';
		int from = 1;
		for(int i = 1;  i <= 50 ; i++)
			if(a[i] >= from && a[i] < to)
				a[i]++;
		a[l] = 1;
	}
	cout << '\n';
	return 0;
}

