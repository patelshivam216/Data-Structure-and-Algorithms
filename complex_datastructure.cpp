
class temp{
public:
	int data1;
	int data2;
	temp(int d1,int d2){
		data1=d1;
		data2=d2;
	}
	temp(){
		// empty on purpose 
	}
};

class cmp{
public:
	bool operator()(temp a , temp b){
		return a.data1 > b.data1;
	}
};

int main(){

	priority_queue<temp,vector<temp>,cmp> maxH;
	
	maxH.push(temp(1,1));
	maxH.push(temp(2,1));

	while(maxH.size()>0) {
		auto p = maxH.top();
		maxH.pop();
		cout<<p.data1<<"-"<<p.data2<<endl;
	}

	return 0;
}