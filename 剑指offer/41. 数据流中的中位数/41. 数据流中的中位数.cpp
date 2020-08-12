3 8 4 5 9 1 7 6
     Min      Max
      6        5 
      7        4
      8        3
      9        1
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

//使用优先队列 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(double num) {
        if(((Min.size()+Max.size())&1)==0){
            if(Min.size()>0&&num<Max.top()){
                Max.push(num);
                num=Max.top();
                Max.pop();
            }
            Min.push(num);
        }
        else{
            if(Min.size()>0 && Min.top()<num);{
                Min.push(num);
                num=Min.top();
                Min.pop();
            }
            Max.push(num);
        }
        
    }
    
    double findMedian() {
        int n=Min.size()+Max.size();
        if(n%2==1){
            return Min.top();
        }
        else{
            return (Min.top()+Max.top())/2;
        }

    }
private:
    priority_queue<double,vector<double>,greater<double> > Min;
    priority_queue<double,vector<double>,less<double> > Max;
};