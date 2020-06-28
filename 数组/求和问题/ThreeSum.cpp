// 三数之和

// 双指针
/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        int n=nums.size();
        for(int i=0;i<nums.size();++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target=-nums[i];
            int k=n-1;
            for(int j=i+1;j<nums.size();++j){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                while(j<k && nums[k]+nums[j]>target){
                    --k;
                }
                if(j==k) break;
                if(nums[k]+nums[j]==target){
                    answer.push_back({nums[i],nums[j],nums[k]});
                }

            }  
        }
        return answer;

    }
};