bool isPalindrome(int x) {
    int number = x;
    if(x<0) return false;
    if(abs(x)>=0 && abs(x)< 10) return true;
    int count = 0;
    while(number != 0){
        number /= 10;
        count++;
    }
    
    int i=0;
    for(i=0;i<count/2 ;i++) {
        printf("%d, %d|", x,x/((int)pow(10,(count-1-2*i))));
        if(x%10 != x/((int)pow(10,(count-1-2*i)))){
            return false;
        }
        x = x - x/((int)pow(10,(count-1-2*i))) * ((int)pow(10,(count-1-2*i)));
        x /= 10;
    }
    return true;
}