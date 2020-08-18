
class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int> nums,int k){
        vector<vector<int>> res;
        vector<int> track;
        sort(nums.begin(),nums.end());
        backtrace(nums,k,0,track,res);
        return res;
    }

    void backtrace(vector<int> &nums,int target,int idx,vector<int> &track,vector<vector<int>>& res){
        if(target<0){
            return;
        }
        if(target==0&&find(res.begin(),res.end(),track)==res.end()){
            res.push_back(track);
        }
        for(int i=idx;i<nums.size();++i){
            if(i>idx&&nums[i]==nums[i-1]){
                continue;
            }
            track.push_back(nums[i]);
            backtrace(nums,target-nums[i],i+1,track,res);
            track.pop_back();
        }
    }
}
;
