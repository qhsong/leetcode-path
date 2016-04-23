int lengthOfLongestSubstring(char* s) {
    //sliding windows
    int i,len= strlen(s);
    int maxLen = 1,start = 0,current=1;
    if(len == 0) return 0;
    for(i = 1;i<len;i++) {
        int j,flag=0;
        for(j=i-1; j>=start;j--){
            if(s[j] == s[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            current++;
        }else{
            start = j+1;
            current = i-start+1;
        }
        
        if(current > maxLen){
            maxLen = current;
        }
    }
    return maxLen;
}