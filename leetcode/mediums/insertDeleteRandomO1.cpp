class RandomizedSet {
public:
    int sz;
    vector<int> V;
    unordered_map<int, int> M;
    /** Initialize your data structure here. */
    RandomizedSet() {
        M.clear();
        V.clear();
        sz = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(M.count(val))
            return false;
        int increase = 0;
        if(V.size() == 0 || V.size() <= sz)
            V.push_back(val);
        else
            V[sz] = val;
        M[val] = sz;
        sz++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!M.count(val)) return false;
        int value = M[val];
        int key = V[sz-1];
        swap(V[M[val]], V[sz-1]);
        M.erase(val);
        if(val != key)
            M[key] = value;
        sz--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        assert(sz > 0);
        return V[rand()%sz];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
