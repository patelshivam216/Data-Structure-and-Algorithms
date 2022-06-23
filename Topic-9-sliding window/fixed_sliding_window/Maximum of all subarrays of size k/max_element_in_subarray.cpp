#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    deque<int> q;
    vector<int>  ans;
    int i=0;
    int j=0;

    while(i<n){
        // calculation

        if(q.size()==0){
            q.push_back(a[i]);
        }
        else if(q.back() < a[i]){

            while(q.back()<a[i])
                q.pop_back();

            q.push_back(a[i]);

        }else if(q.back()>a[i]){
            q.push_back(a[i]);
        }

        if(i-j+1<k){
            i++;
        }
        else if(i-j+1==k){
            //ans calculation
            ans.push_back(q.front());

            

            //slide the window

            if(a[j]==q.front()){
                q.pop_front();
            }
            i++;
            j++;
        }
    }

    for(auto v : ans){
        cout<<v<<" ";
    }


    return 0;
}