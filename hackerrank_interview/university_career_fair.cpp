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
#define pb push_back

using namespace std;


int f(vector<int> b, vector<int> c) {
	vector<pair<int, pair<int, int> > > a;
	int n = b.size(), ans = 0, mx = -1;
	for(int i = 0 ; i < n ; i++)
		a.pb({b[i]+c[i]-1, {c[i], i}});
	sort(a.begin(), a.end());
	for(auto i : a) {
		int p = i.s.s;
		if(mx <= b[p])
			mx = i.f, ans++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> b(n), c(n);
	for(int i = 0 ; i < n ; i++)
		cin >> b[i];
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> c[i];
	cout << f(b,c) << '\n';
	return 0;
}
