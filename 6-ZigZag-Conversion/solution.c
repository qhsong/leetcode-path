char* convert(char* s, int numRows) {
    int len = strlen(s);
    int i,j,index;
    if(numRows >=len || numRows == 1) return s;
    
    char *result = (char *)malloc(sizeof(char) * len + 1);
    int count = 0;
    for(i=0;i<len;i += (2*numRows-2)) {
        result[count] = s[i];
        count++;
    }
    for(i=1;i<numRows-1;i++){
        index=i;
        for(j=0;index<len;j++){
            result[count] = s[index];
            if(j%2 == 0){
                index += 2*(numRows - i - 1);
            }else{
                index += 2*i;
            }
            count++;
        }
    }
    for(i=numRows-1;i<len;){
        result[count] = s[i];
        i = i + 2*numRows-2;
        count++;
    }
    result[len] = '\0';
    return result;
}