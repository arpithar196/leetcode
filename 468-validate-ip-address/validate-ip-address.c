bool isipv4(char* ip,bool first){
    int len=strlen(ip);
    if(len==0 || len>3)
        return false;
    for(int i=0;i<len;i++){
        if(!isdigit(ip[i]))
            return false;
    }
        if (len > 1 && ip[0] == '0') return false;
            //return false;
    int val=atoi(ip);
    if(val>=0 && val<=255)
        return true;
    else
        return false;
}
bool isipv6 (char*ip){
    int len=strlen(ip);
    if(len==0 || len>4)
        return false;
    for(int i=0;i<len;i++){
        if(!isxdigit(ip[i]))
            return false;
    }
    return true;
}

char* validIPAddress(char* queryIP) {
 char* result=(char*) malloc(10*sizeof(char));
  int dotCount=0;
  int colon=0;
  int count=0;
  if(strlen(queryIP)> 4*4*7){
        strcpy(result,"Neither");
        return result;
  }
  for(int i=0;i<strlen(queryIP);i++){
    if(queryIP[i]=='.')
        dotCount++;
    if(queryIP[i]==':')
        colon++;
  }  
//   if(dotCount>3 || colon >7)
//     return false;
  if(dotCount == 3){
    char ip[100];
    strcpy(ip,queryIP);
    bool first=true;
    char * token=strtok(ip,".");
    while(token){
        if(!isipv4(token,first)){
            first=false;
            strcpy(result,"Neither");
            return result;
        }
        first=false;
        count++;
        token=strtok(NULL,".");
    }
    if(count==4){
        strcpy(result,"IPv4");
        return result;
    }
    

  }
  if(colon == 7){
    char ip[100];
    strcpy(ip,queryIP);
    char * token=strtok(ip,":");
    while(token){
        if(!isipv6(token)){
            strcpy(result,"Neither");
            return result;
        }
        count++;
        token=strtok(NULL,":");
    }
    if(count==8){
        strcpy(result,"IPv6");
        return result;
    }
  }
    strcpy(result,"Neither");
        return result;
    

  }
