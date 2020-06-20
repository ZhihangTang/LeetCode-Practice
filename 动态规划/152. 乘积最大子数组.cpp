# 152. 乘积最大子数组
#
# 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
#
#  
#
# 示例 1:
#
# 输入: [2,3,-2,4]
# 输出: 6
# 解释: 子数组 [2,3] 有最大乘积 6。
# 示例 2:
#
# 输入: [-2,0,-1]
# 输出: 0
# 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
#
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int cur_max=1,cur_min=1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<0){
                int tmp=cur_max;
                cur_max=cur_min;
                cur_min=tmp;
            }
            cur_max=max(cur_max*nums[i],nums[i]);
            cur_min=min(cur_min*nums[i],nums[i]);
            res=max(res,cur_max);
        }
        return res;

    }
};