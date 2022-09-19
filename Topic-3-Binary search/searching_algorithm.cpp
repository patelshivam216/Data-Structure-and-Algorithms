#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={2,4,6,8,9,12,14,16};
    int n=8;

    int x=14;

    int start = 0;
    int end= n-1;

    while(start<end){
        int mid=(start+end)/2;

        if(a[mid]==x){
            cout<<mid;
            break;
        }else if(x<a[mid]){
            end=mid-1;
        }else if(x>a[mid]){
            start=mid+1;
        }

    }

    return 0;

}