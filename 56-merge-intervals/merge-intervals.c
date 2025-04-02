/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b){
    return *((int **)a)[0]-*((int **)b)[0];
 }
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int** res=(int **)malloc(intervalsSize*sizeof(int *));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    qsort(intervals,intervalsSize,sizeof(int*),cmp);
    //res[0]=intervals[0];
    int j=0;
    res[j] = (int*)malloc(2 * sizeof(int));
    res[j][0] = intervals[0][0];
    res[j][1] = intervals[0][1];
    *returnColumnSizes[j]=2;
    for(int i=1;i<intervalsSize;i++){
        if(res[j][1]>=intervals[i][0]){
            res[j][1]=fmax(res[j][1],intervals[i][1]);
        } else{
            j++;
            res[j] = (int*)malloc(2 * sizeof(int));
            res[j][0] = intervals[i][0];
            res[j][1] = intervals[i][1];
            (*returnColumnSizes)[j]=2;
        }
    }
    *returnSize=j+1;
    return res;
}