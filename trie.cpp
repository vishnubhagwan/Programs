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
#define vi vector<int>
#define sort(v) sort(all(v))
#define fo(i,m,n) for(auto i = m ; i < n ; i++)
#define rep(i,n) fo(i,0,n)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pqueue priority_queue<int,vector<int>, greater<int> >
#define sz(s) s.size()
#define trace(a) {for(auto i:a) cout << i << ' '; cout << '\n';}
#define out(a) cout << a << '\n'
#define set(a) memset(a,0,sizeof(a))
#define si(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define pi(n) printf("%d\n",n)
#define sm(n,m) scanf("%lld%lld",&n,&m)
#define pm(n,m) printf("%lld %lld\n",n,m)
typedef long long int ll;
typedef pair<int, int> ii;

struct TriNode
{
	int val;
	TriNode* arr[2];
};

TriNode* newNode()
{
	TriNode* tmp = new TriNode;
	tmp -> val = 0, tmp -> arr[0] = tmp -> arr[1] = NULL;
	return tmp;
}

void insert(TriNode* root, int k, int level = 32)
{
	if(level == -1)
	{
		root -> val = k;
		return;
	}
	bool v = level&k;
	if(root -> arr[v] == NULL)
		root -> arr[v] = newNode();
	else insert(root -> arr[v], k, level - 1);
	return;
}

int q(TriNode* root, int k, int level = 32)
{
	if(level == -1)
		return root -> val;
	bool v = level&k;
	if(root -> arr[1-v] != NULL)
		return q(root -> arr[1-v], k, level - 1);
	else if(root -> arr[v] != NULL)
		return q(root -> arr[v], k, level - 1);
}

int main()
{
	TriNode* root = newNode();
	
	return 0;
}
