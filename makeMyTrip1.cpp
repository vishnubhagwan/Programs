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



int bsearch(vector<int> a, int l, int r, int k) {
	if(l > r)
		return -1;
	int m = (l+r)/2;
	if(l == r) {
		if(a[m] == k)
			return l;
		else
			return -1;
	}
	if(a[m] < k) {
		return bsearch(a, m+1, r, k);
	}
	else {
		return bsearch(a, l, m, k);
	}
}

int solve() {
	int n, k;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	cin >> k;
	int l = 0, r = n-1;
	while(l < r) {
		int m = (l+r)/2;
		if(a[m] > a[m+1])
			l = m+1;
		else
			r = m;
	}
	int ans = 0;
	if((ans = bsearch(a, 0, l-1, k)) != -1)
		return ans;
	ans = bsearch(a, l, n-1, k);
	return ans;
}

int main()
{
	clock_t beg = clock();
	fast_io;
	cout << solve() << endl;
	clock_t end = clock();
	fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
	return 0;
}
