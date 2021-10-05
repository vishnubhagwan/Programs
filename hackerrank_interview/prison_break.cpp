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

int n,m;
int p,q;
vector<int> v, h;

int f() {
	vector<int> x(n+1), y(m+1);
	for(int i = 1 ; i <= n ; i++)
		x[i] = i;
	for(int j = 1 ; j <= m ; j++)
		y[j] = j;
	sort(h.begin(), h.end());
	sort(v.begin(), v.end());
	for(int i = 0 ; i < p ; i++) {
		int t = h[i];
		x[t] = x[t-1];
	}
	for(int i = 0 ; i < q ; i++) {
		int t = v[i];
		y[t] = y[t-1];
	}
	int mx, my;
	mx = my = 0;
	for(int i = 1 ; i <= n ; i++)
		mx = max(mx, i - x[i] + 1);
	for(int i = 1 ; i <= m ; i++)
		my = max(my, i - y[i] + 1);
	return mx * my;
}

int main(){
	cin >> n >> m;
	v.resize(m), h.resize(n);
	cin >> p;
	for(int i = 0 ; i < p ; i++)
		cin >> h[i];
	cin >> q;
	for(int i = 0 ; i < q ; i++)
		cin >> v[i];
	cout << f() << '\n';
	return 0;
}

