#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define all(M) (M).begin(), (M).end()
#define vi vector<ll>
#define sort(v) sort(all(v))
#define fo(i,m,n) for(auto i = m ; i < n ; i++)
#define rep(i,n) fo(i,0,n)
#define f first
#define s second
#define sz(s) s.size()
typedef long long int ll;
typedef pair<ll,ll> pll;

int main()
{
	priority_queue<ll> max_heap; priority_queue<ll, vector<ll>, greater<ll> > min_heap;
	ll l,r,t,m = 0;
	ll n; scanf("%lld",&n); ll a[n];
	rep(i,n)
	{
		scanf("%lld",&t); l = sz(max_heap), r = sz(min_heap);
		if(l == r)
		{
			if(t <= m)
			{
				max_heap.push(t);
				m = max_heap.top();
			}
			else
			{
				min_heap.push(t);
				m = min_heap.top();
			}
		}
		else if(l < r)
		{
			if(t <= m)
				max_heap.push(t);
			else
			{
				max_heap.push(min_heap.top()); min_heap.pop();
				min_heap.push(t);
			}
			m = max_heap.top();
		}
		else
		{
			if(t <= m)
			{
				min_heap.push(max_heap.top()); max_heap.pop();
				max_heap.push(t);
			}
			else
				min_heap.push(t);
			m = max_heap.top();
		}
		printf("%lld\n",m);
	}
	return 0;
}
