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

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
	ListNode *head, *tmp;
	tmp = head = NULL;
	while(a != NULL && b != NULL) {
		if(a->val == b->val) {
			if(head == NULL) {
				tmp = head = a;
				a = a->next;
				tmp->next = b;
				tmp = tmp->next;
			}
			else {
				tmp->next = a;
				tmp = tmp->next;
				a = a->next;
				tmp->next = b;
				tmp = tmp->next;
			}
			b = b->next;
		}
		else if(a->val <= b->val) {
			if(head == NULL)
				tmp = head = a;
			else {
				tmp->next = a;
				tmp = tmp->next;
			}
			a = a->next;
		}
		else {
			if(head == NULL)
				tmp = head = b;
			else {
				tmp->next = b;
				tmp = tmp->next;
			}
			b = b->next;
		}
	}
	while(a != NULL) {
		if(head == NULL)
			tmp = head = a;
		else {
			tmp->next = a;
			tmp = tmp->next;
		}
		a = a->next;
	}
	while(b != NULL) {
		if(head == NULL)
			tmp = head = b;
		else {
			tmp->next = b;
			tmp = tmp->next;
		}
		b = b->next;
	}
	return head;
}

int main() {
	int n,m;
	cin >> n >> m;
	ListNode *a,*b,*tmp;
	a = b = tmp = NULL;
	for(int i = 0 ; i < n ; i++) {
		int l;
		cin >> l;
		if(a == NULL) {
			a = new ListNode(l);
			tmp = a;
		}
		else {
			tmp->next = new ListNode(l);
			tmp = tmp->next;
		}
	}
	for(int i = 0 ; i < m ; i++) {
		int l;
		cin >> l;
		if(b == NULL) {
			b = new ListNode(l);
			tmp = b;
		}
		else {
			tmp->next = new ListNode(l);
			tmp = tmp->next;
		}
	}
	ListNode* head = mergeTwoLists(a,b);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

