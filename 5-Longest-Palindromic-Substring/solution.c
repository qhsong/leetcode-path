char* longestPalindrome(char* s) {
    int i;
    int len = strlen(s);
    int maxLen=0, start=0,maxStart=0;
    if(len == 0) return NULL;
    if(len == 1) return s;
    for(i=0;i<len;i++){
       int j, count=0;
       //Odd
       for(j=0;i-j>=0 && i+j<len ;j++){
           if(s[i-j] == s[i+j]) {
                count=2*j+1;
                start = i-j;
           }else{
               break;
           }
       }
       if(count>maxLen){
           maxLen = count;
           maxStart = start;
       }
       
       count = 0;
       if(s[i] == s[i+1]){  //Oven
            for(j=0;i-j>=0&&i+j<len;j++){
                if(s[i-j] == s[i+j+1]){
                    count= 2*(j+1);
                    start = i-j;
                }else{
                    break;
                }
            }
            if(count>maxLen){
                maxLen = count;
                maxStart = start;
            }
       }
    }
    
    printf("%d|%d", maxLen,maxStart);
    char *result = (char *)malloc(sizeof(char) * maxLen + 1);
    for(i=0;i<maxLen;i++){
        result[i] = s[i+maxStart];
    }
    result[maxLen] = '\0';
    return result;
}