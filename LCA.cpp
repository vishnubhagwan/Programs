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
#define fast_io {cin.tie(0); ios_base::sync_with_stdio(false);}

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vi g[1001];
int p[1001][10],h[1001],n;

void dfs(int u) {
	for(auto v:g[u]) {
		if(h[v] == -1) {
			h[v] = h[u] + 1;
			p[v][0] = u;
			rep(i,10) {
				if(p[v][i] == -1)
					break;
				p[v][i+1] = p[p[v][i]][i];
			}
			dfs(v);
		}
	}
	return;
}

void lift(int& u, int dh) {
	rep(i,10)
		if(dh & (1<<i))
			u = p[u][i];
}

int solve(int u, int v) {
	if(h[v] > h[u])
		swap(u,v);
	int dh = h[u] - h[v];
	lift(u, dh);
	if(u == v) return u;
	for(int i = 9 ; i >= 0 ; i--)
		if(p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];
	return p[u][0];
}

void inp() {
	int m;
	cin >> n;
	fo(u,1,n+1) {
		cin >> m;
		while(m--) {
			int v;
			cin >> v;
			g[u].pb(v), g[v].pb(u);
		}
	}

	fo(i,1,1001) {
		rep(j,10) p[i][j] = -1;
		h[i] = -1;
	}
	h[1] = 0, p[1][0] = 1;
	dfs(1);

	int q;
	cin >> q;
	while(q--) {
		int u,v;
		cin >> u >> v;
		cout << solve(u,v) << '\n';
	}
	return;
}

int main()
{
	clock_t beg = clock();
	fast_io;
	int t;
	cin >> t;
	fo(i,1,t+1) {
		rep(j,1001) g[j].clear();
		cout << "Case " << i << ":\n";
		inp();
	}
	clock_t end = clock();
	fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
	return 0;
}
