int dp(int *nums,int numsSize,int prev,int index,int **memo){
    if(index>=numsSize)
        return 0;
    int take=0,skip=0;
    if(prev!=-1 && memo[prev][index]!=-1)
        return memo[prev][index];
    if(prev==-1 || nums[prev]<nums[index]){
        take=1+dp(nums,numsSize,index,index+1,memo);
    }
    skip=dp(nums,numsSize,prev,index+1,memo);
    if(prev!=-1){
    memo[prev][index]=fmax(take,skip);
    return memo[prev][index];
    }else{
        return fmax(take,skip);
    }
    
}
int lengthOfLIS(int* nums, int numsSize) {
    int **memo=(int**)malloc(numsSize*sizeof(int *));
    for(int i=0;i<numsSize;i++){ 
        memo[i] = (int*)malloc(numsSize * sizeof(int));
        for (int j = 0; j < numsSize; j++) {
            memo[i][j] = -1;
        }
    }
    return dp(nums,numsSize,-1,0,memo);
}
