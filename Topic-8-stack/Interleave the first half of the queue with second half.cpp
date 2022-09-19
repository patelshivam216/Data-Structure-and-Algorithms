#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

queue<int> solve(queue<int> q){
    int n = q.size();
    queue<int> q1;
    queue<int> q2;

    while(q.size()>(n/2)){
        q1.push(q.front());
        q.pop();
    }
    while(q.size()>0){
        q2.push(q.front());
        q.pop();
    }

    while(q1.size()>0 and q2.size()>0){
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }

    
    return q;


}
int main(){

    int n;
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        q.push(v);
    }

    queue<int> ans = solve(q);
    while(ans.size()>0){
        cout<<ans.front()<<" ";
        ans.pop();
    }

    return 0;
}

/*
10
11 
12 
13
14
15
16
17
18
19
20
*/