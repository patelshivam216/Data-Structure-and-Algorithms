#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
void recoverFromInsertion(vi &arr,int curId,int parentId){

    if(parentId == 1){
        if(arr[parentId]<arr[curId]){
            swap(arr[parentId],arr[curId]);
        }

        return;
    }

    if(arr[parentId]>=arr[curId]){
        return;
    }else{
        swap(arr[parentId],arr[curId]);
        recoverFromInsertion(arr,parentId,(parentId/2));
    }
}

void recoverFromDeletion(vi &arr,int curId,int l,int r){
    if(l<arr.size() and r<arr.size()){
        if(arr[curId]>arr[l] and arr[curId]>arr[r]) return;

        if(arr[l] > arr[r]){
            swap(arr[curId] , arr[l]);
            recoverFromDeletion(arr,l,l*2,(l*2)+1);
        }else{
            swap(arr[curId],arr[r]);
            recoverFromDeletion(arr,r,r*2,(r*2)+1);
            
        }
    }else if( l < arr.size() and r >= arr.size()){
        if(arr[curId]<arr[l]){
            swap(arr[curId],arr[l]);
            return;
        }
    }

    return;
}

vi insert(vi arr,int value){
    arr.push_back(value);
    recoverFromInsertion(arr,arr.size()-1,(arr.size()-1)/2);

    return arr;
}

vi deleteRoot(vi arr){
    if(arr.size() == 0 || arr.size() == 1) return {};
    if(arr.size() == 2) return {arr[1]};

    swap(arr[1],arr[arr.size()-1]);
    arr.erase(arr.begin()+arr.size()-1);
    recoverFromDeletion(arr,1,2,3);

    return arr;

}

int main(){
    int n;
    cin>>n;
    vi arr(n+1,-1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int value;
    cin>>value;
    vi ans1 = insert(arr,value);
    for(auto v : ans1) cout<<v<<" ";
    
    cout<<endl;


    vi ans2 = deleteRoot(arr);
    for(auto v : ans2) cout<<v<<" ";


    return 0;


}

/*

9
70 50 40 45 35 39 16 10 9
60

*/