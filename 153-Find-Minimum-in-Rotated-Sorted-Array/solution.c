int findMin(int* nums, int numsSize) {
    int i=0,j=numsSize-1, mid = (numsSize - 1)/2;
    while(i<=j) {
        if(mid == i) break;
        if(nums[i] < nums[j]) return nums[i];
        if(nums[mid] > nums[i]) {
            i = mid;
        }else if(nums[mid] < nums[i]) {
            j = mid;
        }
        mid = (i+j)/2;
    }
    return nums[i]>nums[j]?nums[j]:nums[i];
}