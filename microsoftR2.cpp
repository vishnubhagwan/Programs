// given number of seats in each row. Price of seat in even row is number of seats in that even row and price of odd row is 100-number of seats in that odd row. Find maximum possible price for first n customers.

#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
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
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

#define N int(1e6)
#define MIN -int(1e9)
#define MAX int(1e9)

class LRUCache {
	private:
		int capacity;
		map<int, list<int>::iterator> M; // gives a pointer to list where value is present
		unordered_map<int, int> cacheKeyValueMap;
		list<int> cacheKey;
	public:
		LRUCache(int capacity) {
			this->capacity = capacity;
			M.clear();
			cacheKey.clear();
			cacheKeyValueMap.clear();
		}

		int get(int key) {
			if(cacheKeyValueMap.count(key)) {
				cacheKey.push_front(key);
				cacheKey.erase(M[key]);
				M[key] = cacheKey.begin();
				return cacheKeyValueMap[key];
			}
			return -1; // no value
		}

		void put(int key, int value) {
			if(cacheKey.size() == capacity && !cacheKeyValueMap.count(key)) {
				int tmp = cacheKey.back();
				M.erase(tmp);
				cacheKeyValueMap.erase(tmp);
				cacheKey.pop_back();
			}
			if(cacheKeyValueMap.count(key))
				cacheKey.erase(M[key]);
			cacheKey.push_front(key);
			M[key] = cacheKey.begin();
			cacheKeyValueMap[key] = value;
			return;
		}

		int getSize() {
			return cacheKey.size();
		}

		void printCache() {
			for(auto i : cacheKey)
				cout << i << ' ' << cacheKeyValueMap[i] << '\n';
			cout << '\n';
		}
};

void solve() {
	LRUCache cache(4);
	cache.put(1,2);
	cache.put(2,3);
	cache.put(3,4);
	cache.get(1);
	cache.put(4,5);
	cache.put(5,6);
	cache.printCache();
	cache.get(4);
	cache.put(2,3);
	cout << cache.get(1)<<endl;
	cache.printCache();
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
