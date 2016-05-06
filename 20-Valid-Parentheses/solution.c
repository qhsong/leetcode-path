bool isValid(char* s) {
    int n = strlen(s);
    char stack[n/2 + 1];
    int index = -1;
    
    while(*s != '\0') {
        if(*s == '(' || *s == '{' || *s== '[') {
            stack[index++] = *s;
        }else if(*s == ')' || *s=='}' || *s==']') {
            if(index<0) return false;
            char c = stack[--index];
            if(*s==')' && c!='('){
                return false;
            }else if(*s=='}' && c!= '{'){
                return false;
            }else if(*s==']' && c!= '[') {
                return false;
            }
        }
        s++;
    }
    if(index!= -1) return false;
    return true;
}