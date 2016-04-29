int maxArea(int* height, int heightSize) {
    int i=0, j=heightSize-1;
    int max = (height[0]>height[heightSize-1]?height[heightSize-1]:height[0]) * (heightSize-1), imax = 0, jmax= heightSize-1;
    while(i<j){
        height[i]>height[j]?j--:i++;
        int size = (height[i]>height[j]?height[j]:height[i])*(j-i);
        max = size>max?size:max;
        printf("%d|",max);
    }
    return max;
}