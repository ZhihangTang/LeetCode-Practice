暴力解法：
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int m = s.size();
		if (m == 0) return 0;
		int maxl = 0;
		int left = 0, right = 0, count = 0;
		for (int i = 0; i < m; ++i) {
			count = 0;
			for (int j = i; j < m; j++) {
				if (i == j) {
					count++;
					continue;
				}
				string tmp = s.substr(i, j - i);
				if (s.substr(i, j - i).find(s[j]) == s.npos) {
					count++;
				}
				else {
					break;
				}
			}
			if (count > maxl) maxl = count;
		}
		return maxl;
	}
};

abcacb
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int> mp;
        int max_Length=0;
        int cur_Length=0;
        int start_idx=0;
        for(int i=0;i<s.size();++i){
            if(mp.find(s[i])==mp.end()){
                cur_Length++;
                mp[s[i]]=i;
            }
            else{
                max_Length=max(max_Length,cur_Length);
                start_idx=max(mp[s[i]],start_idx);
                cur_Length=i-start_idx;
                mp[s[i]]=i;
            }
            max_Length=max(cur_Length,max_Length);

        }
        return max_Length;
    }
};