// given number of seats in each row. Price of seat in even row is number of seats in that even row and price of odd row is 100-number of seats in that odd row. Find maximum possible price for first n customers.

#include <iostream>
#include <queue>
#include <map>
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


void inp() {
	return;
}

bool operator< (ii a, ii b) {
	if(a.f == b.f)
		return a.s <= b.s;
	return a.f < b.f;
}

int maxPrice(vector<int> seats, int numCustomers) {
	int n = seats.size();
	priority_queue<ii, vector<ii> > q;
	for(int i = 0 ; i < n ; i++) {
		if(i & 1)
			q.push({seats[i], i});
		else
			q.push({100-seats[i], i});
	}
	int maxPriceVal = 0;
	while(numCustomers > 0) {
		ii largestPrice = q.top();
		int price = largestPrice.f;
		int index = largestPrice.s;
		maxPriceVal += price;
		seats[index]--;
		q.pop();
		if(seats[index] > 0) {
			if(index & 1)
				q.push({seats[index], index});
			else
				q.push({100-seats[index], index});
		}
		numCustomers--;
	}
	return maxPriceVal;
}

void solve() {
	int n;
	cin >> n;
	vector<int> seats(n);
	for(int i = 0 ; i < n ; i++)
		cin >> seats[i];
	int numCustomers;
	cin >> numCustomers;
	cout << maxPrice(seats, numCustomers) << '\n';
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
