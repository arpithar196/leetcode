


typedef struct T {
    struct T *child[26];
    bool isLeaf;
} Trie;


Trie* trieCreate() {
    Trie* t=(Trie*)malloc(sizeof(Trie));
    for(int i=0;i<26;i++){
        t->child[i]=NULL;
    }
    t->isLeaf=false;
    return t;
}

void trieInsert(Trie* obj, char* word) {
    int i=0;

    while(word[i]!='\0'){
        if(obj->child[word[i]-'a']==NULL){
            obj->child[word[i]-'a']=trieCreate();
        }
        obj=obj->child[word[i]-'a'];
        i++;
    }
    obj->isLeaf=true;
}

bool trieSearch(Trie* obj, char* word) {
    if(obj==NULL)
        return false;
    for(int i=0;i<strlen(word);i++){
        if(obj->child[word[i]-'a']==NULL)
            return false;
        obj=obj->child[word[i]-'a']; 
    }
    return obj->isLeaf;
}

bool trieStartsWith(Trie* obj, char* word) {
    for(int i=0;i<strlen(word);i++){
        if(obj->child[word[i]-'a']==NULL)
            return false;
        obj=obj->child[word[i]-'a']; 
    }
    return true;
}

void trieFree(Trie* obj) {
    for(int i=0;i<26;i++){
        if(obj->child[i]){
            free(obj->child[i]);
        }
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/