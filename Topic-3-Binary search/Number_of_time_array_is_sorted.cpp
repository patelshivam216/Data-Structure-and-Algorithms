#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={11,12,13,2,5,6,7};
    int n=7;

    int start=0;
    int end=n-1;

    while(start<end){
        int mid=(start+end)/2;

        int next=(mid+1)%n;
        int pre=(mid-1+n)%n;

        if(a[mid]<= a[next] and a[mid]<= a[pre]){
            cout<<mid+1;
            break;
        }else if (a[start]<= a[mid]){
            start=mid+1;
        }else if(a[mid]<= a[end]){
            end=mid-1;
        }
    }
    return 0;
}