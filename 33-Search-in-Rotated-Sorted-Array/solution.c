int search(int* nums, int numsSize, int target) {
    int i=0, j=numsSize-1, mid = (numsSize-1)/2;
    while(i<=j) {
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] >= nums[i]) {
            if(target > nums[mid]) {
                i = mid + 1;
            }else{
                if(target<nums[i]) {
                    i = mid +1;
                }else{
                    j = mid -1;
                }
            }
        }else{
            if(target<nums[mid]) {
                j = mid -1;
            }else{
                if(target>=nums[i]){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }
        }
        mid = (i+j)/2;
    }
    return -1;
}