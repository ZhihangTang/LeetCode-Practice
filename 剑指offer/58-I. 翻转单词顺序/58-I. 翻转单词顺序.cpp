class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string c;
        stack<string > str;
        while(getline(ss,c,' ')){
            if(c!="") str.push(c);
        }
        string res;
        while(!str.empty()){    
            res+=(str.top()+' ');
            str.pop();
        }
        res.pop_back();
        return res;
    }
};