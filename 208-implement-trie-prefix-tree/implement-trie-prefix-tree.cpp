class Trie {
public:
    vector<string> trie;
    Trie() {
        
    }
    
    void insert(string word) {
        trie.push_back(word);
    }
    
    bool search(string word) {
        for(int i=0;i<trie.size();i++){
            if(trie[i]== word)
                return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for(int i=0;i<trie.size();i++){
            if(trie[i].starts_with(prefix))
                return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */