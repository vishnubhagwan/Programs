#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
#define pq priority_queue<plll,vector<plll>, greater<plll>>
#define sz(s) s.size()
#define trace(a) {for(auto i:a) cout << i << ' '; cout << endl;}
#define out(a) cout << a << endl;
#define setall(a) fill(all(a),0)
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;


#define N 1000006

ll parent[N], r[N], n;

void MakeSet()
{
	for(ll i = 1 ; i < n; i++)
		parent[i] = i, r[i] = 1;
	return;
}

ll find(ll x)
{
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void Union(ll x, ll y)
{
	ll root_x = find(parent[x]), root_y = find(parent[y]);
	if(root_x == root_y) return;
	if(r[root_x] > r[root_y]) swap(root_x, root_y);
	parent[root_x] = root_y;
	r[root_y] += r[root_x];
	return;
}

int main()
{
	ll m;
	cin >> n >> m;
	pq q; MakeSet();
	rep(i,m)
	{
		ll u,v,w;
		cin >> u >> v >> w;
		q.push(mp(w,mp(u,v)));
	}
	ll e = 0, ans = 0;
	while(e < n-1 && !q.empty())
	{
		auto a = q.top(); q.pop();
		ll u = a.s.f, v = a.s.s, w = a.f;
		if(find(u) != find(v))
		{
			Union(u,v);
			ans+=w;
			e++;
		}
	}
	out(ans);
	return 0;
}
