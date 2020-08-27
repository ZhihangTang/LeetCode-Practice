class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int max_length=0,cur_length=0,start_idx=0;
        for(int i=0;i<s.size();++i){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                cur_length++;
            }
            else{
                max_length=max(max_length,cur_length);
                start_idx=max(mp[s[i]],start_idx);
                cur_length=i-start_idx;
                mp[s[i]]=i;
            }
            max_length=max(cur_length,max_length);
        }
        return max_length;
    }
};


// 滑动窗口，用set维护一个不重复的窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        set<char> myset;
        for(int i=0,j=0;j<s.size();++j){
            char c=s[j];
            while(myset.find(c) != myset.end()){
                myset.erase(myset.find(s[i]));
                i++;

            }
            myset.insert(c);
            res=max(res,j-i+1);
        }
        return res;
    }
};

#include<set>       //set 的头文件 

    set<int> s;        //声明一个int型set变量,名为s　

    s.empty()       //判定 s 是否为空 

　　s.insert(1);       //把数字1插入到s中 

　　s.clear();        //清空s 

　　s.erase(1);        //假若s存在1，则删除1 

　　s.begin();        //返回s中第一个元素地址  所以 *s.begin() 

　　s.end();        //返回s中最后一个元素地址  
                    //这个特殊一点，返回的是s中最后一个元素的下一个元素 
                    //所以  *(--s.end())是s最后一个元素 

　　s.rbegin();        //rbegin可以看做逆向的第一个地址   相当于(--s.end())  此处取的已经是s最后一个元素 

　　s.rend();        //rend可以看做逆向的最后一个地址  相当于 s.begin() 

　　s.count(1);        //计算s中1出现的次数，而次数只存在0与1，所以可以借来查找是否存在1 

　　s.size();        //返回s中元素的个数 

　　s.max_size();    //s最大能存元素的数目 

　　s.find(2);        //查找2 

　　set<int>::iterator iter;    //迭代器