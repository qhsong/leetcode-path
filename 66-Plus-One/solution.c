/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    int carry=0;
    int tmp = digits[digitsSize -1 ];
    *returnSize = digitsSize;
    digits[digitsSize -1] = (tmp + 1) % 10;
    carry = (tmp+1)/10;
    
    for(i=digitsSize -2;i>=0 && carry != 0;i--) {
        tmp = digits[i];
        digits[i] = (tmp + carry) %10;
        carry = (tmp + carry)/10;
    }
    
    if(carry != 0){
        *returnSize += 1;
        digits = (int *)realloc(digits, sizeof(int)* (*returnSize));
        digits[0] = carry;
    }
    return digits;
}