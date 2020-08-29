class Solution {
public:
    int findNthDigit(int n) {
        int digit=1;//n所在的数字的位数
        long start=1;//数字范围开始的第一个数
        long count=9; //占多少位
        while(n>count){
            n-=count;
            digit++;
            start*=10;
            count=digit*start*9;
        }
        long num=start+(n-1)/digit;
        return to_string(num)[(n-1)%digit]-'0';
    }
};