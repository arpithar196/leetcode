int firstUniqChar(char* s) {
    int hash[256];
     bzero(&hash, sizeof(hash));
    for(int i=0;i<strlen(s);i++){
        hash[s[i]]++;
    }   
    for(int i=0;i<strlen(s);i++){
        if(hash[s[i]]==1)
            return i;
    }
    return -1;
}