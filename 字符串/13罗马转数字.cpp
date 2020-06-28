13. 罗马数字转整数
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> a={
            {'M',1000},

            {'D',500},

            {'C',100},

            {'L',50},

            {'X',10},

            {'V',5},

            {'I',1}
            };
        int ans=0;
        for(int i=0;i<s.size();++i){
            if(i<s.size()-1 && a[s[i]]<a[s[i+1]]){
                ans-=a[s[i]];
            }
            else{
                ans+=a[s[i]];
            }
        }
        return ans;
    }
};