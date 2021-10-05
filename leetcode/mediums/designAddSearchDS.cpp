class WordDictionary {
public:
    vector<WordDictionary*> W;
    bool end = false;
    /** Initialize your data structure here. */
    WordDictionary() {
        W.clear();
        W.resize(26);
    }
    
    int ord(char c) {
        return c-'a';
    }
    
    int chr(int c) {
        return c+'a';
    }
    
    void addWord(string word) {
        int n = word.size();
        WordDictionary* tmp = this;
        for(int i = 0 ; i < n ; i++) {
            int c = ord(word[i]);
            if(!tmp->W[c])
                tmp->W[c] = new WordDictionary();
            tmp = tmp->W[c];
        }
        tmp->end = true;
    }
    
    bool searchUtil(WordDictionary* root, string s, int start) {
        if(start == s.size())
            return root->end;
        bool ok = false;
        if(s[start] == '.')
            for(int i = 0 ; i < 26 ; i++)
                if(root->W[i])
                    ok |= searchUtil(root->W[i], s, start+1);
        if(s[start] == '.')
            return ok;
        int c = ord(s[start]);
        if(root->W[c])
            return searchUtil(root->W[c], s, start+1);
        else return false;
    }
    
    bool search(string word) {
        int n = word.size();
        return searchUtil(this,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
