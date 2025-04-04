/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** res=(char**)malloc((n)*sizeof(char *));
    for(int i=1;i<=n;i++){
        if(i%3==0 && i%5==0){
        res[i-1]=(char *)malloc(8*sizeof(char));
        res[i-1]="FizzBuzz";
        }
        else if(i%3==0){
        res[i-1]=(char *)malloc(4*sizeof(char));
        res[i-1]="Fizz";
        }
        else if( i%5 ==0){
        res[i-1]=(char *)malloc(4*sizeof(char));
        res[i-1]="Buzz";
        }
        else{
        res[i-1]=(char *)malloc(12*sizeof(char));
        // Enough to hold any 32-bit int including sign and null terminator
        snprintf(res[i-1],12,"%d",i);
        }

    }
    *returnSize=n;
    return res;
}