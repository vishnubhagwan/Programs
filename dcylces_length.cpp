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

vector<vi> g;
vi vis,in;
stack<ll> s;
ll n,ans;

void dfs(ll i)
{
	if(vis[i])
	{
		in[i] = 0;
		return;
	}
	s.push(i); in[i] = vis[i] = 1;
	for(auto j:g[i])
	{
		if(!vis[j])
			dfs(j);
		else if(in[j])
		{
			ll k;
			do
			{
				k = s.top(); in[k] = 0;
				s.pop(); ans++;
			} while(k!=j);
			return;
		}
	}
	if(!s.empty())
	{
		in[s.top()] = 0;
		s.pop();
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
		cin >> n; vi a(n); ans = 0;
		g.resize(n); vis.resize(n); in.resize(n);
		rep(i,n)
		{
			cin >> a[i];
			a[i] %= n;
		}
		rep(i,n)
		{
			ll l = (i+a[i]+1)%n;
			g[i].push_back(l);
		}
		rep(i,n)
			if(!vis[i])
				dfs(i);
		g.clear(); vis.clear(); in.clear();
		cout << ans << endl;
	}
	return 0;
}
