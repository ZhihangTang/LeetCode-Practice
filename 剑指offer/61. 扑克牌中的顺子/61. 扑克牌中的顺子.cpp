class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int cnt=0,minnum=9999,maxnum=0;
        map<int,int> m;
        for(auto n:nums){
            if(n==0)cnt++;
            else{
                minnum=min(n,minnum);
                maxnum=max(n,maxnum);
                if(m.find(n)==m.end()) m[n]=1;
                else return false;
            }
        }
        if(cnt==0) return maxnum-minnum==4;
        else return maxnum-minnum<=4;
    }
};