char* longestCommonPrefix(char** strs, int strsSize) {
    int count = 0;
    int i=0;
    if(strsSize==0) return "";
    if(strsSize == 1) return strs[0];
    while(1){
        int sameFlag = 0;
        for(i=1;i<strsSize;i++){
            if(strs[i-1][count]=='\0'||strs[i][count]=='\0'||strs[i][count]!= strs[i-1][count]) {
                sameFlag = 1;
                break;
            }
        }
        if(sameFlag == 1){
            break;
        }
        count++;
    }
    
    char *result = (char *)malloc(sizeof(char) * (count+1));
    for(i=0;i<count;i++){
        result[i] = strs[0][i];
    }
    result[count] = '\0';
    return result;
}