/*4. 寻找两个正序数组的中位数
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。



示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
class Solution {
public:*/
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>nums;
		float mid;
        int i=0,j=0;
        while(i<nums1.size()||j<nums2.size()){
            if(i<nums1.size()&&j<nums2.size()){
                if(nums1[i]<nums2[j]){
                    nums.push_back(nums1[i]);
                    i++;
                }
                else{
                    nums.push_back(nums2[j]);
                    j++;
                }
            }
            else{
                if(i<nums1.size()){
                    nums.push_back(nums1[i]);
                    i++;
                }
                if(j<nums2.size()){
                    nums.push_back(nums2[j]);
                    j++;
                }
            }
        }

		int m = nums.size();
		if (m % 2 == 0) {
			int idx1 = m / 2 - 1;
			int idx2 = m / 2 ;
			mid = (nums[idx1] + nums[idx2]) / 2.0;
		}
		else {
			int idx = m / 2;
			mid = nums[idx];
		}
		return mid;
	}
};