// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;


int mn(int a, int b, int c) {
	return min(a,min(b,c));
}

int main() {
	int n;
	cin >> n;
	vector<vector<int> > a(n+1);
	for(int i = 0 ; i <= n ; i++) {
		a[i].push_back(0);
		if(i == 0) {
			for(int j = 0 ; j < n ; j++)
				a[i].push_back(0);
			continue;
		}
		for(int j = 0 ; j < n ; j++) {
			int l;
			cin >> l;
			a[i].push_back(l);
		}
	}
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(a[i][j] > 0)
				a[i][j] = mn(a[i][j-1], a[i-1][j], a[i-1][j-1]) + 1;
	int ans = 0;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			ans = max(ans, a[i][j]);
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ans << ' ';
	return 0;
}
