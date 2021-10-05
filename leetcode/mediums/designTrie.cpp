class Trie {
public:
    unordered_map<int, Trie*> T;
    bool end = false;
    
    int ord(char c) {
        return c-'a';
    }
    
    int chr(int c) {
        return char(c+'a');
    }

    /** Initialize your data structure here. */
    Trie() {
        T.clear();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        Trie* tmp = this;
        for(char ch : word) {
            int c = ord(ch);
            if(!tmp->T[c])
                tmp->T[c] = new Trie();
            tmp = tmp->T[c];
        }
        tmp->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        Trie* tmp = this;
        for(char ch : word) {
            int c = ord(ch);
            if(!tmp->T[c])
                return false;
            tmp = tmp->T[c];
        }
        return tmp->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        Trie* tmp = this;
        for(char ch : prefix) {
            int c = ord(ch);
            if(!tmp->T[c])
                return false;
            tmp = tmp->T[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
