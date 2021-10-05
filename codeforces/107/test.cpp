#include <iostream>
using namespace std;
#define all(M) (M).begin(), (M).end()
#define vi vector<int>
#define vl vector<ll>
#define sort(v) sort(all(v))
#define reverse(v) reverse(all(v))
#define fo(i,m,n) for(int i = m ; i < n ; i++)
#define trace(a) {for(auto i:a) cout << i << ' '; cout << '\n';}
#define rep(i,n) fo(i,0,n)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 10
#define pii pair<int, int>

typedef long long int ll;

int main()
{
	time_t t;
	srand((unsigned) time(&t));
	int T = 1;
	cout << T << '\n';
	while(T--) {
		int a,b,c;
		a = rand()%N;
		b = rand()%N;
		c = rand()%N;
		cout << a << ' ' << b << ' ' << c;
	}
	return 0;
}
