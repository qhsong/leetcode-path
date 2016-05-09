/* O(n^2) result is TLE, 
int removeDuplicates(int* nums, int numsSize) {
    int i,j;
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize && nums[i]==nums[j];j++);
        if(j==i+1) continue;
        int diff = j - i - 1;
        for(;j<numsSize;j++){
            nums[j-diff] = nums[j];
        }
        numsSize -= diff;
    }
    return numsSize;
}
*/
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    int i,j;
    i=j=1;
    int resultCount = 1;
    while(j<numsSize){
        if(nums[j-1]!=nums[j]){
            nums[i] = nums[j];
            i++;
            resultCount++;
        }
        j++;
    }
    return resultCount;
}