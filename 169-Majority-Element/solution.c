int majorityElement(int* nums, int numsSize) {
    int cadidate=0, count=0;
    int i;
    for(i=0;i<numsSize;i++) {
        if(count ==0) {
            cadidate = nums[i];
            count++;
        }else{
            if(cadidate != nums[i]){
                count--;
            }else{
                count++;
            }
        }
    }
    return cadidate;
}