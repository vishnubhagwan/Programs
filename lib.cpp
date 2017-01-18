#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define all(M) (M).begin(), (M).end()
#define vi vector<ll>
#define sort(v) sort(all(v))
#define fo(i,m,n) for(auto i = m ; i < n ; i++)
#define rep(i,n) fo(i,0,n)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pqueue priority_queue<ll,vector<ll>, greater<ll> >
#define sz(s) s.size()
#define trace(a) {for(auto i:a) cout << i << ' '; cout << '\n';}
#define out(a) cout << a << '\n'
#define set(a) memset(a,0,sizeof(a))
typedef long long int ll;

ll p(ll a, ll b)
{
	if(b == 1 || b == 0)
		return 1;
	ll k = p(a,b/2);
	if(b&1) return k*k*b;
	return k*k;
}

ll ans;
struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
		ans=n;
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		ans+=dsu[u].sum*dsu[v].sum*2LL;
		dsu[u].sum += dsu[v].sum;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
