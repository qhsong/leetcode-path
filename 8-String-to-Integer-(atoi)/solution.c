enum STATUS {ST_START, ST_FLAG, ST_NUMBER};

//"-2147483648","-0","   -+2", "   -0000 12","-0013a34","    -00134","MAX_INT","MIN_INT"
int myAtoi(char* str) {
    int result = 0, i, flag = 0;
    int len = strlen(str);
    enum STATUS st= ST_START;
    int tmp=0;
    for(i=0; i<len;i++){
        switch (st){
            case ST_START:
                if(str[i] == ' '){continue;}
                else if(str[i] == '+') {st = ST_FLAG;}
                else if(str[i] == '-') {st = ST_FLAG;flag = 1;}
                else if(str[i]>='0' && str[i]<='9'){
                    st = ST_NUMBER;
                    result += str[i]-'0';
                    if(flag == 1){result= -result;flag=0;}
                }
                else{return 0;}
            break;
            case ST_FLAG:
                if(str[i] >='0' && str[i]<='9'){
                    st = ST_NUMBER; 
                    result += str[i]-'0';
                    printf("%d,%c,%d|", result,str[i],result);
                    if(flag==1&&result!=0) {result = -result;flag = 0;}
                }
                else{return 0;}
            break;
            case ST_NUMBER:
                if(str[i] >='0' && str[i]<='9'){
                    tmp = result;
                    result *=10;
                    if(result>=0){
                        result += str[i]-'0';
                    }else{
                        result -= (str[i] -'0');
                    }
                    if(flag==1&&result!=0) {result = -result;flag = 0;}
                    printf("%d,%c,%d|", result,str[i],result);
                    if(result/10 != tmp){
                        if(tmp>0) return INT_MAX;
                        return INT_MIN;
                    }
                }else{return result;}
        }
    }
    return result;
}