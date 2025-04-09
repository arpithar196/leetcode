int myAtoi(char* s) {
    int i=0;
    long long ans=0;
    int sign=1;
    while(i<strlen(s) && s[i]==' '){
        i++;
    }
    if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
    else if(s[i]=='+'){
        i++;
    }
    while(s[i]){
        if(!isdigit(s[i]))
            return ans*sign;
        int val=s[i]-'0';

        ans=ans*10+val;
        if(ans>INT_MAX && sign==-1)
            return INT_MIN;
        if(ans>INT_MAX && sign==1)
            return INT_MAX;

        i++;
    }
    return ans*sign;
}