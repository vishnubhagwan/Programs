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
vi vis,low,high,in;
stack<ll> s;
ll n,id=1,ans;

void connect(ll i)
{
	s.push(i);
	low[i] = high[i] = id;
	in[i] = 1; id++;
	for(auto j:g[i])
		if(high[j] == 0)
		{
			connect(j);
			low[i] = min(low[i],low[j]);
		}
		else if(in[j] = 1)
			low[i] = min(low[i],high[j]);
	if(low[i] == high[i])
	{
		ll j;
		do
		{
			j = s.top(); s.pop();
			in[j] = 0; ans++;
//			cout << j << ' ';
		}while(j!=i);
//		cout << endl;
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
		g.resize(n); low.resize(n); high.resize(n); in.resize(n);
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
			if(high[i] == 0) connect(i);
		rep(i,n)
			cout << low[i] << ' ' << high[i] << endl;
		cout << ans << endl;
	}
	return 0;
}
