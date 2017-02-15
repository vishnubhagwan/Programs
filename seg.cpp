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
		return;
	}
	int m = (l+r)>>1, ch1 = 2*id, ch2 = 2*id+1;
	build(l,m,ch1);
	build(m+1,r,ch2);
	return;
}

void update(int y, int x, int l=0, int r=n-1, int id=1)
{
	if(l > y || r < x) return;
	if(l == r)
	{
		return;
	}
	int m = (l+r)>>1;
	update(y,x,l,m,2*id);
	update(y,x,m+1,r,2*id+1);
	return;
}

ll query(int x, int y, int l=0, int r=n-1, int id=1)
{
	if(r < x || l > y)
	if(l >= x && r <= y)
	int m = (l+r)>>1, ch1 = 2*id, ch2 = 2*id+1;
	ll q1 = query(x,y,l,m,ch1), q2 = query(x,y,m+1,r,ch2);
}

int main()
{
	return 0;
}
