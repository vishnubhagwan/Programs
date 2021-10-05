#include<iostream>
#include<algorithm>
#include<vector>
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

#define N int(1e6)
#define MIN -int(1e9)
#define MAX int(1e9)

vector<string> ans;

void f(int n, string s = "", int open = 0, int close = 0, int c = 0) {
	if(c < 0)
		return;
	if(n == 0) {
		if(open == close) {
			ans.pb(s);
			return;
		}
		else
			return;
	}
	f(n-1, s+"(", open+1, close, c+1);
	f(n-1, s+")", open, close+1, c-1);
}

void solve() {
	int n;
	cin >> n;
	n *= 2;
	f(n);
	for(auto i : ans)
		cout << i << '\n';
	return;
}

int main()
{
	clock_t beg = clock();
	fast_io;
	solve();
	clock_t end = clock();
	fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
	return 0;
}
