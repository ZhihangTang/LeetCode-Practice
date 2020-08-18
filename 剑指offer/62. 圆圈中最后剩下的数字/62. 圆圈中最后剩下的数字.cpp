
class Solution{
public:
	int lastRemaining(int n,int m){
		int res=0;
		for(int i=2;i<n+1;++i){
			res=(res+m)%i;
		}
		return res;
	}
};


//超时方法

class Solution{
public:
	int lastRemaining(int n,int m){
		if(n<1||m<1)
			return -1;
		int i=0;
		list<int>numbers;
		for(int i=0;i<n;++i){
			numbers.push_back(i);
		}
		list<int>::iterator current=numbers.begin();
		while(numbers.size()>1){
			for(int i=0;i<m;++i){
				current++;
				if(current==numbers.end()){
					current=numbers.begin();
				}
			}
			list<int>::iterator next=++current;
			if(next==numbers.end())
				next=numbers.begin();

			--current;
			numbers.erase(current);
			current=next;
		}
		return *(current);
	}
};41                    n 