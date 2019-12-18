// Find a triplet that sum to a given value
#include<iostream>
#include<cstdlib>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<pthread.h>
#define f first
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e9+1)
#define N int(1e5+1)

int gcd(int a, int b) {
	if(a < b)
		swap(a,b);
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int a[] = {1,2,3,4,5,6,7};
	int n = 7, k = 3;
	int g = gcd(n,k);
	for(int i = 0 ; i < g ; i++) {
		int tmp = a[i];
		for(int j = (i + k)%n ; j != i ; (j += k)%=n) {
			int tmp1 = a[j];
			a[j] = tmp;
			tmp = tmp1;
		}
		a[i] = tmp;
	}
	for(auto i:a) cout << i << ' '; cout << '\n';
    return 0;
}
