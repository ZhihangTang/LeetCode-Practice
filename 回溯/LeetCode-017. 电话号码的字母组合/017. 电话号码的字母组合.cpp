class Solution {
public:
	vector<string> res;
	unordered_map<char, string> phone{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};  
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(digits == "") return res;
        backtrace(digits, "", n,0);
        return res;
    }
    
    void backtrace( string &digits, string track, int n,int k){
        if(track.size() == n){
            res.push_back(track);
            return;
        }
        string tmp = phone[digits[k]];
        for(char w : tmp){
            track += w;
            backtrace(digits,track,n, k+1);
            track.pop_back();
        }
        return ;
    }
};