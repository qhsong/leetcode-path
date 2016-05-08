/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
void generatorParenthesisHelper(char *s, int leftBracket, int rightBracket, int n, char ***resultPoint, int *returnSize) {
    int i;
    //printf("%d,%d,%s|",leftBracket, rightBracket,s);
    char **result = *resultPoint;
    if(leftBracket == n){
        *resultPoint = (char **)realloc(*resultPoint, sizeof(char *) * (*returnSize + 1));
        char *tmpStr = (char *)malloc(sizeof(char)* (2*n + 1));
        strcpy(tmpStr, s);
        int len = strlen(s);
        for(i=len;i<2*n;i++){
            tmpStr[i] = ')';
        }
        tmpStr[2*n] = '\0';
        (*resultPoint)[*returnSize] = tmpStr;
        (*returnSize)++;
        return;
    }
    if(leftBracket < n){
        int len = strlen(s);
        s = (char *)realloc(s, (len+2)* sizeof(char));
        s[len] = '(';
        s[len+1] = '\0';
        generatorParenthesisHelper(s, leftBracket+1, rightBracket, n, resultPoint, returnSize);
        if(leftBracket > rightBracket){
            s[len] = ')';
            s[len+1] = '\0';
            generatorParenthesisHelper(s, leftBracket, rightBracket+1, n , resultPoint, returnSize);
        }
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    if(n==0){
        return NULL;
    }
    char *s = (char *)malloc(sizeof(char) * 2);
    s[0] = '(';
    s[1] = '\0';
    char **result=NULL;
    generatorParenthesisHelper(s, 1, 0, n, &result, returnSize);
    printf("%d|", result);
    return result;
}