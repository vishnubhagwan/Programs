#include <bits/stdc++.h>
using namespace std;
#define all(M) (M).begin(), (M).end()
#define vi vector<ll>
#define sort(v) sort(all(v))
#define fo(i,m,n) for(auto i = m ; i < n ; i++)
#define rep(i,n) fo(i,0,n)
#define f first
#define s second
typedef long long int ll;

ll n,m,ans;
vector<vi> g;
vi c;

void dfs(ll i, ll k, ll pr = -1)
{
	if(k > m) return;
	ll a = 1;
	for(auto j:g[i])
		if(j != pr)
		{
			a = 0;
			dfs(j,k*c[j] + c[j],i);
		}
	ans+=a;
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	c.resize(n);
	rep(i,n) cin >> c[i];
	g.resize(n);
	rep(i,n-1)
	{
		ll u,v;
		cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,c[0]);
	cout << ans << endl;
	return 0;
}
