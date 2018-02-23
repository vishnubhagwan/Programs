#include <bits/stdc++.h>
using namespace std;
#define all(M) (M).begin(), (M).end()
#define vi vector<int>
#define vl vector<ll>
#define sort(v) sort(all(v))
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

#define N int(1e3)
#define MIN -int(1e9)
#define MAX int(1e9)

int n;
string op[100];
int seg[4*N], lazy[4*N];
vector<int> a;

void inp() {
	cin >> n;
	scanf("%*c");
	rep(i,n)
		getline(cin, op[i]);
	return;
}

void update(int x, int y, int v, int l=0, int r=N, int id=1) {
	int ch1=id<<1, ch2=ch1|1;
	if(l > r || x > y || r < x || l > y) return;
	if(x <= l && r <= y) {
		if(lazy[id] != 0) {
			seg[id] += lazy[id];
			lazy[ch1] = lazy[ch2] = lazy[id];
			lazy[id] = 0;
		}
		seg[id] += v;
		lazy[ch1] = lazy[ch2] = v;
		return;
	}
	int m = l+r>>1;
	update(x,y,v,l,m,ch1);
	update(x,y,v,m+1,r,ch2);
	seg[id] = seg[ch1] + seg[ch2];
}

int query(int x, int l=0, int r=N, int id=1) {
	int ch1=id<<1, ch2=ch1|1;
	if(lazy[id] != 0) {
		seg[id] += lazy[id];
		lazy[ch1] = lazy[ch2] = lazy[id];
		lazy[id] = 0;
	}
	if(l > r || x < l || x > r) return 0;
	if(l == r && r == x) return seg[id];
	int m = l+r>>1;
	int q1, q2;
	q1 = query(x,l,m,ch1);
	q2 = query(x,m+1,r,ch2);
	return q1+q2;
}

void solve() {
	stack<int> s;
	for(int i = 0 ; i < n ; i++) {
		stringstream ss;
		ss << op[i];
		while(ss.good()) {
			string t;
			ss >> t;
			if(t != "") {
				if(t == "push") {
					string tmp;
					ss >> tmp;
					int k = stoi(tmp);
					s.push(k);
					a.pb(0);
				}
				else if(t == "pop") {
					string tmp;
					s.pop();
					a.pop_back();
				}
				else {
					string tmp;
					int e, k;
					ss >> tmp;
					e = stoi(tmp);
					ss >> tmp;
					k = stoi(tmp);
					update(0,e-1,k);
				}
			}
			cout << query(a.size()-1)+s.top() << endl;
		}
	}
	return;
}

int main()
{
	clock_t beg = clock();
	inp();
	solve();
	clock_t end = clock();
	fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
	return 0;
}
