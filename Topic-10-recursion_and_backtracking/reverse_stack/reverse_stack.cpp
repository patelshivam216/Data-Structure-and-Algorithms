#include<bits/stdc++.h>
using namespace std;
void insert_ele(stack<int> &s,int ele){

    if(s.size()==0){
        s.push(ele);
        return ;
    }
    int temp=s.top();
    s.pop();
    insert_ele(s,ele);
    s.push(temp);

}
void reverse_stack(stack<int> &s ){

    if(s.size()==1){
        return ;
    }

    int temp=s.top();
    s.pop();
    reverse_stack(s);
    insert_ele(s,temp);

    return ;

}
int main(){
    int n;
    cin>>n;
    stack<int> s;

    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        s.push(val);
    }

    reverse_stack(s);

    while(s.size()>0){
        cout<<s.top();
        s.pop();
    }

    return 0;
}