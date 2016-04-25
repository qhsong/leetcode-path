int reverse(int x) {
    int result = 0;
    int tmp = 0;
    int flag = 0;
    if(x < 0){
        flag = 1;
        x = -x;
    }
    
    while(x !=0){
        result *= 10;
        result += (x % 10);
        if((result/10) != tmp) return 0;    //overflow
        x /= 10;
        tmp = result;
    }
    
    if(flag == 1){
        return -result;
    }
    
    return result;
}