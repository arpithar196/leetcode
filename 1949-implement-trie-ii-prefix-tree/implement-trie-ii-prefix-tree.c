


typedef struct T{
    struct T* child[26];
    bool isLeaf;
    int count;
    int wordcount;
} Trie;


Trie* trieCreate() {
    Trie* t=(Trie*)malloc(sizeof(Trie));
    for(int i=0;i<26;i++){
        t->child[i]=NULL;
    }
    t->count=0;
    t->wordcount=0;
    t->isLeaf=false;
    return t;
}

void trieInsert(Trie* obj, char* word) {
    for(int i=0;i<strlen(word);i++){
        if(obj->child[word[i]-'a']==NULL){
            obj->child[word[i]-'a']=trieCreate();
        } 
            obj->child[word[i]-'a']->count++;
            obj=obj->child[word[i]-'a'];
        
    }
    obj->wordcount++;
    obj->isLeaf=true;
}

int trieCountWordsEqualTo(Trie* obj, char* word) {
    for(int i=0;i<strlen(word);i++){
        if(obj->child[word[i]-'a']==NULL)
            return 0;
        obj=obj->child[word[i]-'a'];
    }   
    return obj->wordcount;
}

int trieCountWordsStartingWith(Trie* obj, char* word) {
    for(int i=0;i<strlen(word);i++){
        if(obj->child[word[i]-'a']==NULL)
            return 0;
        obj=obj->child[word[i]-'a'];
    }   
    return obj->count;
}

void trieErase(Trie* obj, char* word) {
    for(int i=0;i<strlen(word);i++){
        if(obj->child[word[i]-'a']==NULL)
            return ;
      
        obj=obj->child[word[i]-'a'];
          obj->count--;
    }  
    obj->wordcount--;
    if (obj->wordcount == 0) {
        obj->isLeaf = false;
    }
    
}

void trieFree(Trie* obj) {
    for(int i = 0; i <26; i++){
        if(obj->child[i] == NULL)
            continue;
        trieFree(obj->child[i]);
    }   
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * int param_2 = trieCountWordsEqualTo(obj, word);
 
 * int param_3 = trieCountWordsStartingWith(obj, prefix);
 
 * trieErase(obj, word);
 
 * trieFree(obj);
*/