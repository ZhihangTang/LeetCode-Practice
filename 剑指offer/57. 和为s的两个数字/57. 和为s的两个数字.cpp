class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while((nums[i]+nums[j])!=target){
            if((nums[i]+nums[j])>target){
                j--;
            }
            else i++;
        }
        return {nums[i],nums[j]};
    }
};