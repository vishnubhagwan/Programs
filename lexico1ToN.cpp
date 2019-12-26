// Print numbers from 1 to n in lexicographical order
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

void findAns(int n, int ans = 0) {
	if(ans > n) return;
	for(int i = 1 ; i < 10 ; i++) {
		ans++;
		if(ans <= n)
			cout << ans << '\n';
		findAns(n, ans*10);
	}
}

int main() {
	int n;
	cin >> n;
	findAns(n);
    return 0;
}
