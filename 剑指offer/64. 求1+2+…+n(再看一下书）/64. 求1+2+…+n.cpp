int num = 0;
int sum = 0;

class A {
public:
    A(){ sum = sum + ++num; }
};

class Solution {
public:
    int sumNums(int n) {
        num = sum = 0;
        A a[n];
        return sum;
    }
};


