int cmpFunc(const void* a, const void* b) {
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i=0;
    int minDiff=INT_MAX;
    int resultTarget = nums[0]+ nums[1]+ nums[numsSize -1];
    
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    for(int i=0;i<numsSize;i++) {
        int j = i+1;
        int k = numsSize - 1;
        while(j < k){
           int sum = nums[i] + nums[j] + nums[k];
           int diff = sum - target;
           if(diff == 0) {return target;}
           if(abs(diff)< minDiff){
               minDiff = abs(diff);
               resultTarget = sum;
           }
           
           if(diff > 0) {
               k--;
           }else if(diff<0){
               j++;
           }
        }
    }
    return resultTarget;
}