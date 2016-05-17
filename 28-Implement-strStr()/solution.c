int strStr(char* haystack, char* needle) {
    int i,j=0;
    int last = 0;
    if(strlen(haystack)==0 && strlen(needle)==0) return 0;
    
    for(i=0;i<strlen(haystack);i++) {
        if(j<strlen(needle) && haystack[i] == needle[j]){
            if(j==0) last = i;
            j++;
        }else if(j == strlen(needle)){
            return last;
        }else if(j!=0 && haystack[i] != needle[j]) {
            j=0;
            i=last;
        }
    }
    if(j!=0 && j==strlen(needle)) {
        return last;
    }
    
    return -1;
}