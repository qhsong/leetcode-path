char* intToRoman(int num) {
    char s[][2] = {
        {'I', 'V'},
        {'X','L'},
        {'C', 'D'},
        {'M', '\0'},
    };
    
    int count = 0;
    int tmp = num;
    int i=0;
    char *result = (char *)malloc(100*sizeof(char));
    while(num!= 0) {
        int digit = num %10;
        if(digit>0 && digit<=3){
            int j=0;
            for(j=0;j<digit;j++){
                result[++count] = s[i][0];
            }
        }else if(digit == 4){
            result[++count] = s[i][1];
            result[++count] = s[i][0];
        }else if(digit>=5 && digit<=8){
            int j;
            for(j=digit-5;j>0;j--){
                result[++count] = s[i][0];
            }
            result[++count]= s[i][1];
        }else if(digit==9){
            result[++count] = s[i+1][0];
            result[++count] = s[i][0];
        }
        num /= 10;
        i++;
    }
    
    result[++count] = '\0';
    printf("%s", result);
    //reverse array
    for(i=0;i<count/2;i++){
        char ctmp = result[i];
        result[i] = result[count-i-1];
        result[count-i-1] = ctmp;
    }
    
    return result;
}