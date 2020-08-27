class Solution {
public:
    int translateNum(int num) {
        if(num<0) return 0;
        string numberInString=to_string(num);
        return GetTranslationCount(numberInString);
    }
    
    int GetTranslationCount(const string& number){
        int length=number.size();
        int* counts=new int[length];
        int count=0;
        for(int i=length-1;i>=0;--i){
            count=0;
            if(i<length-1){
                count=counts[i+1];
            }
            else{
                count=1;
            }
            if(i<length-1){
                int digit1=number[i]-'0';
                int digit2=number[i+1]-'0';
                int converted=digit1*10+digit2;
                if(converted>=10&&converted<=25){
                    if(i<length-2){
                        count+=counts[i+2];
                    }
                    else{
                        count+=1;
                    }
                }
            }
            counts[i]=count;
        }
        count=counts[0];
        delete[] counts;
        return count;

    }
};

//-------------dp-----------------------

class Solution
{
public:
    int translateNum(int num) {
        string num_str=to_string(num);
        int n=num_str.size();
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;++i){
            if(num_str[i-2]=='1'||(num_str[i-2]=='2'&&num_str[i-1]<'6')){
                dp[i]=dp[i-2]+dp[i-1];
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[n];
    }
    
};


// -----------------递归backtrace-------------------------
class Solution {
public:
    int backtrack(string& s, int idx){
        int n = s.size();
        if(idx == n) return 1;
        if(idx == n - 1 || s[idx] == '0' || s.substr(idx, 2) > "25")
            return backtrack(s, idx + 1);
        return backtrack(s, idx + 1) + backtrack(s, idx + 2);
    }
    int translateNum(int num) {
        string s = to_string(num);
        return backtrack(s, 0);
    }
};

