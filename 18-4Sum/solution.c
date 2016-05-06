/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
/* struct int_map_struct {
    int id;            /* we'll use this field as the key
    int flag;   
    UT_hash_handle hh; /* makes this structure hashable 
};

void add_number(struct int_map_struct **intNumber, int id) {
    struct int_map_struct *s=NULL;
    HASH_FIND_INT(*intNumber, &id, s);
    if(s==NULL){
        s = (struct int_map_struct *)malloc(sizeof(struct int_map_struct));
        s->id = id;
        s->flag = 1;
        HASH_ADD_INT(*intNumber, id, s); 
    }
}
*/

int cmpHelper(const void *i1, const void *i2) {
    return (*(int *)i1 - *(int *)i2);
}
 
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if(numsSize <=3){
        *returnSize = 0;
        return NULL;
    }
    int i;
    qsort(nums, numsSize, sizeof(int), cmpHelper);
    
    int **result = NULL;
    
    int j,k,l;
    i=0;
    while(i<numsSize - 3) {
        int l =numsSize - 1;
        while(l>=i+3){
            j = i+1;
            k = l-1;
            while(k>j){
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                //printf("%d,%d,%d,%d,%d|", *returnSize,i,j,k,l);
                int diff = target - sum;
                if(diff == 0){
                    *returnSize = *returnSize + 1;
                    result = (int **)realloc(result, sizeof(int *)*(*returnSize));
                    result[*returnSize - 1] = (int *)malloc(sizeof(int) * 4);
                    result[*returnSize - 1][0] = nums[i];
                    result[*returnSize - 1][1] = nums[j];
                    result[*returnSize - 1][2] = nums[k];
                    result[*returnSize - 1][3] = nums[l];
                    j++;
                    while(j<numsSize - 1 && nums[j]==nums[j-1]) j++;
                    k--;
                    while(k>=0 && nums[k]==nums[k+1]) k--;
                }else{
                    if(diff>0){
                        j++;
                    }else{
                        k--;
                    }
                }
            }
            l--;
            while(l>i&& nums[l]==nums[l+1]) l--;
        }
        i++;
        while(i<numsSize -3 && nums[i] == nums[i-1]) i++;
    }
    return result;
    
}