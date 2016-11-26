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

#define N (int)1e3+3

vector<vi> g,g1;
vi vis;
stack<ll> s;
ll n,id=1,ans;

void dfs(ll i)
{
	if(vis[i]) return; vis[i] = 1;
	for(auto j:g[i])
		if(!vis[j]) dfs(j);
	s.push(i);
	return;
}

bool connected[N];

void dfs1(ll i)
{
	if(!vis[i])
	{
		connected[i] = ans;
		for(auto j:g1[i])
			if(!vis[j]) dfs1(j);
	}
	return;
}


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll t; cin >> t;
	while(t--)
	{
		cin >> n; vi a(n);
		g.resize(n); g1.resize(n); vis.resize(n);
		rep(i,n)
		{
			cin >> a[i];
			a[i] %= n;
		}
		rep(i,n)
		{
			ll l = (i+a[i]+1)%n;
			g[i].push_back(l);
			g1[l].push_back(i);
		}
		rep(i,n)
			dfs(i);
		fill(all(vis),0);
		while(!s.empty())
		{
			if(!vis[s.top])
			{
				dfs1(s.top());
				ans++;
			}
			s.pop();
		}
	}
	return 0;
}
