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


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
