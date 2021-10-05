#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <assert.h>

#define pii pair<int, int>
#define f first
#define s second
#define vipii vector<int, pair<int, int> >
#define ipii pair<int, pair<int, int> >

using namespace std;
typedef long long int ll;

const int N = int(1e5+1);

ll MOD = ll(1e9+7);

#define vi vector<int>
#define vii vector<vi >
#define pb push_back

int mx(int a, int b, int c) {
	return max(a,max(b,c));
}

typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		next = NULL;
	}
} ListNode;

ListNode* findMid(ListNode* a) {
	if(!a)
		return a;
	ListNode *fast, *slow;
	fast = a, slow = a;
	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int solve(ListNode* a, int b) {
	ListNode *mid = findMid(a), *tmp = a;
	while(tmp && b > 0)
		tmp = tmp->next, b--;
	cout << tmp->val << endl;
	while(tmp != mid && tmp)
		a = a->next, tmp = tmp->next;
	return tmp ? a->val : -1;
}

int main() {
	int n, m;
	cin >> n;
	ListNode *head, *tmp;
	head = tmp = NULL;
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		if(head == NULL)
			head = new ListNode(l), tmp = head;
		else {
			tmp->next = new ListNode(l);
			tmp = tmp->next;
		}
	}
	cin >> m;
	cout << solve(head, m) << '\n';
//	head = solve(head, m);
//	for(ListNode *i = head ; i != NULL ; i = i->next)
//		cout << i->val << ' ';
//	cout << '\n';
	return 0;
}

