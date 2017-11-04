#include<bits/stdc++.h>
using namespace std;
class LRUCache{
private:
	map<int, list<int>::iterator> m;
	unordered_map<int, int> t;
	list<int> L;
	int n;
public:
    LRUCache(int capacity) {
	    n = capacity;
	    m.clear();
	    t.clear();
	    L.clear();
    }

    int get(int key) {
	    if(t.count(key)) {
	        L.push_front(key);
	        L.erase(m[key]);
	        m[key] = L.begin();
	        return t[key];
	    }
	    return -1;
    }

    void set(int key, int value) {
	    if(L.size() == n && !t.count(key)) {
	        int v = L.back();
	        m.erase(v);
	        t.erase(v);
	        L.pop_back();
	    }
	    if(t.count(key)) L.erase(m[key]);
	    L.push_front(key);
	    m[key] = L.begin();
	    t[key] = value;
	    return;
    }
};

int main() {
	int k,c;
	cin >> k >> c;
	LRUCache lru = LRUCache(c);
	while(k--) {
		string s;
		int t,v;
		cin >> s >> t;
		if(s == "S") {
			cin >> v;
			lru.set(t,v);
		}
		else cout << lru.get(t) << '\n';
	}
	return 0;
}