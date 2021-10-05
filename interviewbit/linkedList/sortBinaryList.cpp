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

ListNode* solve(ListNode* a) {
	ListNode *ones, *zeros, *onesHead, *zerosHead;
	ones = new ListNode(1);
	zeros = new ListNode(0);
	onesHead = ones;
	zerosHead = zeros;
	ListNode* pre = new ListNode(-1);
	pre->next = a;
	while(a) {
		ListNode* next = a->next;
		if(a->val == 0) {
			zeros->next = a;
			pre->next = a->next;
			a->next = NULL;
			zeros = zeros->next;
		}
		else {
			ones->next = a;
			pre->next = a->next;
			a->next = NULL;
			ones = ones->next;
		}
		a = next;
	}
	zeros->next = onesHead->next;
	return zerosHead->next;
}

int main() {
	int n;
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
	head = solve(head);
	for(ListNode *i = head ; i != NULL ; i = i->next)
		cout << i->val << ' ';
	cout << '\n';
	return 0;
}

