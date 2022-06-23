#include<bits/stdc++.h>
using namespace std;
void delete_middleelement(stack<int> &s,int k){

    if(k==0){

        s.pop();
        return;
    }

    int temp=s.top();
    s.pop();

    delete_middleelement(s,k-1);

    s.push(temp);


}
int main(){

    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        s.push(val);
    }
    if(s.size()%2==0){
        n=n/2;
    }else{
        n=(n+1)/2;
    }
    delete_middleelement(s,n-1);

    while(s.size()>0){

        cout<<s.top();
        s.pop();

    }
    return 0;
}