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
//#define sort(v) sort(all(v))
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
//#define set(a) memset(a,0,sizeof(a))
#define si(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define pi(n) printf("%lld\n",n)
#define sm(n,m) scanf("%lld%lld",&n,&m)
#define pm(n,m) printf("%lld %lld\n",n,m)
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

vi a;

void insert(int k)
{
	a.pb(k);
	int i = sz(a);
	while(i > 1)
	{
		int par = (i+1)/2, ch1,ch2; ch1 = par*2, ch2 = par*2+1; int largest = -1;
		if(a[par] > a[ch1] && ch1 < sz(a))
		{
			swap(a[par], a[ch1]);
			largest = ch1;
		}
		if(a[par] > a[ch2] && ch2 < sz(a))
		{
			swap(a[par], a[ch2]);
			largest = ch2;
		}
		if(largest != -1) i = largest;
		else i = par;
	}
	return;
}

int top()
{
	int ans = a[1];
	a[1] = a[sz(a)-1]; a.pop_back();
	int i=1;
	while(i <= sz(a))
	{
		int par = i, ch1 = 2*i, ch2 = 2*i+1; int largest = -1;
		if(a[par] > a[ch1] && ch1 < sz(a))
		{
			swap(a[par], a[ch1]);
			largest = ch1;
		}
		if(a[par] > a[ch2] && ch2 < sz(a))
		{
			swap(a[par], a[ch2]);
			largest = ch2;
		}
		if(largest != -1) i = largest;
		else i <<= 1;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	a.pb(INT_MIN);
	rep(i,n)
	{
		int l; cin >> l;
		insert(l);
//	trace(a);
	}
	while(sz(a) > 1) cout << top() << '\n';
	return 0;
}
