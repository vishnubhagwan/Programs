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

ListNode* reverse(ListNode* a) {
	if(!a || !a->next)
		return a;
	ListNode* tmp = reverse(a->next);
	a->next->next = a;
	a->next = NULL;
	return tmp;
}

ListNode* reverseList(ListNode* a, int b) {
	if(a == NULL || a->next == NULL)
		return a;
	int k = b;
	ListNode *prev=NULL, *curr=a, *next=NULL;
	while(k-- && curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr = prev;
	a->next = reverseList(next, b);
	return prev;
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
	head = reverseList(head, m);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}
