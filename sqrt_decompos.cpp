#include <bits/stdc++.h>
using namespace std;
#define all(M) (M).begin(), (M).end()
#define vi vector<int>
#define vl vector<ll>
// #define sort(v) sort(all(v))
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
#define ndl '\n'
#define fast_io {cin.tie(0); ios_base::sync_with_stdio(false);}

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define N int(1e5)+1
#define MIN -int(1e9)
#define MAX int(1e9)
int BLOCK;

inline void inp() {
	return;
}

inline bool cmp(pair<int, pii> s, pair<int, pii> t) {
	if(s.s.f/BLOCK != t.s.f/BLOCK)
		return s.s.f/BLOCK < t.s.f/BLOCK;
	return s.s.s < t.s.s;
}

int tot;

inline void add(int x) {
	return;
}

inline void remove(int x) {
	return;
}

inline void solve() {
	si(p);
	b = sqrt(p);
	vector<pair<int, pii>> q;
	rep(i,p) {
		int l,r;
		scanf("%d%d",&l,&r);
		q.pb({i,{l,r}});
	}
	sort(all(q),cmp);
	int curl,curr;
	curl = curr = 0;
	vi ans(p);
	for(auto i:q) {
		int l = i.s.f, r = i.s.s, qq = i.f;
		while(curl < l)
			remove(curl), curl++;
		while(curl > l)
			add(curl-1), curl--;
		while(curr <= r)
			add(curr), curr++;
		while(curr > r+1)
			remove(curr-1), curr--;
		ans[qq] = tot;
	}
	for(auto i:ans) cout << i << ndl;
	return;
}

int main()
{
	clock_t beg = clock();
	fast_io;
	inp();
	solve();
	clock_t end = clock();
	fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
	return 0;
}
