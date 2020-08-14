class Solution {
public:
    int add(int a, int b) {
    	int res=0;
    	int xor=a^b;
    	res=(unsigned int)(a&b)<<1;
    	return res==0?xor:add(xor,res)

    }
};


class Solution {
public:
    int add(int a, int b) {
    	while(b!=0){
         //进位，注意：C++不支持负值左移！！这里要加上unsigned int
    		int c=(unsigned int)(a & b)<<1;
    		a^=b;
    		b=c;
    	}
    	return a;

    }
};