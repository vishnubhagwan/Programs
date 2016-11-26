#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
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
#define setall(a) fill(all(a),0)
typedef long long int ll;

#define N (ll)1e6+5

ll prime[N], s[N], n, a[N], parent[N];

void sieve()
{
	prime[0] = prime[1] = 1;
	for(ll i = 2 ; i < N ; i+=2)
		prime[i] = 2;
	for(ll i = 3 ; i < N ; i+=2)
	{
		if(!prime[i])
		{
			prime[i] = i;
			for(int j = i ; j < N ; j+=i)
				if(!prime[j]) prime[j] = i;
		}
	}
}

void build(ll id=1, ll l=1, ll r=n)
{
	if(l == r)
	{
		s[id] = prime[a[l]];
		return;
	}
	ll m = (l+r)>>1;
	build(2*id, l, m);
	build(2*id+1, m+1, r);
	s[id] = max(s[2*id], s[2*id+1]);
}

void update(ll ind, ll id=1, ll l=1, ll r=n)
{
	if(ind < l || ind > r) return;
	if(l == r)
	{
		s[id] = prime[a[l]];
		return;
	}
	ll m = (l+r)>>1;
	if(ind <= m)
		update(ind,2*id,l,m);
	else update(ind,2*id+1,m+1,r);
	s[id] = max(s[2*id],s[2*id+1]);
}

ll query(ll x, ll y, ll id=1, ll l=1, ll r=n)
{
	if(y < l || x > r)
		return 0;
	if(x <= l && y >= r)
		return s[id];
	ll m = (l+r)>>1,a,b;
	a = query(x,y,2*id,l,m);
	b = query(x,y,2*id+1,m+1,r);
	return max(a,b);
}

ll find(ll i)
{
	if(parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	ll m,type,t; cin >> t;
	while(t--)
	{
		cin >> n >> m;
		fo(i,1,n+1)
		{
			cin >> a[i];
			parent[i] = i;
		}
		parent[n+1] = n+1;
		build();
		while(m--)
		{
			ll x,y;
			cin >> type >> x >> y;
			if(type == 0)
			{
				ll i = find(x);
				while(i <= y)
				{
					a[i] = a[i]/prime[a[i]];
					if(a[i] == 1)
						parent[i] = find(i+1);
					update(i);
					i = find(i+1);
				}
			}
			else
				cout << query(x,y) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
