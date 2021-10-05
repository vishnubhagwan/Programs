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

ListNode* removeNode(ListNode** tail) {
	ListNode *tmp = *tail;
	*tail = (*tail)->next;
	return tmp;
}

ListNode* insertionSortList(ListNode* a) {
	ListNode *tail = a;
	ListNode *head = new ListNode(0), *tmp;
	while(tail) {
		ListNode* pre = NULL;
		for(tmp = head ; tmp && tmp->val < tail->val ; tmp = tmp->next) pre = tmp;
		ListNode* c = removeNode(&tail);
		pre->next = c;
		c->next = tmp;
	}
	return head->next;
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
	head = insertionSortList(head);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

