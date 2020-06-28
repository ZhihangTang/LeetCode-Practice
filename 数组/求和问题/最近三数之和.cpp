// 16. 最接近的三数之和
// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

// 示例：

// 输入：nums = [-1,2,1,-4], target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。


// 思路：
// 双指针

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int closeSum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;++i){
            int j=i+1,k=n-1;
                while(j<k){
                    int tmp_sum=nums[i]+nums[j]+nums[k];
                    if(abs(tmp_sum-target)<abs(closeSum-target)){
                        closeSum=tmp_sum;
                    }
                    
                    if(tmp_sum>target){
                        k--;
                    }
                    else if(tmp_sum<target) j++;
                    else return target;
                    
                }
               
            }
        
        return closeSum;
    }
};