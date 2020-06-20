/*
541. 反转字符串 II
给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。


示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        string ans;
        string cur;
        for(int i=0;i<s.size();i+=2*k){
            if(i+2*k<s.size()){
                cur=s.substr(i,2*k);
                ans+=myReverse(cur,0,k-1);
                continue;
            }
            if(i+k<s.size()){
                cur=s.substr(i,s.size()-i);
                ans+=myReverse(cur,0,k-1);
                continue;
            }
            cur=s.substr(i,s.size()-i);
            ans+=myReverse(cur,0,cur.size()-1);
        }

        return ans;
    }

    string myReverse(string s,int st,int ed){
        string res;
        for(int i=ed;i>=st;--i){
            res+=s[i];
        }
        res=s.substr(0,st)+res+s.substr(ed+1,s.size()-1);
        return res;
    }

};