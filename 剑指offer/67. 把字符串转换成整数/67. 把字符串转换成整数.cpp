class Solution {
public:
    int strToInt(string str) {
        int flag=1;
        long res=0;
        int i=0;
        while(str[i]==' ')i++; //首先去除空格
        if(!isdigit(str[i])&&str[i]!='+'&&str[i]!='-')//然后判断第一个非空格的字符是否为正负号或者数字
            return 0;
        if(str[i]=='-'){				//处理正负号
                flag=-1;
                i++;
        }
        else if(str[i]=='+')i++;
        
        while(isdigit(str[i])){	//累加
            res=res*10+str[i]-'0';
            if(flag==1&&res>INT_MAX){//判断越界
                return INT_MAX;
            }         
            else if(flag==-1&&-res<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return flag*res;
    }
};