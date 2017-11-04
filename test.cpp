#include <bits/stdc++.h>
using namespace std;
#define all(M) (M).begin(), (M).end()
#define vi vector<int>
#define vl vector<ll>
#define sort(v) sort(all(v))
#define reverse(v) reverse(all(v))
#define fo(i,m,n) for(int i = m ; i < n ; i++)
#define trace(a) {for(auto i:a) cout << i << ' '; cout << '\n';}
#define rep(i,n) fo(i,0,n)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define T 4
#define N 4
#define pii pair<int, int>

typedef long long int ll;

int main()
{
	time_t t;
	srand((unsigned) time(&t));
	int n=N;
	cout << n << '\n';
	rep(i,n) {
		int p = rand()%2,v; while((v = rand()%T) == 0);
		if(p)
			cout << -v << ' ';
		else cout << v << ' ';
	}
	cout << '\n';
	int q = 5;
	cout << q << '\n';
	while(q--) {
		int l,r;
		while((l = rand()%n) == 0);
		r = l+rand()%(n-l);
		cout << l << ' ' << r << '\n';
	}
	return 0;
}
