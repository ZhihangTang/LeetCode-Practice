class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxV=INT_MIN;
        if (nums.size()==0|| k==1) return nums;
        vector<int> ans;
        for(int i=0;i<=nums.size()-k;++i){
            int maxV=INT_MIN;
            for(int j=0;j<k;++j){
                if(nums[i+j]>maxV)maxV=nums[i+j];
            }
            ans.push_back(maxV);
        }
       return ans;
       
        return ans;
    }
};

// 优化版本
思路：首先遍历前k个取得第一个最大值，然后从第k个元素开始，
当移出去的元素小于最大值且移入的元素小于等于最大值的时候，最大值不变
否则重新从i-k+1遍历到i寻找最大值，
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==0) return {};
        int cur_max=INT_MIN;
        for(int i=0;i<k;++i){
            cur_max=max(cur_max,nums[i]);
        }
        vector<int> res={cur_max};
        for(int i=k;i<nums.size();++i){
           if(nums[i]<=cur_max&&nums[i-k]<cur_max){
               res.push_back(cur_max);
               continue;
           }
           else{
               cur_max=INT_MIN;
               for(int j=i-k+1;j<=i;++j){
                   cur_max=max(cur_max,nums[j]);
               }
               res.push_back(cur_max);
           }
        }
        return res;
    }
};