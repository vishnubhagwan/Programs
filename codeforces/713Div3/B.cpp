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
	int t;
	cin >> t;
x:	while(t--) {
		int n;
		cin >> n;
		char a[n][n];
		pii p,q;
		p = {-1,-1};
		q = {-1,-1};
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++) {
				cin >> a[i][j];
				if(a[i][j] == '*') {
					if(p == pii(-1,-1))
						p = {i,j};
					else
						q = {i,j};
				}
			}
		if(p.fi != q.fi && p.se != q.se)
			a[p.fi][q.se] = '*', a[q.fi][p.se] = '*';
		else {
			if(p.fi == q.fi) {
				for(int i = n-1 ; i >= 0 ; i--)
					if(a[i][p.se] == '.') {
						a[i][p.se] = '*', a[i][q.se] = '*';
						break;
					}
			}
			else {
				for(int i = n-1 ; i >= 0 ; i--)
					if(a[p.fi][i] == '.') {
						a[p.fi][i] = '*', a[q.fi][i] = '*';
						break;
					}
			}
		}
		for(int i = 0 ; i < n ; i++) {
			for(auto j : a[i])
				cout << j;
			cout << '\n';
		}
	}
	return 0;
}

