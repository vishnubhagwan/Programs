// TSP-Backtracking
#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<unordered_set>
#include<algorithm>
#include<queue>
#define f first
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e18+1)
#define N int(1e6+1)

vector<vector<int> > a;
vector<bool> vis;
ll n, ans = MAX;

void tsp(int x = 0, int y = 0, int cnt = 1, ll cost = 0) {
	vis[y] = true;
	if(cnt == n) {
		ans = min(ans,cost + a[y][0]);
		return;
	}
	for(int i = 0 ; i < n ; i++)
		if(!vis[i] && i != y)
			tsp(y,i,cnt+1,cost + a[y][i]);
	vis[y] = false;
	return;
}

int main() {
	cin >> n;
	a.resize(n);
	vis.resize(n,false);
	for(int i = 0 ; i < n ; i++)
		a[i].resize(n);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> a[i][j];
	tsp();
	cout << ans << '\n';
 	return 0;
}
