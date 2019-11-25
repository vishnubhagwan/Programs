// Painters Partition Problem - Google interviews question
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#define f first
// #define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e18+1)
#define N int(1e6+1)

bool checkPartition(vector<int> a, int m, int k) {
	int n = a.size(), s = 0;
	for(int i = 0 ; i < n ; i++) {
		if(s + a[i] > m)
			k--, s = a[i];
		else
			s += a[i];
		if(k < 0)
			return true;
	}
	return k == 0;
}

void findAns(vector<int> a, int k) {
	int n = a.size();
	int l=1, h=n;
	while(l < h) {
		int m = (l+h)>>1;
		if(checkPartition(a, m, k))
			l = m+1;
		else h = m;
	}
	cout << l << '\n';
	return;
}

int main() {
	int n,k;
	vector<int> a = {1, 2, 4, 7, 3, 6, 9};
	k = 4;
	findAns(a, k);
	return 0;
}
