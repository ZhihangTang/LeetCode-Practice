
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
    	int n=a.size();
        if(n==0) return{};
    	vector<int> b(n,1),c(n,1),d(n,1);
    	//b保存结果=a[0]*a[1]*...*a[i-2]*a[i-1] * a[i+1]*a[i+2]*...*a[n-2]*a[n-1]
    	
    	for(int i=1;i<n;++i){
    		c[i]=c[i-1]*a[i-1];
    		d[n-i-1]=d[n-i]*a[n-i];
    	}
    	for(int i=0;i<n;++i){
    		b[i]=c[i]*d[i];
    	}
    	return b;
    }
};


//思路二
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len=a.size();
        vector<int> res(len,1);
        int left=1,right=1;
        for(int i=0;i<len;++i){
            res[i]*=left;
            left*=a[i];
        }
        for(int j=len-1;j>=0;--j){
            res[j]*=right;
            right*=a[j];
        }
        return res;
    }
};