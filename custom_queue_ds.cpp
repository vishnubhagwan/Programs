#include <iostream>
#include <vector>
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define N int(1e6)
#define MIN -int(1e9)
#define MAX int(1e9)


// implement queue using stacks, use custom stack DS not library DS

class Stack {
	private:
		vector<int> stack;
	public:
		bool empty() {
			if(stack.size() > 0)
				return false;
			return true;
		}
		int top() {
			if(stack.empty())
				return -1;
			return stack[stack.size()-1];
		}
		int pop() {
			if(stack.size() == 0)
				return -1;
			int num = stack[stack.size() - 1];
			stack.pop_back();
			return num;
		}
		void push(int val) {
			stack.push_back(val);
			return;
		}
};

class Queue {
	private:
		Stack stack1, stack2;
	public:
		void push(int val) {
			while(!stack1.empty()) {
				stack2.push(stack1.pop());
			}
			stack1.push(val);
			while(!stack2.empty())
				stack1.push(stack2.pop());
			return;
		}
		int front() {
			return stack1.top();
		}
		int pop() {
			return stack1.pop();
		}
		bool empty() {
			if(stack1.empty())
				return true;
			return false;
		}
};

int main()
{
	clock_t beg = clock();
	fast_io;
	int t;
	cin >> t;
	Queue queue;
	while(t--) {
		char c;
		int n;
		cin >> c;
		if(c == 'e') {
			cin >> n;
			queue.push(n);
		}
		else if(c == 'd')
			cout << queue.pop() << '\n';
	}
	clock_t end = clock();
	fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
	return 0;
}
