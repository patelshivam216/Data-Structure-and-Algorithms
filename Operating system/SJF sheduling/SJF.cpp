#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<vector<int>>

class job{
public:
	int arr;
	int brust;
	int id;
	job(int a,int bt,int id){
		this->id = id;
		brust = bt;
		arr=a;
	}
};
class cmp1{
public:
	bool operator()(job a,job b){
		return a.arr > b.arr;
	}
};
class cmp2{
public:
	bool operator()(job a,job b){
		return a.brust > b.brust;
	}
};


vi fun(vi arr , vi brust){
	
	vi ans;
	int n = arr.size();
	priority_queue<job,vector<job>,cmp1> store;

	for(int i=0;i<n;i++){
		job temp = job(arr[i],brust[i],i+1);
		store.push(temp);
	}

	priority_queue<job,vector<job>,cmp2> readyQueue;

	int TimeLimit = 0;
	for(auto v : brust) TimeLimit = max(TimeLimit,v);


	int Time = 0;
	while(Time <= TimeLimit ){

		while(store.top().arr <= Time){
			job temp = store.top();
			store.pop(); 
			readyQueue.push(temp);
		}

		if(readyQueue.size()>0){
			job temp = readyQueue.top();
			readyQueue.pop();
			ans.push_back(temp.id);
			Time += temp.brust;
		}else
			Time+=1;
	}
    
    while(store.size()>0){
        readyQueue.push(store.top());
        store.pop();
    }

	while(readyQueue.size()>0){
		ans.push_back(readyQueue.top().id);
		readyQueue.pop();
	}


	return ans;
}
int main(){

	int n;
	cin>>n;
	vi arr(n);
	vi brust(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) cin>>brust[i];

	vi ans = fun(arr,brust);
	for(auto v : ans) cout<<v<<endl;

	return 0;
}

/*

Number of process or jobs 
second line is arriving time
last is brust time 

4
2 0 4 5
3 4 2 4

*/