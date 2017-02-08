#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
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
#define pqueue priority_queue<pll,vector<pll>, greater<pll>>
#define sz(s) s.size()
#define trace(a) {for(auto i:a) cout << i << ' '; cout << '\n';}
#define out(a) cout << a << '\n'
#define mset(a) memset(a,0,sizeof(a))
#define si(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define pi(n) printf("%lld\n",n)
#define sm(n,m) scanf("%lld%lld",&n,&m)
#define pm(n,m) printf("%lld %lld\n",n,m)
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

#define N ll(1e5+5)

ll seg[4*N], n;
vi a;

void build(int l=0, int r=n-1, int id=1)
{
	if(l == r)
	{
		seg[id] = a[l];
		return;
	}
	int m = (l+r)>>1;
	build(l,m,2*id);
	build(m+1,r,2*id+1);
	seg[id] = min(seg[2*id], seg[2*id+1]);
	return;
}

void update(int y, int x, int l=0, int r=n-1, int id=1)
{
	if(l == r)
	{
		seg[id] = y;
		return;
	}
	int m = (l+r)>>1;
	if(l <= x && x <= m)
		update(y,x,l,m,2*id);
	else if(m+1 <= x && x <= r)
		update(y,x,m+1,r,2*id+1);
	seg[id] = min(seg[2*id], seg[2*id+1]);
	return;
}

ll query(int x, int y, int l=0, int r=n-1, int id=1)
{
	if(r < x || l > y)
		return INT_MAX;
	if(l >= x && r <= y)
		return seg[id];
	int m = (l+r)>>1;
	return min(query(x,y,l,m,2*id), query(x,y,m+1,r,2*id+1));
}

int main()
{
	return 0;
}
