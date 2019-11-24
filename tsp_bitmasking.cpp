// TSP-Bitmasking
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
int n, ans = N;

void tsp(int mask=1, int x=0, int cost=0) {
	if(mask == (1<<n)-1) {
		ans = min(ans, cost + a[x][0]);
		return;
	}
	for(int i = 0 ; i < n ; i++)
		if((mask & (1<<i)) == 0)
			tsp(mask|(1<<i), i, cost + a[x][i]);
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
