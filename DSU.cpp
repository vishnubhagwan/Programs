#include <bits/stdc++.h>
using namespace std;
#define all(M) (M).begin(), (M).end()
#define vi vector<int>
#define vl vector<ll>
#define sort(v) sort(all(v))
#define reverse(v) reverse(all(v))
#define fo(i,m,n) for(int i = m ; i < n ; i++)
#define rep(i,n) fo(i,0,n)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pqueue priority_queue<ll,vector<ll>, greater<ll> >
#define sz(s) s.size()
#define trace(a) {for(int i:a) cout << i << ' '; cout << '\n';}
//#define set(a) memset(a,0,sizeof(a))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld\n",n)
#define smi(n,m) scanf("%d%d",&n,&m)
#define pmi(n,m) printf("%d %d\n",n,m)
#define sml(n,m) scanf("%lld%lld",&n,&m)
#define pml(n,m) printf("%lld %lld\n",n,m)
#define ndl '\n'
#define fast_io {cin.tie(0); ios_base::sync_with_stdio(false);}

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define N int(1e6)
#define MIN -int(1e9)
#define MAX int(1e9)

class DSU {
private:
	vi par, rank;
	int n;
public:
	void make_set(int x) {
		par.resize(x+1);
		rank.resize(x+1);
		rep(i,x+1) par[i] = i, rank[i] = 1;
	}
	DSU(int x=0) {
		n = x;
		make_set(x);
	}
	vi get_par() {
		return par;
	}
	vi get_rank() {
		return rank;
	}
	int get_size() {
		return n;
	}
	int find(int x) {
		if(par[x] != x)
			par[x] = find(par[x]);
		return par[x];
	}
	void un(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]) swap(x,y);
		rank[x] += rank[y];
		rank[y] = 0;
		par[y] = x;
		return;
	}
};

int n;

void inp() {
	cin >> n;
	vi a;
	a.resize(n);
	DSU dsu = DSU(n);
	rep(i,n) cin >> a[i], dsu.un(i+1,a[i]), dsu.find(i);
	set<int> s;
	for(auto i:dsu.get_par()) s.insert(i);
	s.erase(0);
	if(n == 9999) {
	    trace(s);
	}
	cout << sz(s) << ndl;
	return;
}

int main()
{
	clock_t beg = clock();
	fast_io;
	inp();
	clock_t end = clock();
	fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
	return 0;
}