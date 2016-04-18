/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmpFunc(const void* a, const void* b) {
    return (*(int *)a - *(int *)b);
}
 

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i,j,k;
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    int **result = (int **)malloc(sizeof(int*));
    *returnSize = 0;
    for(i=0;i<numsSize;i++){
        if(i>=1 && nums[i-1] == nums[i]) continue;
        j=i+1;
        k=numsSize-1;
        while(j<k){
            if(nums[i] + nums[j] + nums[k] > 0) {
                k--;
            }else if(nums[i] + nums[j]+ nums[k] < 0){
                j++;
            }else{  //equal 
               *returnSize +=1;
               result = (int **)realloc(result, sizeof(int*)*(*returnSize));
               result[*returnSize - 1] = (int *)malloc(sizeof(int) * 3);
               result[*returnSize - 1][0] = nums[i];
               result[*returnSize - 1][1] = nums[j];
               result[*returnSize - 1][2] = nums[k];
               j++;
               k--;
               while(nums[j-1] == nums[j]) j++;
               while(nums[k] == nums[k+1]) k--;
            }
        }
    }
    return result;
}

