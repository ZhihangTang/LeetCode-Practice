class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(double num) {
    	if(((Min.size()+Max.size())&1)==0){
    		if(Min.size()>0&&num<Max[0]){
	    		Max.push_back(num);
	    		push_heap(Max.begin(),Max.end(),less<int>());
	    		num=Max[0];
	    		pop_heap(Max.begin(),Max.end(),less<int>());
	    		Max.pop_back();
    		}
    		Min.push_back(num);
    		push_heap(Min.begin(),Min.end(),greater<int>());
    	}
    	else{
    		if(Min.size()>0 && Min[0]<num);{
    			Min.push_back(num);
    			push_heap(Min.begin(),Min.end(),greater<int>());
    			num=Min[0];
    			pop_heap(Min.begin(),Min.end(),greater<int>());
    			Min.pop_back();
    		}
    		Max.push_back(num);
    		push_heap(Max.begin(),Max.end(),less<int>());

    	}
    	
    }
    
    double findMedian() {
    	int n=Min.size()+Max.size();
    	if(n%2==1){
    		return Min[0];
    	}
    	else{
    		return (Min[0]+Max[0])/2;
    	}

    }
private:
	vector<double> Min;
	vector<double> Max;

};
