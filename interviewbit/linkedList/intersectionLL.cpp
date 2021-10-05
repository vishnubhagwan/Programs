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

void trace(ListNode* a) {
	if(a == NULL) {
		cout << '\n';
		return;
	}
	cout << a->val << ' ';
	trace(a->next);
}

ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
	int l1 = 0, l2 = 0;
	ListNode *tmpA, *tmpB;
	tmpA = a;
	tmpB = b;
	while(tmpA) tmpA = tmpA->next, l1++;
	while(tmpB) tmpB = tmpB->next, l2++;
	int l = 0;
	if(l1 > l2) {
		l = l1-l2;
		tmpA = a;
		while(l--)
			tmpA = tmpA->next;
	}
	else {
		l = l2-l1;
		tmpB = b;
		while(l--)
			tmpB = tmpB->next;
	}
	while(tmpA != tmpB && tmpA && tmpB)
		tmpA = tmpA->next, tmpB = tmpB->next;
	return tmpA;
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
	ListNode* head = getIntersectionNode(a,b);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

