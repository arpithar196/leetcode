int firstUniqChar(char* s) {
    int hash[256]={0};
    int len=strlen(s);
    // bzero(&hash, sizeof(hash));
    for(int i=0;i<len;i++){
        hash[s[i]]++;
    }   
    for(int i=0;i<len;i++){
        if(hash[s[i]]==1)
            return i;
    }
    return -1;
}