// Find a triplet that sum to a given value
#include<iostream>
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
#define N int(1e3+1)

vector<int> a;
const int THREADS = 10;
pthread_mutex_t lck;

struct param {
	int l,r;
	param(int l, int r): l(l), r(r) {}
};

void merge(int l, int r) {
	int m = (l+r)>>1;
	int i, j;
	i = 0, j = m+1;
	vector<int> c;
	while(i <= m && j <= r) {
		if(a[i] <= a[j])
			c.pb(a[i++]);
		else
			c.pb(a[j++]);
	}
	while(i <= m)
		c.pb(a[i++]);
	while(j <= r)
		c.pb(a[j++]);
	for(int i = l ; i <= r ; i++)
		a[i] = c[i-l];
	return;
}

// void* msort(void* q) {
void msort(int l, int r) {
	// param* p = (param*) q;
	// int l = p->l, r = p->r;
	if(l >= r)
		// return NULL;
		return;
	int m = (l+r)>>1;
	// pthread_t p1, p2;
	// pthread_create(&p1, NULL, msort, (void*) new param(l,m));
	// pthread_create(&p2, NULL, msort, (void*) new param(m+1,r));
	// pthread_join(p1, NULL);
	// pthread_join(p2, NULL);
	// msort((void*) new param(l,m));
	// msort((void*) new param(m+1,r));
	msort(l,m);
	msort(m+1,r);
	merge(l,r);
	// return NULL;
	return;
}

void* merge_sort(void*) {
	static int cnt = 0;
	int n = a.size();
	pthread_mutex_lock(&lck);
	int l = n*cnt/THREADS + (cnt != 0);
	int r = n*(cnt+1)/THREADS - (cnt == THREADS);
	cnt++;
	pthread_mutex_unlock(&lck);
	msort(l, r);
	return NULL;
}

int main() {
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		a.pb(l);
	}
	pthread_t t[THREADS] = {0};
	pthread_mutex_init(&lck, NULL);
	for(int i = 0 ; i < THREADS ; i++)
		pthread_create(&t[i], NULL, merge_sort, (void*) NULL);
	for(int i = 0 ; i < THREADS ; i++)
		pthread_join(t[i], NULL);
	pthread_mutex_destroy(&lck);

	// msort((void*) new param(0,n-1));
	for(auto i:a) cout << i << ' '; cout << '\n';
    return 0;
}
