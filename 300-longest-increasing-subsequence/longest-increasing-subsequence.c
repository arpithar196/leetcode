int binarySearch(int* res,int size,int target){
    int low=0;
    int right=size-1;
    while(low<=right){
        int mid=(low+right)/2;
        if(res[mid]==target){
            return mid;
        } else if(res[mid]<target){
            low=mid+1;
        } else{
            right=mid-1;
        }
    }
    return low;
}
int lengthOfLIS(int* nums, int numsSize) {
    int size=0;
    int* res=(int*)malloc(numsSize*sizeof(int));
    res[0]=nums[0];
    for(int i=1;i<numsSize;i++){
        if(res[size]<nums[i]){
            res[++size]=nums[i];
        } else{
            int index=binarySearch(res,size+1,nums[i]);
            res[index]=nums[i];
        }
    }
    return size+1;
}