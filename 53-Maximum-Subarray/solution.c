int maxSubArray(int* nums, int numsSize) {
     int sums = 0,i = 0;
     int max = INT_MIN;
     for(i=0;i<numsSize;i++) {
         sums += nums[i];
         if(sums>max) {
             max = sums;
         }
         if(sums < 0) {
             sums = 0;
         }
     }
     return max;
}