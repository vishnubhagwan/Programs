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


void f(int n, int* loc) {
	map<int, int> m;
	for(int i = 1 ; i <= n ; i++) {
		int l = max(1, i-loc[i-1]);
		int r = min(n, i+loc[i-1]);
		m[l] = max(m[l], r);
	}
	int l=0,r=0,ans=1;
	while(1) {
		auto ptr = m.lower_bound(r+1);
		cout << r << ' ';
		l = ptr->f;
		r = ptr->s;
		cout << l << ' ' << r << '\n';
		if(r == n)
			break;
		ans++;
	}
	cout << ans << '\n';
	return;
}

int main() {
	int n;
	cin >> n;
	int loc[n];
	for(int i = 0 ; i < n ; i++)
		cin >> loc[i];
	f(n, loc);
	return 0;
}
